#include <iostream>
#include <unistd.h>
#include <cstdio>
using namespace std;

#define PAGER   "${PAGER:-more}"
#define MAX_SIZE 1024

/*
 * popen : 创建一个管道,fock进程,关闭未使用的管道端,调用exec执行
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "param error" << endl;
        return -2;
    }

    FILE *fpin = fopen(argv[1], "r");
    if (fpin == NULL)
    {
        cout << "file open error : " << argv[1] << endl;
        return -1;
    }
 
    // 第二个参数只能是r || w 
    FILE *fpout = popen("less", "w");
    if (fpout == NULL)
    {
        cout << "popen error" << endl;
        return -1;
    }

    char buf[MAX_SIZE] = "";
    while(fgets(buf, MAX_SIZE, fpin) != NULL)
    {
        if(fputs(buf, fpout) == EOF)
        {
            cout << "fputs data error" << endl;
            return -1;
        }
    }

    /*ferror : ferror返回0表示未出错;返回非0表示出错
     * 每调用一次输入输出函数将会产生一次error值,因此每次调用函数立即调用ferror检查
    */
    if(ferror(fpin))
    {
        cout << "ferror" << endl;
        return -1;
    }

    if(pclose(fpout) < 0)
    {
        cout << "pclose error" << endl;
        return -1;
    }

    return 0;
}

