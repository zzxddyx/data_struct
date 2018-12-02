#include <iostream>
#include <cstdio>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

using namespace std;
const int MAX_SIZE = 1024;

void my_error(const char *str)
{
    cout << str << endl;
    exit(1);
}

int main(void)
{
    if(mkfifo("./fifo", S_IRUSR | S_IWUSR | S_IWGRP) < 0 && errno != EEXIST)
    {
        my_error("mkfifo error");
    }

    int fd = open("./fifo", O_RDONLY);
    if (fd < 0)
        my_error("open fifo error");

    char buf[MAX_SIZE] = "";
    while(1)
    {
        int n = read(fd, buf, MAX_SIZE);
        if (n < 0)
            my_error("read error");
        if (n > 0)
            cout << buf << endl;
        if ( n == 0)
            break;
    }

    close(fd);
    unlink("./fifo");

    return 0;
}
