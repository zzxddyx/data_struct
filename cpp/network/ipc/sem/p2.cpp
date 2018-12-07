#include "./common.h"

int main(void)
{
    int sem_id = semget(SEM_KEY, 1, SEM_MODE | IPC_CREAT);
    cout << __FILE__ << " : " << sem_id << endl;
    if (sem_id < 0)
    {
        cout << "semget error" << endl;
        return -1;
    }

    if(!init_sem(sem_id))
    {
        cout << "init sem error" << endl;
        return -1;
    }

    for (int i = 10; i < 20; ++i)
    {
        sem_p(sem_id);
        comm += 1;
        cout << __FILE__ << " : comm is : " << comm << endl;
        sleep(1);
        sem_v(sem_id);
    }

    del_sem(sem_id);

    return 0;
}
