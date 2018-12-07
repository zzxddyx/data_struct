#include "./common.h"

int main(void)
{
    //sem
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

    //shm
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
    datas->pid = getpid();
    char buf[MAX_LEN] = "";
    if(fgets(buf, MAX_LEN, stdin) != NULL)
    {
        strcpy(datas->buf, buf);
    }
    unlock(sem_id);

    if(shmdt(shm_data) < 0)
    {
        perror("client shmdt error");
        return -1;
    }

    return 0;
}
