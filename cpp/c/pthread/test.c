#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int run = 1;
static int retvalue;

void *start_router(void *args)
{
    int *running = args;
    printf("son pthread init ok, trans arg is : %d\n", running);
    while(*running)
    {
        printf("son pthread is running\n");
        usleep(1);
    }
    printf("son pthread is exit\n");

    retvalue = 8;
    pthread_exit( (void*)&retvalue);
}

int main(void)
{
    pthread_t pt;
    int ret = -1;
    int times = 3;
    int i = 0;
    int *ret_join = NULL;

    ret = pthread_create(&pt, NULL, (void*)start_router, &run);
    if (ret != 0)
    {
        printf("pthread create failed\n");
        return 1;
    }
    usleep(1);

    for(; i < times; i++)
    {
        printf("father pthread is running\n");
        usleep(1);
    }
    
    run = 0;
    pthread_join(pt, (void*)&ret_join);
    printf("pthread return value is %d\n", *ret_join);

    return 0;
}
