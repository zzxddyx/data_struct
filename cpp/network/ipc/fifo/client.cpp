#include<iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void my_error(const char *str)
{
    cout << str << endl;
    return;
}

int main(void)
{
    /*
    if(mkfifo("./fifo", S_IRUSR | S_IWUSR | S_IWGRP) < 0)
        my_error("mkfifo error");
        */

    int fd = open("./fifo", O_WRONLY);
    if (fd < 0)
        my_error("open fifo error");

    char str[] = "Hello, My First Fifo Code";
    int len = strlen(str);

    if(write(fd, str, len) != len)
        my_error("write fifo error");

    return 0;
}

