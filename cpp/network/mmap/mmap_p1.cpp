#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
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
        cout << "fstat file error" << endl;
        return -1;
    }

    // mmp
    char *mmap_addr = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_addr == (void *) -1)
    {
        cout << "mmanp error" << endl;
        return -1;
    }

    close(fd);

    // 每隔2s检查数据有没有被修改
    for(;;)
    {
        cout << "buff info is : " << endl << mmap_addr << endl;
        sleep(5);
    }

    return 0;
}

