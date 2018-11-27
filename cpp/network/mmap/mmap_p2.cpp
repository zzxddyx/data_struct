#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(void)
{
    int fd = open("./data", O_RDWR);
    if (fd < 0)
    {
        cout << "open file error" << endl;
        return -1;
    }

    struct stat sb;
    if((fstat(fd, &sb)) < 0)
    {
        cout << "stat file error" << endl;
        return -1;
    }

    char *mmap_addr = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_addr == (void *)-1)
    {
        cout << "mmap error" << endl;
        return -1;
    }

    close(fd);

    mmap_addr[5] = 'A';

    return 0;
}
