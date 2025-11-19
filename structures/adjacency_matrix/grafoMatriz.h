#ifndef GRAFOMATRIZ_H_INCLUDED
#define GRAFOMATRIZ_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    int numVertices;
    int **matriz;
} GrafoMatriz;

GrafoMatriz *criaGrafoMatriz(int vertices);

void destroiGrafoMatriz(GrafoMatriz *g);

void insereArestaMatriz(GrafoMatriz *g, int origem, int destino);

void removeArestaMatriz(GrafoMatriz *g, int origem, int destino);

bool existeArestaMatriz(GrafoMatriz *g, int origem, int destino);

void imprimeGrafoMatriz(GrafoMatriz *g);

void imprimeArestasMatriz(GrafoMatriz *g);

int calculaGrauMatriz(GrafoMatriz *g, int vertice);

int encontraMaisPopularMatriz(GrafoMatriz *g);

void buscaProfundidadeMatriz(GrafoMatriz *g, int vertice, int *visitados);

void buscaLarguraMatriz(GrafoMatriz *g, int vertice, int *visitados);

void encontraComponentesMatriz(GrafoMatriz *g);

void recomendacaoDiretaMatriz(GrafoMatriz* g, int vertice, int* recomendacoes);

void recomendacaoAmigoDeAmigoMatriz(GrafoMatriz* g, int vertice, int* recomendacoes);

bool verificarCaminhoMatriz(GrafoMatriz* g, int origem, int destino);

#endif // GRAFOMATRIZ_H_INCLUDED
