#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

using namespace std;

#define MAX_LEN 4096
#define SHM_LEN 4096
#define SEM_PATH    "."
#define SEM_KEY     0x1234
#define SHM_PATH    "."
#define SHM_KEY     0x1234

/*
   unsigned short sem_num;   semaphore number 
   short          sem_op;    semaphore operation 
   short          sem_flg;   operation flags 
*/

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

typedef struct _shm_data
{
    pid_t pid;
    char buf[MAX_LEN];
}SHM_DATA;

void lock(int sem_id)
{
    struct sembuf sops;
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sops, 1) < 0)
    {
        perror("common semop lock error");
        return;
    }
}

void unlock(int sem_id)
{
    struct sembuf sops;
    sops.sem_num = 0;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sops, 1) < 0)
    {
        perror("common semop unlock error");
        return;
    }
}

/*
 * shmget
 * shmctl
 * shmat
 * shmdt
 */

#endif //_COMMON_H
