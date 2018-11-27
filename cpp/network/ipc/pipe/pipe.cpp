#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

#define MAX_SIZE 1024

int main(void)
{
    int my_pipe[2]; // 0:读 1:写
    if(pipe(my_pipe) < 0)
    {
        cout << "pipe failed" << endl;
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0)
    {
        cout << "fork failed" << endl;
        return -1;
    }
    else if(pid > 0)
    {
        close(my_pipe[0]);
        char str[] = "Hello C++\n";
        int len = strlen(str);
        write(my_pipe[1], str, len);
    }
    else
    {
        close(my_pipe[1]);
        char buf[MAX_SIZE] = "";
        int n = read(my_pipe[0], buf, MAX_SIZE);
        write(STDOUT_FILENO, buf, n);
    }

    return 0;
}
