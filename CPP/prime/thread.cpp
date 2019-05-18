#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* thread1(void* num)
{
    int *inum = (int*)num;
    std::cout << *inum << std::endl;

    return NULL;
}

void* thread2(void* num)
{
    double *dnum = (double*)num;
    std::cout << *dnum+100 << std::endl;
    return NULL;
}

int main(void)
{
    pthread_t pid1;
    pthread_t pid2;
    int arg1 = 10;
    int *parg1 = &arg1;
    if((pthread_create(&pid1, NULL, &thread1, (void*)parg1)) < 0)
    {
        std::cout << "create p1 error" << std::endl;
        return -1;
    }
    sleep(100);

    double arg2 = 10.10;
    double *parg2 = &arg2;
    if((pthread_create(&pid2, NULL, &thread2, (void*)parg2)) < 0)
    {
        std::cout << "create p2 error" << std::endl;
        return -1;
    }

    sleep(100);

    if(pthread_join(pid1, NULL))
    {
        std::cout << "join p1 error" << std::endl;
        return -1;
    }

    if (pthread_join(pid2, NULL))
    {
        std::cout << "join p2 error" << std::endl;
        return -1;
    }

    return 0;
}
