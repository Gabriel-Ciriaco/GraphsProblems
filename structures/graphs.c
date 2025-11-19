#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>


/*
    Serve como um strategy de POO. Ele seleciona a função correta
    de acordo com o tipo de implementação.

    Aqui, temos um cast da assinatura das funções.

    Por exemplo, (void (*) (void*, int, int))

    - void: indica o retorno da função.

    - (*): indica que é o ponteiro para uma função.

    - (void*, int, int): os tipos dos parâmetros que a função aceita.
*/
OperacoesGrafos escolheOperacoes(int tipo)
{
    OperacoesGrafos operacoes;

    if (tipo == LISTA_ADJACENCIA)
    {
        operacoes.destroi = (void (*)(void*)) destroiGrafoLista;
        operacoes.insereAresta = (void (*)(void*,int,int)) insereArestaLista;
        operacoes.removeAresta = (void (*)(void*,int,int)) removeArestaLista;
        operacoes.existeAresta = (bool (*)(void*,int,int)) existeArestaLista;
        operacoes.imprimeGrafo = (void (*)(void*)) imprimeGrafoLista;
        operacoes.imprimeArestas = (void (*)(void*)) imprimeArestasLista;
        operacoes.calculaGrau = (int (*)(void*,int)) calculaGrauLista;
        operacoes.encontraMaisPopular = (int (*)(void*)) encontraMaisPopularLista;
        operacoes.buscaProfundidade = (void (*)(void*,int,int*)) buscaProfundidadeLista;
        operacoes.buscaLargura = (void (*) (void*,int,int*)) buscaLarguraLista;
        operacoes.encontraComponentes = (void (*)(void*)) encontraComponentesLista;
        operacoes.recomendacaoDireta = (void (*) (void*, int, int*)) recomendacaoDiretaLista;
        operacoes.recomendacaoAmigoDeAmigo = (void (*) (void*, int, int*)) recomendacaoAmigoDeAmigoLista;
        operacoes.verificarCaminho = (bool (*) (void*, int, int)) verificarCaminhoLista;
    }
    else if (MATRIZ_ADJACENCIA)
    {
        operacoes.destroi = (void (*)(void*)) destroiGrafoMatriz;
        operacoes.insereAresta = (void (*)(void*,int,int)) insereArestaMatriz;
        operacoes.removeAresta = (void (*)(void*,int,int)) removeArestaMatriz;
        operacoes.existeAresta = (bool (*)(void*,int,int)) existeArestaMatriz;
        operacoes.imprimeGrafo = (void (*)(void*)) imprimeGrafoMatriz;
        operacoes.imprimeArestas = (void (*)(void*)) imprimeArestasMatriz;
        operacoes.calculaGrau = (int (*)(void*,int)) calculaGrauMatriz;
        operacoes.encontraMaisPopular = (int (*)(void*)) encontraMaisPopularMatriz;
        operacoes.buscaProfundidade = (void (*)(void*,int,int*)) buscaProfundidadeMatriz;
        operacoes.buscaLargura = (void (*) (void*,int,int*)) buscaLarguraMatriz;
        operacoes.encontraComponentes = (void (*)(void*)) encontraComponentesMatriz;
        operacoes.recomendacaoDireta = (void (*) (void*, int, int*)) recomendacaoDiretaMatriz;
        operacoes.recomendacaoAmigoDeAmigo = (void (*) (void*, int, int*)) recomendacaoAmigoDeAmigoMatriz;
        operacoes.verificarCaminho = (bool (*) (void*, int, int)) verificarCaminhoMatriz;
    }

    return operacoes;
}


Grafo* criaGrafo(int tipoImplGrafo, int vertices)
{
    if (tipoImplGrafo != LISTA_ADJACENCIA &&
        tipoImplGrafo != MATRIZ_ADJACENCIA)
    {
        printf("\n[CRIA-GRAFO]: Favor selecionar um tipo válido. (LISTA_ADJACENCIA/MATRIZ_ADJACENCIA)\n");

        return NULL;
    }

    Grafo* novoGrafo = (Grafo*) malloc(sizeof(Grafo));

    novoGrafo->tipoImplGrafo = tipoImplGrafo;
    novoGrafo->numVertices = vertices;
    novoGrafo->operacoes = escolheOperacoes(tipoImplGrafo);


    if (tipoImplGrafo == LISTA_ADJACENCIA)
        novoGrafo->impl = criaGrafoLista(vertices);

    else if (tipoImplGrafo == MATRIZ_ADJACENCIA)
        novoGrafo->impl = criaGrafoMatriz(vertices);

    return novoGrafo;
}

void destroiGrafo(Grafo* g)
{
    if (!g) return;

    g->operacoes.destroi(g->impl);

    free(g);
}

void insereAresta(Grafo* g, int origem, int destino)
{
    if (!g) return;

    g->operacoes.insereAresta(g->impl, origem, destino);
}

void removeAresta(Grafo *g, int origem, int destino)
{
    if (!g) return;

    g->operacoes.removeAresta(g->impl, origem, destino);
}

bool existeAresta(Grafo *g, int origem, int destino)
{
    if (!g)
        return false;

    return g->operacoes.existeAresta(g->impl, origem, destino);
}

void imprimeGrafo(Grafo *g)
{
    if (!g) return;

    g->operacoes.imprimeGrafo(g->impl);
}

void imprimeArestas(Grafo *g)
{
    if (!g) return;

    g->operacoes.imprimeArestas(g->impl);
}

int calculaGrau(Grafo *g, int vertice)
{
    if (!g)
        return GRAPH_ERROR;

    return g->operacoes.calculaGrau(g->impl, vertice);
}

int encontraMaisPopular(Grafo *g)
{
    if (!g)
        return GRAPH_ERROR;

    return g->operacoes.encontraMaisPopular(g->impl);
}

void buscaProfundidade(Grafo *g, int vertice, int *visitados)
{
    if (!g) return;

    g->operacoes.buscaProfundidade(g->impl, vertice, visitados);
}

void buscaLargura(Grafo *g, int vertice, int * visitados)
{
    if (!g)
        return;

    g->operacoes.buscaLargura(g->impl, vertice, visitados);
}

void encontraComponentes(Grafo *g)
{
    if (!g) return;

    g->operacoes.encontraComponentes(g->impl);
}

void recomendacaoDireta(Grafo* g, int vertice, int* recomendacoes)
{
    if (!g) return;

    g->operacoes.recomendacaoDireta(g->impl, vertice, recomendacoes);
}

void recomendacaoAmigoDeAmigo(Grafo* g, int vertice, int* recomendacoes)
{
    if (!g) return;

    g->operacoes.recomendacaoAmigoDeAmigo(g->impl, vertice, recomendacoes);
}


bool verificarCaminho(Grafo* g, int origem, int destino)
{
    if (!g)
        return false;

    return g->operacoes.verificarCaminho(g->impl, origem, destino);
}
