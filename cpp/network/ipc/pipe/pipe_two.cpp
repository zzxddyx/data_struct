#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <signal.h>
#include <unistd.h>

#define MAX_SIZE 1024

using namespace std;

/*
 * fileno(stdin) = STDIN_FILENO = 0
 * fileno(stdout) = STDOUT_FILENO = 1
 * fileno(stderr) = STDERR_FILENO = 2
 */

static void sig_pipe(int)
{
    cout << "caught SIGPIPE" << endl;
    exit(-1);
}

void my_quit(const char *str)
{
    cout << str << endl;
    exit(-1);
}

int main(void)
{
    if(signal(SIGPIPE, sig_pipe) == SIG_ERR)
        my_quit("signal error");

    int fd1[2], fd2[2]; // 0读 1写
    if (pipe(fd1) < 0 || pipe(fd2) < 0)
        my_quit("create pipe error");

    pid_t pid = fork();
    char buf[MAX_SIZE] = "";
    if (pid < 0)
        my_quit("fork error");
    else if (pid > 0) // server parent
    {
        close(fd1[0]); // 关闭fd1的读
        close(fd2[1]); // 关闭fd2的写

        while(fgets(buf, MAX_SIZE, stdin) != NULL)
        {
            int len = strlen(buf);
            if (write(fd1[1], buf, len) != len)
                my_quit("parent write error");
            if ((len = read(fd2[0], buf, MAX_SIZE)) < 0)
                my_quit("parent read error");
            if (len == 0)
            {
                cout << "parent not read data" << endl;
                break;
            }

            buf[len] = '\0';
            if(fputs(buf, stdout) == EOF)
                my_quit("parent read error");

        }
        if(ferror(stdin))
            my_quit("parent stdin error");

        exit(1);
    }
    else  // child client
    {
        close(fd1[1]); // 关闭fd1写
        close(fd2[0]); // 关闭fd2读

        if (fd1[0] != STDIN_FILENO)
        {
            if(dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO)
                my_quit("child dup2 fd1 rror");
            close(fd1[0]);
        }

        if (fd2[1] != STDOUT_FILENO)
        {
            if(dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO)
                my_quit("child dup2 fd2 error");
            close(fd2[1]);
        }

        if(execl("./add", "add", NULL) < 0)
            my_quit("execl error");
    }

    return 0;
}
