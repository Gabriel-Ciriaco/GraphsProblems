#include <stdio.h>
#include <stdlib.h>
#include "musicas.h"
#include "structures/adjacency_list/grafoLista.h"





/*  lista de musicas poggers hyoe  */
char* musicas[MAX_MUSICAS] = {
    "HOLLYWOOD ACTION - boynextdoor",
    "sticker - nct",
    "but sometimes - boynextdoor",
    "poppop - nct wish",
    "treat you better - shawn mendes",
    "blank space - taylor swift",
    "perfect - ed sheeran",
    "photograph - ed sheeran",
    "steal my girl - one direction",
    "what makes you beautiful - one direction",
    "diario de um detento - racionais",
    "cachimbo da paz - gabriel o pensador",
    "2345meia78 - gabriel o pensador",
    "american idiot - green day",
    "21 guns - green day",
    "californication - red hot chilli peppers",
    "somebody told me - the killers",
    "numb - linkin park",
    "welcome to the black parade - mcr",
    "camisa 10 - turma do pagode",
    "melhor amigo - turma do pagode",
    "inseguranca - pixote",
    "deixa tudo como ta - thiaguinho",
    "pelados em santos - mamonas assassinas",
    "vira-vira - mamonas assassinas",
    "GABRIELLA - KATEYES",
    "golden - huntrix",
    "love language - txt",
    "cat & dog - txt",
    "youngblood - 5sos",
    "animals - maroon 5",
    "python - got7",
    "you calling my name - got7",
    "monster - exo",
    "jopping - superm",
    "stand by me - oasis",
    "505 - arctic monkeys",
    "pass the mic - enhypen",
    "xo - enhypen",
    "deja vu - olivia rodrigo",
    "expresso - sabrina carpenter",
    "tempo perdido - legiao urbana",
    "sera - legiao urbana",
    "mulher de fases - raimundos",
    "whisky a gogo - roupa nova",
    "ainda gosto dela - skank",
    "vamos fugir - skank",
    "jackie tequila - skank",
    "jailhouse rock - elvis presley",
    "thats what i like - bruno mars",
    "the lazy song - bruno mars",
    "APT - bruno mars e rose"
};






/*  inserearestaLista, listasad) */
void montarGrafoLista(GrafoLista* g)
{
    if (g == NULL)
        {
        return;
    }

    /* inicializa listasdj ) */
    for (int i = 0; i < g->numVertices; i++)
    {
        g->listasAdj[i] = g->listasAdj[i];
    }

    /* KPOP */
    insereArestaLista(g,0,1,0);
    insereArestaLista(g,0,2,0);
    insereArestaLista(g,0,3,0);
    insereArestaLista(g,0,34,0);
    insereArestaLista(g,0,37,0);
    insereArestaLista(g,1,3,0);
    insereArestaLista(g,3,34,0);
    insereArestaLista(g,1,28,0);
    insereArestaLista(g,31,32,0);
    insereArestaLista(g,32,33,0);
    insereArestaLista(g,27,28,0);
    insereArestaLista(g,27,3,0);
    insereArestaLista(g,27,25,0);

    /* RAP */
    insereArestaLista(g,10,11,0);
    insereArestaLista(g,11,12,0);
    insereArestaLista(g,10,12,0);

    /* ROCK */
    insereArestaLista(g,13,14,0);
    insereArestaLista(g,13,15,0);
    insereArestaLista(g,16,17,0);
    insereArestaLista(g,17,18,0);
    insereArestaLista(g,15,16,0);
    insereArestaLista(g,16,35,0);
    insereArestaLista(g,18,36,0);

    /* POP */
    insereArestaLista(g,4,5,0);
    insereArestaLista(g,5,6,0);
    insereArestaLista(g,6,7,0);
    insereArestaLista(g,4,9,0);
    insereArestaLista(g,8,9,0);
    insereArestaLista(g,4,8,0);
    insereArestaLista(g,6,8,0);
    insereArestaLista(g,7,5,0);

    /* PAGODE */
    insereArestaLista(g,19,20,0);
    insereArestaLista(g,20,21,0);
    insereArestaLista(g,21,22,0);
    insereArestaLista(g,22,19,0);

    /* MAMONAS */
    insereArestaLista(g,23,24,0);

    /* INDIE */
    insereArestaLista(g,35,36,0);
    insereArestaLista(g,16,35,0);

    /* BRUNO MARS */
    insereArestaLista(g,49,50,0);
    insereArestaLista(g,49,51,0);
    insereArestaLista(g,50,51,0);

    /* SKANK */
    insereArestaLista(g,45,46,0);
    insereArestaLista(g,46,47,0);
    insereArestaLista(g,45,47,0);

    /* LEGIAO / RAIMUNDOS */
    insereArestaLista(g,41,42,0);
    insereArestaLista(g,42,43,0);
    insereArestaLista(g,41,43,0);

    /* POP ROCK */
    insereArestaLista(g,29,30,0);
    insereArestaLista(g,9,29,0);

    /* ELVIS */
    insereArestaLista(g,48,35,0);
}







/* recomendacao direta (lista) */
void recomendarMusicasLista(GrafoLista* g, int id)
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

    printf("\n\n   musicas similares a: %s\n", musicas[id]);

    No* atual = g->listasAdj[id];
    if (atual == NULL)
    {
        printf("nenhuma recomendacao\n");
        return;
    }

    while (atual != NULL)
    {
        printf("- %s\n", musicas[atual->vertice]);
        atual = atual->proximo;
    }
}





void criarPlaylistLista(GrafoLista* g, int musicasIds[3]) {
    if (g == NULL) {
        printf("Grafo nulo\n");
        return;
    }

    printf("\n\n\n\n   Playlist criada com base nas musicas:\n");
    for (int i = 0; i < 3; i++) {
        printf("- %s\n", musicas[musicasIds[i]]);
    }
    printf("\n\n   Playlist recomendada:\n");

    int incluidos[MAX_MUSICAS] = {0};
    int count = 0;

    // Adicionar as 3 musicas originais
    for (int i = 0; i < 3; i++) {
        if (!incluidos[musicasIds[i]]) {
            incluidos[musicasIds[i]] = 1;
            printf("%d. %s\n", ++count, musicas[musicasIds[i]]);
        }
    }

    // Add reco diretas de cada musica
    for (int i = 0; i < 3; i++)
        {
        No* atual = g->listasAdj[musicasIds[i]];

        while (atual != NULL)
        {
            if (!incluidos[atual->vertice])
            {
                incluidos[atual->vertice] = 1;
                printf("%d. %s\n", ++count, musicas[atual->vertice]);
            }
            atual = atual->proximo;
        }
    }

    printf("\n\n Total de musicas na playlist: %d\n", count);
}




/* amigo de amigo (lista) */
void recomendarAmigoDeAmigoLista(GrafoLista* g, int id)
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

    int visitado[MAX_MUSICAS] = {0};
    int direto[MAX_MUSICAS] = {0};

    No* atual = g->listasAdj[id];

    while (atual != NULL)
    {
        direto[atual->vertice] = 1;
        atual = atual->proximo;
    }

    printf("\namigo de amigo para: %s\n", musicas[id]);

    atual = g->listasAdj[id];
    int achou = 0;

    while (atual != NULL)
        {
        No* segundo = g->listasAdj[atual->vertice];

        while (segundo != NULL)
            {
            int m = segundo->vertice;

            if (m != id && !direto[m] && !visitado[m])
            {
                visitado[m] = 1;
                achou = 1;
                printf("- %s\n", musicas[m]);
            }

            segundo = segundo->proximo;
        }

        atual = atual->proximo;
    }

    if (!achou)
    {
        printf("nenhuma recomendacao de segundo nivel\n");
    }
}






/* verificar caminho (lista) */
bool verificarCaminhoLista(GrafoLista* g, int origem, int destino)
{
    if (g == NULL)
    {
        return false;
    }
    if (origem < 0 || destino < 0 || origem >= MAX_MUSICAS || destino >= MAX_MUSICAS)
    {
        return false;
    }

    if (existeArestaLista(g, origem, destino))
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


    /* dfs recursiva */
    void dfs(int v)
    {
        visitados[v] = 1;
        No* aux = g->listasAdj[v];

        while (aux != NULL)
        {
            if (!visitados[aux->vertice])
            {
                dfs(aux->vertice);
            }
            aux = aux->proximo;
        }
    }

    dfs(origem);
    int resp = visitados[destino];
    free(visitados);
    return resp == 1;
}

