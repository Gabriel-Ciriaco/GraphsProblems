#ifndef GRAPHS_H_INCLUDED
#define GRAPHS_H_INCLUDED

#include "adjacency_list/grafoLista.h"
#include "adjacency_matrix/grafoMatriz.h"

#define GRAPH_ERROR -1


typedef enum
{
    LISTA_ADJACENCIA=1,
    MATRIZ_ADJACENCIA
} tipoImplementacaoGrafo;

/*
    Aqui temos ponteiros de funções para facilitar
    o uso das operacoes de acordo com a implementação
    do grafo escolhida.

    insereAresta, por exemplo, é um ponteiro que
    permite armazenar qualquer função que retorna void
    e tem como parâmetros: (void *impl, int origem, int destino).
*/
typedef struct
{
    void (*destroi)(void *impl);

    void (*insereAresta)(void *impl, int origem, int destino, int peso);
    void (*removeAresta)(void *impl, int origem, int destino);

    bool (*existeAresta)(void *impl, int origem, int destino);

    void (*imprimeGrafo)(void *impl);
    void (*imprimeArestas)(void *impl);

    int (*calculaGrau)(void *impl, int vertice);
    int (*encontraMaisPopular)(void *impl);

    void (*buscaProfundidade)(void *impl, int vertice, int *visitados);
    void (*buscaLargura) (void *impl, int vertice, int *visitados);

    void (*encontraComponentes)(void *impl);

    int* (*dijkstra)(void *impl, int origem);

    void (*recomendacaoDireta)(void *impl, int vertice, int* recomendacoes);
    void (*recomendacaoAmigoDeAmigo)(void *impl, int vertice, int* recomendacoes);

    bool (*verificarCaminho)(void* impl, int origem, int destino);

    int* (*prim)(void* impl);

} OperacoesGrafos;

typedef struct _grafo
{
    int tipoImplGrafo; // Indica se o grafo é uma lista ou matriz.

    int numVertices;

    void* impl; // Implementação do gráfico (lista ou matriz).

    /*
        Nos permite um polimorfismo dinâmico com as operações
        de grafo. Por exemplo, se tivermos usando a implementação
        de lista de adjacência, ele usa as funções de lista.
    */
    OperacoesGrafos operacoes;
} Grafo;

Grafo* criaGrafo(int tipoImplGrafo, int vertices);

void destroiGrafo(Grafo *g);

void insereAresta(Grafo *g, int origem, int destino, int peso);

void removeAresta(Grafo *g, int origem, int destino);

bool existeAresta(Grafo *g, int origem, int destino);

void imprimeGrafo(Grafo *g);

void imprimeArestas(Grafo *g);

int calculaGrau(Grafo *g, int vertice);

int encontraMaisPopular(Grafo *g);

void buscaProfundidade(Grafo *g, int vertice, int *visitados);

void buscaLargura(Grafo *g, int vertice, int *visitados);

int* dijkstra(Grafo *g, int origem);

void recomendacaoDireta(Grafo *g, int vertice, int * recomendacoes);

void recomendacaoAmigoDeAmigo(Grafo *g, int vertice, int * recomendacoes);

void encontraComponentes(Grafo *g);

bool verificarCaminho(Grafo* g, int origem, int destino);

int* prim(Grafo *g);

#endif // GRAPHS_H_INCLUDED
