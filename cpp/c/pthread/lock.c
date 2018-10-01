#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

int buffer_item = 0;
pthread_mutex_t mutex;
int running = 1;

void *prodect(void *args)
{
    while(running)
    {
        pthread_mutex_lock(&mutex);
        buffer_item++;
        printf("product num :%d\n", buffer_item);
        pthread_mutex_unlock(&mutex);
    }
}

void *consume(void *args)
{
    while(running)
    {
        pthread_mutex_lock(&mutex);
        buffer_item--;
        printf("consume num : %d\n", buffer_item);
        pthread_mutex_unlock(&mutex);
    }
}

int main(void)
{
    pthread_t prod_pt;
    pthread_t coms_pt;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod_pt, NULL, (void*)prodect, NULL);
    pthread_create(&coms_pt, NULL, (void*)consume, NULL);

    usleep(1);
    running = 0;

    pthread_join(prodect, NULL);
    pthread_join(consume, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}
