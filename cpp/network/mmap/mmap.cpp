#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

using namespace std;

#define SIZE 1024

int main(void)
{
    int fd;
    // open
    if ((fd = open("./data", O_RDWR)) < 0)
    {
        cout << "open file error" << endl;
        return - 1;
    }

    // 获取文件属性
    struct stat file_stat;
    if((fstat(fd, &file_stat)) < 0)
    {
        cout << "stat file error" << endl;
        return -1;
    }

    // mmap
    char *map_addr = (char *)mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map_addr == (void *) -1)
    {
        cout << "mmap error" << endl;
        return -1;
    }

    // close fd
    close(fd);
    cout << "mmap addr : " << endl << map_addr << endl;

    // 修改一个字符,并同步到文件中
    map_addr[8] = 'F';
    map_addr[80] = 'F';
    if((msync((void *)map_addr, file_stat.st_size, MS_SYNC)) < 0)
    {
        cout << "msync file error" << endl;
        return -1;
    }

    // 释放mmap
    if ((munmap((void *)map_addr, file_stat.st_size)) < 0)
    {
        cout << "munmap error" << endl;
        return -1;
    }

    return 0;
}
