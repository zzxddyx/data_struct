#ifndef _FIFO_H_
#define _FIFO_H_

#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

using namespace std;

#define BUF_SIZE        PIPE_BUF
#define MSG_LEN         64
#define CLIENT_FIFO_NAME_LEN    64
#define SERVER_FIFO     "fifo.server"
#define CLIENT_FIFO     "fifo.client%d"
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

typedef struct fifo_msg
{
    pid_t client_pid;
    char msg[MSG_LEN];
}IPC_DATA;

void my_print(const char *str)
{
    cout << str << endl;
    return;
}

bool check_exist(const char *path_name)
{
    int access(const char *pathname, int mode);
    if (access(path_name, F_OK) == 0)
        return true;
    else
        return false;
}

#endif //_FIFO_H_
