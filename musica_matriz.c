#include <stdio.h>
#include <stdlib.h>
#include "musicas.h"
#include "structures/adjacency_matrix/grafoMatriz.h"

/* montar grafo matriz */
void montarGrafoMatriz(GrafoMatriz* g)
{
    if (g == NULL)
        {
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
            {
            g->matriz[i][j] = 0;
        }
    }

    /* KPOP */
    insereArestaMatriz(g,0,1);
    insereArestaMatriz(g,0,2);
    insereArestaMatriz(g,0,3);
    insereArestaMatriz(g,0,34);
    insereArestaMatriz(g,0,37);
    insereArestaMatriz(g,1,3);
    insereArestaMatriz(g,3,34);
    insereArestaMatriz(g,1,28);
    insereArestaMatriz(g,31,32);
    insereArestaMatriz(g,32,33);
    insereArestaMatriz(g,27,28);
    insereArestaMatriz(g,27,3);
    insereArestaMatriz(g,27,25);

    /* RAP */
    insereArestaMatriz(g,10,11);
    insereArestaMatriz(g,11,12);
    insereArestaMatriz(g,10,12);

    /* ROCK */
    insereArestaMatriz(g,13,14);
    insereArestaMatriz(g,13,15);
    insereArestaMatriz(g,16,17);
    insereArestaMatriz(g,17,18);
    insereArestaMatriz(g,15,16);
    insereArestaMatriz(g,16,35);
    insereArestaMatriz(g,18,36);

    /* POP */
    insereArestaMatriz(g,4,5);
    insereArestaMatriz(g,5,6);
    insereArestaMatriz(g,6,7);
    insereArestaMatriz(g,4,9);
    insereArestaMatriz(g,8,9);
    insereArestaMatriz(g,4,8);
    insereArestaMatriz(g,6,8);
    insereArestaMatriz(g,7,5);

    /* PAGODE */
    insereArestaMatriz(g,19,20);
    insereArestaMatriz(g,20,21);
    insereArestaMatriz(g,21,22);
    insereArestaMatriz(g,22,19);

    /* MAMONAS */
    insereArestaMatriz(g,23,24);

    /* INDIE */
    insereArestaMatriz(g,35,36);
    insereArestaMatriz(g,16,35);

    /* BRUNO MARS */
    insereArestaMatriz(g,49,50);
    insereArestaMatriz(g,49,51);
    insereArestaMatriz(g,50,51);

    /* SKANK */
    insereArestaMatriz(g,45,46);
    insereArestaMatriz(g,46,47);
    insereArestaMatriz(g,45,47);

    /* LEGIAO / RAIMUNDOS */
    insereArestaMatriz(g,41,42);
    insereArestaMatriz(g,42,43);
    insereArestaMatriz(g,41,43);

    /* POP ROCK */
    insereArestaMatriz(g,29,30);
    insereArestaMatriz(g,9,29);

    /* ELVIS */
    insereArestaMatriz(g,48,35);
}





/* recomendacao direta (matriz) */
void recomendarMusicasMatriz(GrafoMatriz* g, int id)
{
    if (g == NULL)
    {
        printf("grafo nulo\n");
        return;
    }
    if (id < 0 || id >= MAX_MUSICAS)
    {
        printf("id invalido\n");
        return;
    }



    printf("\n\n\n   musicas similares a: %s\n", musicas[id]);

    int achou = 0;
    for (int j = 0; j < g->numVertices; j++)
    {
        if (g->matriz[id][j] == 1)
        {
            printf("- %s\n", musicas[j]);
            achou = 1;
        }
    }

    if (!achou)
    {
        printf("nenhuma recomendacao\n");
    }
}




/* amigo de amigo (matriz) */
void recomendarAmigoDeAmigoMatriz(GrafoMatriz* g, int id)
{

    if (g == NULL)
    {
        printf("grafo nulo\n");
        return;
    }
    if (id < 0 || id >= MAX_MUSICAS)
    {
        printf("id invalido\n");
        return;
    }

    int direto[MAX_MUSICAS] = {0};
    int marcado[MAX_MUSICAS] = {0};
    int achou = 0;

    for (int j = 0; j < g->numVertices; j++)
    {
        if (g->matriz[id][j] == 1)
        {
            direto[j] = 1;
        }
    }

    printf("\n\n   amigo de amigo para: %s\n", musicas[id]);

    for (int amigo = 0; amigo < g->numVertices; amigo++)
    {
        if (g->matriz[id][amigo] == 1)
        {
            for (int amigo2 = 0; amigo2 < g->numVertices; amigo2++)
                {
                if (g->matriz[amigo][amigo2] == 1)
                {

                    if (amigo2 != id && !direto[amigo2] && !marcado[amigo2])
                    {
                        marcado[amigo2] = 1;
                        achou = 1;
                        printf("- %s\n", musicas[amigo2]);
                    }
                }
            }
        }
    }

    if (!achou)
    {
        printf("nenhuma recomendacao de segundo nivel\n");
    }
}




/* verifica caminho (matriz) */
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

    void dfs(int v)
    {
        visitados[v] = 1;
        for (int i = 0; i < g->numVertices; i++)
            {
            if (g->matriz[v][i] == 1 && !visitados[i])
            {
                dfs(i);
            }
        }
    }

    dfs(origem);
    int resp = visitados[destino];
    free(visitados);
    return resp == 1;
}



void criarPlaylistMatriz(GrafoMatriz* g, int musicasIds[3])
{
    if (g == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

    printf("\n\n\n   Playlist criada com base nas musicas:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("- %s\n", musicas[musicasIds[i]]);
    }

    printf("\n\n   Playlist recomendada:\n");

    int incluidos[MAX_MUSICAS] = {0};
    int count = 0;


    // add as 3 musicas originais
    for (int i = 0; i < 3; i++)
    {
        if (!incluidos[musicasIds[i]])
         {
            incluidos[musicasIds[i]] = 1;
            printf("%d. %s\n", ++count, musicas[musicasIds[i]]);
        }
    }


    // add reco diretas de cada musica
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
        {

            if (g->matriz[musicasIds[i]][j] == 1 && !incluidos[j])
            {
                incluidos[j] = 1;
                printf("%d. %s\n", ++count, musicas[j]);
            }
        }
    }

    printf("\n\n   Total de musicas na playlist: %d\n", count);
}

