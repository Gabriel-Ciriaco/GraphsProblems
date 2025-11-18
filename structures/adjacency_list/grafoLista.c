#include "grafo_lista.h"
#include "../minHeap.h"

#include<stdlib.h>
#include<limits.h>

#define MAX_HEAP 10000

No *criaNo(int vertice, int peso)
{
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        return NULL;
    }
    novoNo->vertice = vertice;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

GrafoLista *criaGrafoLista(int vertices)
{
    GrafoLista *g = (GrafoLista *)malloc(sizeof(GrafoLista));
    if (g == NULL)
    {
        return NULL;
    }

    g->numVertices = vertices;

    g->listasAdj = (No **)malloc(g->numVertices * sizeof(No *));
    if (g->listasAdj == NULL)
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        g->listasAdj[i] = NULL;
    }
    return g;
}

void destroiGrafoLista(GrafoLista *g)
{
    if (g == NULL)
    {
        printf("\nGrafo vazio!\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        No *atual = g->listasAdj[i];
        while (atual != NULL)
        {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(g->listasAdj);
    free(g);
}

void insereArestaLista(GrafoLista *g, int origem, int destino, int peso)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        return;
    }

    No *novoNo = criaNo(destino, peso);
    if(novoNo == NULL)
    {
        printf("Erro ao alocar memória!");
        return NULL;
    }
    novoNo->proximo = g->listasAdj[origem];
    g->listasAdj[origem] = novoNo;

    novoNo = criaNo(origem, peso);
    if(novoNo == NULL)
    {
        printf("Erro ao alocar memória!");
        return NULL;
    }
    novoNo->proximo = g->listasAdj[destino];
    g->listasAdj[destino] = novoNo;
}

void removeArestaLista(GrafoLista *g, int origem, int destino)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        return;
    }

    No *atual = g->listasAdj[origem];
    No *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->vertice == destino)
        {
            if (anterior == NULL)
            {
                g->listasAdj[origem] = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    atual = g->listasAdj[destino];
    anterior = NULL;
    while (atual != NULL)
    {
        if (atual->vertice == origem)
        {
            if (anterior == NULL)
            {
                g->listasAdj[destino] = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

bool existeArestaLista(GrafoLista *g, int origem, int destino)
{
    if (g == NULL || origem < 0 || destino < 0 || origem >= g->numVertices || destino >= g->numVertices)
    {
        exit(1);
    }

    No *atual = g->listasAdj[origem];
    while (atual != NULL)
    {
        if (atual->vertice == destino)
        {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void imprimeGrafoLista(GrafoLista *g)
{
    if (g == NULL)
    {
        printf("\nGrafo vazio!\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        No *atual = g->listasAdj[i];
        printf("Vértice %d: ", i);
        while (atual != NULL)
        {
            printf(" -> %d ", atual->vertice);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

int calculaGrauLista(GrafoLista *g, int vertice)
{
    if (g == NULL || vertice < 0 || vertice >= g->numVertices)
    {
        return -1;
    }

    int grau = 0;
    No *atual = g->listasAdj[vertice];
    while (atual != NULL)
    {
        grau++;
        atual = atual->proximo;
    }
    return grau;
}

int encontraMaisPopularLista(GrafoLista *g)
{
    if (g == NULL || g->numVertices == 0)
    {
        return -1;
    }

    int maiorGrau, verticeMaisPopular;
    verticeMaisPopular = 0;
    maiorGrau = calculaGrauLista(g, 0);

    for (int i = 1; i < g->numVertices; i++)
    {
        int grauAtual = calculaGrauLista(g, i);
        if (grauAtual > maiorGrau)
        {
            maiorGrau = grauAtual;
            verticeMaisPopular = i;
        }
    }
    return verticeMaisPopular;
}

void buscaProfundidadeLista(GrafoLista *g, int vertice, int *visitados)
{
	visitados[vertice] = 1;
	printf("%d ", vertice);

	No *atual = g->listasAdj[vertice];
	/*
    Percorre a lista correspondente ao vértice atual na lista de adjacência
    para verificar todos os vértices diretamente conectados a ele.
    Se encontrar um vértice adjacente que ainda não foi visitado,
    chama a DFS recursivamente para explorar esse novo vértice.
	*/
	while(atual != NULL)
	{
		if(visitados[atual->vertice] == 0)
		{
			buscaProfundidadeLista(g, atual->vertice, visitados);
		}
		atual = atual->proximo;
	}
}

void encontraComponentesLista(GrafoLista *g)
{
	/*
	Variável responsável por guardar o número de componentes.
	*/
	int componente = 0;
	int i = 0;
	/*
	Vetor resposável por guardar se um vértice já
	foi visitado ou não.
	*/
	int *visitados = malloc((g->numVertices) * sizeof(int));
	if(visitados == NULL)
	{
		printf("Erro ao alocar memória!");
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
			Chama a função dfs_listaAdj() que é responsável por
			fazer a busca em profundidade.
			*/
			buscaProfundidadeLista(g, i, visitados);
			printf("\n");
		}
	}

	free(visitados);
}

void dijkstraLista(GrafoLista *g, int origem)
{
    /*
    Cria um array de distâncias dist[]  de tamanho V
    e incializa todos os valores com infinito (∞).
    */
    int *distancias = malloc(g->numVertices * sizeof(int));
    int *visitados = malloc(g->numVertices *sizeof(int));
    MinHeap *filaPrioridade = cria_heap(MAX_HEAP);
    if(distancias == NULL || visitados == NULL || filaPrioridade == NULL)
    {
        printf("\nErro ao alocar memória!\n");
        free(distancias);
        free(visitados);
        free(filaPrioridade);
        return;
    }

    for(int i = 0; i < g->numVertices; i++)
    {
        distancias[i] = INT_MAX;
        visitados[i] = 0;
    }

    /*
    Defina dist[origem]=0 e insira o vértice
    na fila de prioridade.
    */
    distancias[origem] = 0;
    push(filaPrioridade, origem, 0);

    while(!empty(filaPrioridade))
    {
        Vertice atual = pop(filaPrioridade);
        int u = atual.v;

        if(visitados[u] == 1) /*Se o vértice já foi visitado, vamos para o próximo.*/
        {
            continue;
        }
        visitados[u] = 1;

        No *no = g->listasAdj[u];
        while(no != NULL)
        {
            int vertice = no->vertice;
            int peso = no->peso;

            if((distancias[u]) != INT_MAX && ((distancias[u] + peso) < distancias[vertice]))
            {
                distancias[vertice] = distancias[u] + peso;
                push(filaPrioridade, vertice, distancias[vertice]);
            }

            no = no->proximo;
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
