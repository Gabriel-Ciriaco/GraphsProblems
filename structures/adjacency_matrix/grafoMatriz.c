#include "grafoMatriz.h"
#include "../minHeap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

#define MAX_HEAP 10000


GrafoMatriz *criaGrafoMatriz(int vertices)
{
    GrafoMatriz *g = (GrafoMatriz *)malloc(sizeof(GrafoMatriz));
    if (g == NULL)
    {
        return NULL;
    }

    g->numVertices = vertices;

    g->matriz = (int **)malloc(vertices * sizeof(int *));
    if (g->matriz == NULL)
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < vertices; i++)
    {
        g->matriz[i] = (int *)malloc(vertices * sizeof(int));
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->matriz[i][j] = 0;
        }
    }

    return g;
}

void destroiGrafoMatriz(GrafoMatriz *g)
{
    if (g == NULL)
    {
        printf("\nGrafo vazio!\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        free(g->matriz[i]);
    }

    free(g->matriz);
    free(g);
}

void insereArestaMatriz(GrafoMatriz *g, int origem, int destino, int peso)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        return;
    }

    if (g->matriz[origem][destino] == 0)
    {
        g->matriz[origem][destino] = peso;
        g->matriz[destino][origem] = peso;
    }
}

void removeArestaMatriz(GrafoMatriz *g, int origem, int destino)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        return;
    }

    if (g->matriz[origem][destino] != 0)
    {
        g->matriz[origem][destino] = 0;
        g->matriz[destino][origem] = 0;
    }
}

bool existeArestaMatriz(GrafoMatriz *g, int origem, int destino)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        fprintf(stderr, "Erro de vértice inválido ou grafo nulo em existeArestaMatriz!\n");
        exit(EXIT_FAILURE);
    }

    if (g->matriz[origem][destino] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void imprimeGrafoMatriz(GrafoMatriz *g)
{
    if (g == NULL)
    {
        printf("\nGrafo vazio!\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
        {
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeArestasMatriz(GrafoMatriz *g)
{
    if (g == NULL)
    {
        printf("\nGrafo vazio!\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = i; j < g->numVertices; j++)
        {
            if (existeArestaMatriz(g, i, j))
            {
                printf("%d %d\n", i, j);
            }
        }
    }
}

int calculaGrauMatriz(GrafoMatriz *g, int vertice)
{
    int grau = 0;

    for (int i = 0; i < g->numVertices; i++)
    {
        if (existeArestaMatriz(g, vertice, i))
        {
            grau++;
        }
    }
    return grau;
}

int encontraMaisPopularMatriz(GrafoMatriz *g)
{
    if (g == NULL || g->numVertices == 0)
    {
        return -1;
    }

    int u;
    int verticeMax = 0;
    int grauMax = calculaGrauMatriz(g, verticeMax);
    int grauAtual;

    for (u = 1; u < g->numVertices; u++)
    {
        grauAtual = calculaGrauMatriz(g, u);
        if (grauAtual > grauMax)
        {
            grauMax = grauAtual;
            verticeMax = u;
        }
    }
    return verticeMax;
}


void buscaProfundidadeMatriz(GrafoMatriz *g, int vertice, int *visitados)
{
	visitados[vertice] = 1; //Seta o vértice como visitado.
	printf("%d ", vertice);

	/*
    Percorre a linha correspondente ao vértice atual na matriz de adjacência
    para verificar todos os vértices diretamente conectados a ele.
    Se encontrar um vértice adjacente que ainda não foi visitado,
    chama a DFS recursivamente para explorar esse novo vértice.
	*/
	for(int i = 0; i < g->numVertices; i++)
	{
		if((g->matriz[vertice][i] != 0) && (visitados[i] == 0))
		{
			buscaProfundidadeMatriz(g, i, visitados);
		}
	}
}

void encontraComponentesMatriz(GrafoMatriz *g)
{
	/*
	Variável responsável por guardar o número de componentes.
	*/
	int componente = 0;
	int i;
	/*
	Vetor resposável por guardar se um vértice já
	foi visitado ou não.
	*/
	int *visitados = (int*)malloc((g->numVertices) * sizeof(int));
	if(visitados == NULL)
	{
		printf("Erro ao aloar memória!");
		return;
	}
	/*
	Inicializando o vetor com zeros para indicar que
	nenhum vértice foi visitado.
	*/
	for(i = 0; i < g->numVertices; i++)
	{
		visitados[i] = 0;
	}

	for(i = 0; i < g->numVertices; i++)
	{
		if(visitados[i] == 0)
		{
			componente++;
			printf("Componente %d: ", componente);
			/*
			Chama a função dfs_matrizAdj() que é responsável por
			fazer a busca em profundidade.
			*/
			buscaProfundidadeMatriz(g, i, visitados);
			printf("\n");
		}
	}

	free(visitados);
}

void dijkstraMatriz(GrafoMatriz *g, int origem)
{
    int *distancias = malloc(g->numVertices * sizeof(int));
    int *visitados = malloc(g->numVertices * sizeof(int));
    MinHeap *filaPrioridade = cria_heap(MAX_HEAP);

    if(distancias == NULL || visitados == NULL || filaPrioridade == NULL)
    {
        printf("\nErro ao alocar memória!\n");
        return;
    }

    for(int i =0; i < g->numVertices; i++)
    {
        distancias[i] = INT_MAX;
        visitados[i] = 0;

    }

    distancias[origem] = 0;
    push(filaPrioridade, origem, 0);

    while(!empty(filaPrioridade))
    {
        Vertice atual = pop(filaPrioridade);
        int u = atual.v;

        if(visitados[u])
        {
            continue;
        }

        visitados[u] = 1;

        for(int i = 0; i < g->numVertices; i++)
        {
            int peso = g->matriz[u][i];

            if(peso > 0)
            {
                if(distancias[u] != INT_MAX && (distancias[u] + peso) < distancias[i])
                {
                    distancias[i] = distancias[u] + peso;
                    push(filaPrioridade, i, distancias[i]);
                }
            }
        }
    }

    printf("Caminho mínimo de %d até todos os vértices:\n", origem);
    for(int i = 0; i < g->numVertices; i++)
    {
        printf("%d -> %d: %d\n", origem, i, distancias[i]);
    }
    free(distancias);
    free(visitados);
    free(filaPrioridade->heap);
    free(filaPrioridade);
}
