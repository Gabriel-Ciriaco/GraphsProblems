#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QueueNode * criarNoQueue(int vertice)
{
    QueueNode * novoNoQueue = (QueueNode*) malloc(sizeof(QueueNode));

    if (!novoNoQueue)
    {
        return NULL;
    }

    novoNoQueue->vertice = vertice;

    novoNoQueue->next = NULL;

    return novoNoQueue;
}

Queue criarQueue()
{
    Queue novoQueue;

    novoQueue.top = NULL;
    novoQueue.bottom = NULL;

    return novoQueue;
}

void pushQueue(Queue * q, int vertice)
{
    if (!q) return;

    QueueNode * novoNo = criarNoQueue(vertice);

    if (!novoNo)
    {
        perror("\n[PUSH-QUEUE]: Houve um erro interno ao inserir o valor desejado.\n");
        return;
    }

    if (!q->bottom)
    {
        q->top = novoNo;
        q->bottom = novoNo;

        return;
    }

    q->bottom->next = novoNo;

    q->bottom = novoNo;
}

int popQueue(Queue * q)
{
    if (!q || !q->top)
    {
        return -1;
    }

    QueueNode * popElement = q->top;

    int popValue = popElement->vertice;

    q->top = q->top->next;

    if (!q->top)
        q->bottom = NULL;

    free(popElement);

    return popValue;
}

void destroiQueue(Queue * q)
{
    if (!q) return;

    while (q->top)
    {
        popQueue(q);
    }
}
