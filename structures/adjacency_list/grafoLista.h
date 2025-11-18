#ifndef GRAFOLISTA_H_INCLUDED
#define GRAFOLISTA_H_INCLUDED

#include <stdbool.h>

typedef struct no
{
    int vertice;
    struct no *proximo;
} No;

typedef struct
{
    No **listasAdj;
    int numVertices;
} GrafoLista;

GrafoLista *criaGrafoLista(int vertices);
void destroiGrafoLista(GrafoLista *g);
void insereArestaLista(GrafoLista *g, int origem, int destino);
void removeArestaLista(GrafoLista *g, int origem, int destino);
bool existeArestaLista(GrafoLista *g, int origem, int destino);
void imprimeArestasLista(GrafoLista *g);
void imprimeGrafoLista(GrafoLista *g);
int calculaGrauLista(GrafoLista *g, int vertice);
int encontraMaisPopularLista(GrafoLista *g);
void buscaProfundidadeLista(GrafoLista *g, int vertice, int *visitados);
void encontraComponentesLista(GrafoLista *g);

#endif // GRAFOLISTA_H_INCLUDED
