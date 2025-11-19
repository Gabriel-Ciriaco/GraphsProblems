#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef struct _queueNode
{
    int vertice;

    struct _queueNode * next;

} QueueNode;

typedef struct _queue
{
    QueueNode * top;
    QueueNode * bottom;
} Queue;


QueueNode * criarNoQueue(int vertice);

Queue criarQueue();

void pushQueue(Queue *q, int vertice);

int popQueue(Queue *q);

void destroiQueue();

#endif // QUEUE_H_INCLUDED
