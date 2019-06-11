#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _Node
{
    int data;
    struct _Node *next;
}NODE;

typedef struct _Queue
{
    NODE *front;
    NODE *rear;
}QUEUE;

QUEUE *create();
QUEUE *enqueue(QUEUE *q, int data);
QUEUE *dequeue(QUEUE *q);
int getLength(QUEUE *q);
void print(QUEUE *q);

#endif //_QUEUE_H_
