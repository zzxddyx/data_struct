#include "./common.h"

int main(void)
{
    key_t key = ftok(SEM_PATH, SEM_KEY);
    if (key < 0)
    {
        perror("server ftok error");
        return -1;
    }

    int sem_id = semget(key, 1, 0644 | IPC_CREAT);
    if (sem_id < 0)
    {
        perror("server semget error");
        return -1;
    }

    union semun un_sem;
    un_sem.val = 1;
    if(semctl(sem_id, 0, SETVAL, un_sem) < 0)
    {
        perror("server semctl setval error");
        return -1;
    }

    key = ftok(SHM_PATH, SHM_KEY);
    int shm_id = shmget(key, SHM_LEN, 0644 | IPC_CREAT);
    if (shm_id < 0)
    {
        perror("server shmget error");
        return -2;
    }

    void *shm_data = shmat(shm_id, NULL, 0);
    if((void *) -1 == shm_data)
    {
        perror("server shmat error");
        return -2;
    }

    SHM_DATA *datas = (SHM_DATA *)shm_data;
    lock(sem_id);
    for (; ;)
    {
        if (datas && datas->pid > 0 && datas->buf != "")
        {
            cout << "recv data from pid shm is : " << datas->pid << " : " << datas->buf << endl;
            if (strncmp(datas->buf, "quit", 4) == 0)
            {
                if(shmdt(shm_data) < 0)
                {
                    perror("server shmdt error");
                }
                break;
            }
        }

        sleep(3);
    }
    if(shmdt(shm_data) < 0)
    {
        perror("server shmdt error");
    }
    unlock(sem_id);

    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);

    return 0;
}
