#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>

using namespace std;

#define     SEM_KEY     (0x8888)
#define     SEM_MODE    (S_IRUSR | S_IWUSR | S_IRGRP | S_IRGRP)

int comm = 0;

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

bool init_sem(int sem_id)
{
    union semun union_sem;
    union_sem.val = 1;
    if(semctl(sem_id, 0, SETVAL, union_sem) < 0)
    {
        cout << "semctl IPC_SET error" << endl;
        return false;
    }

    return true;
}

bool del_sem(int sem_id)
{
    union semun union_sem;
    if(semctl(sem_id, 0, IPC_RMID, union_sem) < 0)
        cout << "del_sem IPC_RMID error" << endl;
}

/*
* unsigned short sem_num;
* short          sem_op; 
* short          sem_flg
*/
bool sem_p(int sem_id)
{
    struct sembuf sops;
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sops, 1) < 0)
    {
        cout << "semop -1 error" << endl;
        return false;
    }
    return true;
}

bool sem_v(int sem_id)
{
    struct sembuf sops;
    sops.sem_num = 0;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sops, 1) < 0)
    {
        cout << "semop +1 error" << endl;
        return false;
    }
    return true;
}
/*
 * semget
 * semctl
 * semop
 */

#endif //_COMMON_H
