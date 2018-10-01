#include<iostream>
#include "Queue.h"
using namespace std;

int main(void)
{
    Queue *queue = new Queue(1);
    cout << queue->isEmpty() << endl;
    queue->Enqueue(100);
    queue->Enqueue(100);
    int t = queue->GetTop();
    cout << t << endl;
    return 0;
}

