#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <fcntl.h>  
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

#define DEF_PAGER   "/bin/more"
#define MAX_SIZE    1024

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "main params error" << endl;
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        cout << "open file error" << endl;
        exit(1);
    }

    int pipe_fd[2];
    if (pipe(pipe_fd) < 0)
    {
        cout << "create pipe error" << endl;
        exit(1);
    }

    pid_t pid = fork();
    char buf[MAX_SIZE] = "";

    if (pid < 0)
    {
        cout << "fork proc error" << endl; 
        exit(1);
    }
    else if(pid > 0) // 0:读 1:写
    {
        close(pipe_fd[0]);

        while(fgets(buf, MAX_SIZE, fp) != NULL)
        {
            int n = strlen(buf);
            if (write(pipe_fd[1], buf, n) != n)
            {
                cout << "write buf error" << endl;
                exit(1);
            }
        }

        if (ferror(fp))
        {
            cout << "fgets erroe" << endl;
            exit(1);
        }
        close(pipe_fd[1]);

        if(waitpid(pid, NULL, 0) < 0)
        {
            cout << "waitpid error" << endl;
            exit(1);
        }
        exit(0);
    }
    else
    {
        close(pipe_fd[1]);
        if (pipe_fd[0] != STDIN_FILENO)
        {
            // dup2(oldfd, newfd)
            if (dup2(pipe_fd[0], STDIN_FILENO) != STDIN_FILENO)
            {
                cout << "dup2 error" << endl;
                exit(1);
            }
            close(pipe_fd[0]);
        }

        /*
        // 环境变量的分析
        char *pager = getenv("PAGER"); // getenv找环境变量
        if (pager == NULL)
            pager = DEF_PAGER;

        //char *strrchr(const char *str, int c) 在参数 str 所指向的字符串中搜索最后一次出现字符 c(一个无符号字符)的位置
        char *argv0 = strrchr(pager, '/');
        if (argv0 != NULL)
        {
            argv0++;
        }
        else
        {
            argv0 = pager;
        }

        if (execl(pager, argv0, NULL) < 0)
        {
            cout << "exec error" << endl;
            exit(1);
        }

        */
        if (execl("/bin/less", "less", NULL) < 0)
        {
            cout << "exec error" << endl;
            exit(1);
        }
    }

    return 0;
}
