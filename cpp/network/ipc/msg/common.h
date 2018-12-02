#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>    
#include <sys/stat.h>    


#define MAX_SIZE        (1024)
#define IPC_KEY         ((key_t)0x6666)
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

using namespace std;

typedef struct msg_data
{
    int type;
    pid_t pid;
    char data[MAX_SIZE];
}MSG_DATA;

void my_print(const char *str)
{
    cout << str << endl;
    return;
};

#endif //_COMMON_H_
