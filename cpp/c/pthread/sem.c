#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int running = 1;

void *product(void *args)
{
    int semval = 0;
    while(running)
    {
        usleep(1);
        sem_post(&sem);
        sem_getvalue(&sem, &semval);
        printf("product num:%d\n", semval);
    }
}

void *consume(void *args)
{
    int semval = 0;
    while(running)
    {
        usleep(1);
        sem_wait(&sem);
        sem_getvalue(&sem, &semval);
        printf("comsume num:%d\n",semval);
    }
}

int main(void)
{
    pthread_t prod_pt;
    pthread_t coms_pt;

    sem_init(&sem, 0, 10);

    pthread_create(&prod_pt, NULL, (void*)product, NULL);
    pthread_create(&coms_pt, NULL, (void*)consume, NULL);

    sleep(1);
    running = 0;
    pthread_join(prod_pt, NULL);
    pthread_join(coms_pt, NULL);
    sem_destroy(&sem);

    return 0;
}
