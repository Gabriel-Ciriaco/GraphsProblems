#include "minHeap.h"

#include<stdlib.h>

MinHeap *cria_heap(int capacidade)
{
    MinHeap *h = (MinHeap*)malloc(sizeof(MinHeap));
    if(h == NULL)
    {
        return NULL;
    }

    h->heap = malloc(capacidade * sizeof(Vertice));
    if(h->heap == NULL)
    {
        printf("\nErro ao alocar memória!\n");
        exit(1);
    }

    h->tamanho = 0;
    h->capacidade = capacidade;

    return h;
}

void troca(Vertice *a, Vertice *b)
{
    Vertice *temp = b;
    b = a;
    a = temp;
}

void sobe(MinHeap *h, int i)
{
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (h->heap[p].distancia <= h->heap[i].distancia)
        {
            break;
        }
        troca(&h->heap[p], &h->heap[i]);
        i = p;
    }
}


void desce(MinHeap *h, int i)
{
    while (1)
    {
        int e = 2*i + 1;
        int d = 2*i + 2;
        int menor = i;

        if (e < h->tamanho && h->heap[e].distancia < h->heap[menor].distancia)
        {
            menor = e;
        }
        if (d < h->tamanho && h->heap[d].distancia < h->heap[menor].distancia)
        {
            menor = d;
        }
        if (menor == i)
        {
            break;
        }
        troca(&h->heap[i], &h->heap[menor]);
        i = menor;
    }
}


void push(MinHeap *h, int v, int distancia)
{
    if (h->tamanho == h->capacidade)
    {
        return;
    }
    h->heap[h->tamanho].v = v;
    h->heap[h->tamanho].distancia = distancia;
    sobe(h, h->tamanho);
    h->tamanho++;
}


Vertice pop(MinHeap *h)
{
    Vertice topo = h->heap[0];
    h->tamanho--;
    h->heap[0] = h->heap[h->tamanho];
    desce(h, 0);
    return topo;
}


int empty(MinHeap *h)
{
    return h->tamanho == 0;
}

