#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

typedef struct
{
    int v;
    int distancia;

}Vertice;

typedef struct
{
    Vertice *heap;
    int tamanho;
    int capacidade;
}MinHeap;

MinHeap *cria_heap(int capacidade);
void troca(Vertice *a, Vertice *b);
void sobe(MinHeap *h, int i);
void desce(MinHeap *h, int i);
void push(MinHeap *h, int v, int distancia);
Vertice pop(MinHeap *h);
int empty(MinHeap *h);

#endif // MINHEAP_H_INCLUDED
