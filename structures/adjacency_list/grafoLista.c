#include "grafoLista.h"

#include "../min_heap/minHeap.h"
#include "../queue/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    }
    novoNo->proximo = g->listasAdj[origem];
    g->listasAdj[origem] = novoNo;

    novoNo = criaNo(origem, peso);
    if(novoNo == NULL)
    {
        printf("Erro ao alocar memória!");
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

void imprimeArestasLista(GrafoLista *g)
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
            if (atual->vertice <= i &&
                existeArestaLista(g, i, atual->vertice))
            {
                printf("%d %d\n", i, atual->vertice);
            }

            atual = atual->proximo;
        }
    }

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
        printf("Vertice %d: ", i);
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


void buscaLarguraLista(GrafoLista *g, int vertice, int *visitados)
{
    if (!g) return;

    Queue fila = criarQueue();

    pushQueue(&fila, vertice);

    visitados[vertice] = 1;

    while(fila.top)
    {
        int v = popQueue(&fila);

        printf("%d ", v);

        // Vértices adjacentes.
        for (int i = 0; i < g->numVertices; i++)
        {
            if (existeArestaLista(g, v, i) && !visitados[i])
            {
                pushQueue(&fila, i); // Adicionamos na fila.

                visitados[i] = 1; // Evita duplicatas.
            }
        }
    }

    destroiQueue(&fila);
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

            if((distancias[u] != INT_MAX) && ((distancias[u] + peso) < distancias[vertice]))
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


void recomendacaoDiretaLista(GrafoLista* g, int vertice, int *recomendacoes)
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

    No* atual = g->listasAdj[vertice];

    if (atual == NULL)
    {
        return;
    }

    int i = 0;

    while (atual != NULL)
    {
        recomendacoes[i++] = atual->vertice;

        atual = atual->proximo;
    }
}


void recomendacaoAmigoDeAmigoLista(GrafoLista* g, int vertice, int* recomendacoes)
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

    int* visitado = (int*) malloc(g->numVertices * sizeof(int));
    int* direto = (int*) malloc(g->numVertices * sizeof(int));

    if (!visitado || !direto)
    {
        if (visitado)
            free(visitado);

        if (direto)
            free(direto);

        printf("\n[RECOMENDACAO-AMIGO-AMIGO-LISTA: Não foi possível alocar memória.\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        visitado[i] = 0;
        direto[i] = 0;
    }

    No* atual = g->listasAdj[vertice];

    while (atual != NULL)
    {
        direto[atual->vertice] = 1;
        atual = atual->proximo;
    }

    atual = g->listasAdj[vertice];

    int rIdx = 0; // Indice de recomendacoes.

    while (atual != NULL)
    {
        No* segundo = g->listasAdj[atual->vertice];

        while (segundo != NULL)
        {
            int m = segundo->vertice;

            if (m != vertice && !direto[m] && !visitado[m])
            {
                visitado[m] = 1;

                recomendacoes[rIdx++] = m;
            }

            segundo = segundo->proximo;
        }

        atual = atual->proximo;
    }

    free(visitado);
    free(direto);
}


bool verificarCaminhoLista(GrafoLista* g, int origem, int destino)
{
    if (g == NULL)
    {
        return false;
    }
    if (origem < 0 || destino < 0)
    {
        return false;
    }

    if (existeArestaLista(g, origem, destino))
    {
        return true;
    }

    int* visitados = (int*) malloc(sizeof(int) * g->numVertices);

    if (visitados == NULL)
    {
        printf("erro de memoria\n");
        return false;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        visitados[i] = 0;
    }

    buscaProfundidadeLista(g, origem, visitados);

    int resp = visitados[destino];

    free(visitados);

    return resp == 1;
}
