#include "grafoMatriz.h"
#include "../min_heap/minHeap.h"

#include "../queue/queue.h"

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

        if (g->matriz[i] == NULL)
        {
            while(i > 0) free(g->matriz[--i]);

            free(g->matriz);

free(g);

            return NULL;
        }
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
        fprintf(stderr, "Erro de v�rtice inv�lido ou grafo nulo em existeArestaMatriz!\n");
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
	visitados[vertice] = 1; //Seta o v�rtice como visitado.
	printf("%d ", vertice);

	/*
    Percorre a linha correspondente ao v�rtice atual na matriz de adjac�ncia
    para verificar todos os v�rtices diretamente conectados a ele.
    Se encontrar um v�rtice adjacente que ainda n�o foi visitado,
    chama a DFS recursivamente para explorar esse novo v�rtice.
	*/
	for(int i = 0; i < g->numVertices; i++)
	{
		if((g->matriz[vertice][i] != 0) && (visitados[i] == 0))
		{
			buscaProfundidadeMatriz(g, i, visitados);
		}
	}
}

void buscaLarguraMatriz(GrafoMatriz *g, int vertice, int *visitados)
{
    if (!g) return;

    Queue fila = criarQueue();

    pushQueue(&fila, vertice);

    visitados[vertice] = 1;

    while(fila.top)
    {
        int v = popQueue(&fila);

        printf("%d ", v);

        // V�rtices adjacentes.
        for (int i = 0; i < g->numVertices; i++)
        {
            if (existeArestaMatriz(g, v, i) && !visitados[i])
            {
                pushQueue(&fila, i); // Adicionamos na fila.

                visitados[i] = 1; // Evita duplicatas.
            }
        }
    }

    destroiQueue(&fila);
}

void encontraComponentesMatriz(GrafoMatriz *g)
{
	/*
	Vari�vel respons�vel por guardar o n�mero de componentes.
	*/
	int componente = 0;
	int i;
	/*
	Vetor respos�vel por guardar se um v�rtice j�
	foi visitado ou n�o.
	*/
	int *visitados = (int*)malloc((g->numVertices) * sizeof(int));
	if(visitados == NULL)
	{
		printf("Erro ao alocar mem�ria!");
		return;
	}
	/*
	Inicializando o vetor com zeros para indicar que
	nenhum v�rtice foi visitado.
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
			Chama a fun��o dfs_matrizAdj() que � respons�vel por
			fazer a busca em profundidade.
			*/
			buscaProfundidadeMatriz(g, i, visitados);
			printf("\n");
		}
	}

	free(visitados);
}


void recomendacaoDiretaMatriz(GrafoMatriz* g, int vertice, int* recomendacoes)
{
    if (g == NULL || recomendacoes == NULL)
    {
        printf("grafo nulo\n");
        return;
    }

    if (vertice < 0)
    {
        printf("vertice invalido\n");
        return;
    }

    int rIdx = 0; // Indice de recomendacoes.

    for (int j = 0; j < g->numVertices; j++)
    {
        if (existeArestaMatriz(g, vertice, j))
        {
            recomendacoes[rIdx++] = j;
        }
    }
}


void recomendacaoAmigoDeAmigoMatriz(GrafoMatriz* g, int vertice, int* recomendacoes)
{
    if (g == NULL)
    {
        printf("grafo nulo\n");
        return;
    }

    if (vertice < 0)
    {
        printf("vertice invalido\n");
        return;
    }

    int* direto = (int*) malloc(g->numVertices * sizeof(int));
    int* marcado = (int*) malloc(g->numVertices * sizeof(int));

    if (!direto || !marcado)
    {
        if (direto)
            free(direto);

        if (marcado)
            free(marcado);

        printf("\n[RECOMENDACAO-AMIGO-AMIGO-MATRIZ: N�o foi poss�vel alocar mem�ria.\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        direto[i] = 0;
        marcado[i] = 0;
    }

    for (int j = 0; j < g->numVertices; j++)
    {
        if (existeArestaMatriz(g, vertice, j))
        {
            direto[j] = 1;
        }
    }


    int rIdx = 0; // Indice de recomendacoes

    for (int amigo = 0; amigo < g->numVertices; amigo++)
    {
        if (existeArestaMatriz(g, vertice, amigo))
        {
            for (int amigo2 = 0; amigo2 < g->numVertices; amigo2++)
            {
                if (existeArestaMatriz(g,amigo, amigo2))
                {
                    if (amigo2 != vertice && !direto[amigo2] && !marcado[amigo2])
                    {
                        marcado[amigo2] = 1;

                        recomendacoes[rIdx++] = amigo2;
                    }
                }
            }
        }
    }

    free(direto);
    free(marcado);
}


void dijkstraMatriz(GrafoMatriz *g, int origem)
{
    int *distancias = malloc(g->numVertices * sizeof(int));
    int *visitados = malloc(g->numVertices * sizeof(int));
    MinHeap *filaPrioridade = cria_heap(MAX_HEAP);

    if(distancias == NULL || visitados == NULL || filaPrioridade == NULL)
    {
        printf("\nErro ao alocar mem�ria!\n");
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

    printf("Caminho m�nimo de %d at� todos os v�rtices:\n", origem);
    for(int i = 0; i < g->numVertices; i++)
    {
        printf("%d -> %d: %d\n", origem, i, distancias[i]);
    }
    free(distancias);
    free(visitados);
    free(filaPrioridade->heap);
    free(filaPrioridade);
}


bool verificarCaminhoMatriz(GrafoMatriz* g, int origem, int destino)
{
    if (g == NULL)
    {
        return false;
    }

    if (origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        return false;
    }

    if (existeArestaMatriz(g, origem, destino))
    {
        return true;
    }

    int* visitados = (int*)malloc(sizeof(int) * g->numVertices);

    if (visitados == NULL)
    {
        printf("erro de memoria\n");
        return false;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        visitados[i] = 0;
    }

    buscaProfundidadeMatriz(g, origem, visitados);


    int resp = visitados[destino];

    free(visitados);

    return resp == 1;
}
