#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

static bool flag = true;

void create_daemonize()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        std::cout << "fork error" << std::endl;
        return;
    }
    else if(pid != 0)
        exit(0);

    if(setsid() < 0)
    {
        std::cout << "setsid error" << std::endl;
        return;
    }

    if(chdir("/") < 0)
    {
        std::cout << "chdir error" << std::endl;
        return;
    }

    umask(0);

    for(int i = 0; i < 3; ++i)
        close(i);
}

void signal_handler(int sig)
{
    std::cout << "recv signal : " << sig << std::endl;
    flag = false;
}

int main(void)
{
    time_t t;
    int fd;
    create_daemonize();
    struct sigaction act;
    act.sa_handler = signal_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if(sigaction(SIGQUIT, &act, NULL) < 0)
    {
        std::cout << "sigaction error" << std::endl;
        exit(0);
    }

    while(flag)
    {
        fd = open("/home/ezfun/data_struct/CPP/os/deamonize/daemonize.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if(fd < 0)
            std::cout << "open file error" << std::endl;

        t = time(0);
        char *buf = asctime(localtime(&t));
        write(fd, buf, strlen(buf));
        close(fd);
        sleep(60);
    }

    return 0;
}
