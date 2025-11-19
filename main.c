#include <stdio.h>
#include <stdlib.h>
#include "structures/adjacency_matrix/grafoMatriz.h"

int main() {
    // Quantidade de vértices do grafo
    int n = 6;
    GrafoMatriz *g = criaGrafoMatriz(n);

    if (g == NULL) {
        printf("Erro ao criar grafo!\n");
        return 1;
    }

    // Criando um grafo de teste
    /*
        Grafo usado:

            (0)
           /   \
         7/     \9
         /       \
       (1)---10--(2)
         \         \
         15         2
          \         \
          (3)---1--(4)
                 \
                  6
                   \
                   (5)
    */

    insereArestaMatriz(g, 0, 1, 7);
    insereArestaMatriz(g, 0, 2, 9);
    insereArestaMatriz(g, 1, 2, 10);
    insereArestaMatriz(g, 1, 3, 15);
    insereArestaMatriz(g, 2, 4, 2);
    insereArestaMatriz(g, 3, 4, 1);
    insereArestaMatriz(g, 4, 5, 6);

    printf("Matriz de adjacencia do grafo:\n");
    imprimeGrafoMatriz(g);

    printf("\nExecutando Dijkstra a partir do vertice 0:\n\n");
    dijkstraMatriz(g, 0);

    destroiGrafoMatriz(g);

    return 0;
}
