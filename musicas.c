#include "musicas.h"
#include "structures/graphs.h"

#include <stdio.h>
#include <stdlib.h>


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

void montarGrafo(Grafo* g)
{
    if (g == NULL)
    {
        return;
    }

    /* KPOP */
    insereAresta(g,0,1,1);
    insereAresta(g,0,2,1);
    insereAresta(g,0,3,1);
    insereAresta(g,0,34,1);
    insereAresta(g,0,37,1);
    insereAresta(g,1,3,1);
    insereAresta(g,3,34,1);
    insereAresta(g,1,28,1);
    insereAresta(g,31,32,1);
    insereAresta(g,32,33,1);
    insereAresta(g,27,28,1);
    insereAresta(g,27,3,1);
    insereAresta(g,27,25,1);

    /* RAP */
    insereAresta(g,10,11,1);
    insereAresta(g,11,12,1);
    insereAresta(g,10,12,1);

    /* ROCK */
    insereAresta(g,13,14,1);
    insereAresta(g,13,15,1);
    insereAresta(g,16,17,1);
    insereAresta(g,17,18,1);
    insereAresta(g,15,16,1);
    insereAresta(g,16,35,1);
    insereAresta(g,18,36,1);

    /* POP */
    insereAresta(g,4,5,1);
    insereAresta(g,5,6,1);
    insereAresta(g,6,7,1);
    insereAresta(g,4,9,1);
    insereAresta(g,8,9,1);
    insereAresta(g,4,8,1);
    insereAresta(g,6,8,1);
    insereAresta(g,7,5,1);

    /* PAGODE */
    insereAresta(g,19,20,1);
    insereAresta(g,20,21,1);
    insereAresta(g,21,22,1);
    insereAresta(g,22,19,1);

    /* MAMONAS */
    insereAresta(g,23,24,1);

    /* INDIE */
    insereAresta(g,35,36,1);
    insereAresta(g,16,35,1);

    /* BRUNO MARS */
    insereAresta(g,49,50,1);
    insereAresta(g,49,51,1);
    insereAresta(g,50,51,1);

    /* SKANK */
    insereAresta(g,45,46,1);
    insereAresta(g,46,47,1);
    insereAresta(g,45,47,1);

    /* LEGIAO / RAIMUNDOS */
    insereAresta(g,41,42,1);
    insereAresta(g,42,43,1);
    insereAresta(g,41,43,1);

    /* POP ROCK */
    insereAresta(g,29,30,1);
    insereAresta(g,9,29,1);

    /* ELVIS */
    insereAresta(g,48,35,1);
}


/* recomendacao direta */
void recomendarMusicas(Grafo* g, int id)
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

    int numRecomendacoes = calculaGrau(g, id);

    if (numRecomendacoes == 0)
    {
        printf("nenhuma recomendacao\n");
        return;
    }

    int* recomendacoes = (int*) malloc(numRecomendacoes * sizeof(int));

    if (!recomendacoes)
    {
        printf("\n[RECOMENDACAO-MUSICAS]: Houve um erro ao alocar espaço na memória.\n");
        return;
    }

    recomendacaoDireta(g, id, recomendacoes);

    for (int i = 0; i < numRecomendacoes; i++)
    {
        printf("- %s\n", musicas[recomendacoes[i]]);
    }

    free(recomendacoes);
}



void criarPlaylist(Grafo* g, int musicasIds[NUM_MUSICAS_BASE_PLAYLIST]) {
    if (g == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

    printf("\n\n\n\n   Playlist criada com base nas musicas:\n");

    for (int i = 0; i < NUM_MUSICAS_BASE_PLAYLIST; i++)
    {
        printf("- %s\n", musicas[musicasIds[i]]);
    }

    printf("\n\n   Playlist recomendada:\n");

    int* incluidos = (int*) malloc(g->numVertices * sizeof(int));

    if (!incluidos)
    {
        printf("\n[CRIAR-PLAYLIST]: Não foi possível alocar memória.\n");
        return;
    }

    for (int i = 0; i < g->numVertices; i++)
    {
        incluidos[i] = 0;
    }

    int count = 0;

    // Adicionar as musicas originais
    for (int i = 0; i < NUM_MUSICAS_BASE_PLAYLIST; i++)
    {
        if (!incluidos[musicasIds[i]])
        {
            incluidos[musicasIds[i]] = 1;

            printf("%d. %s\n", ++count, musicas[musicasIds[i]]);
        }
    }

    // add reco diretas de cada musica
    for (int i = 0; i < NUM_MUSICAS_BASE_PLAYLIST; i++)
    {
        int id = musicasIds[i];

        for (int j = 0; j < g->numVertices; j++)
        {
            if (existeAresta(g, i, j) && !incluidos[j])
            {
                incluidos[j] = 1;
                printf("%d. %s\n", ++count, musicas[j]);
            }
        }
    }

    printf("\n\n Total de musicas na playlist: %d\n", count);

    free(incluidos);
}


void recomendarAmigoDeAmigo(Grafo* g, int id)
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

    int numRecomendacoes = g->numVertices - 2;

    int* recomendacoes = (int*) malloc(numRecomendacoes * sizeof(int));

    if (!recomendacoes)
    {
        printf("\n[RECOMENDACAO-AMIGO-AMIGO]: Houve um erro ao alocar espaço na memória.\n");
        return;
    }

    for (int i = 0; i < numRecomendacoes; i++)
    {
        recomendacoes[i] = MUSICA_NAO_RECOMENDADA;
    }

    recomendacaoAmigoDeAmigo(g, id, recomendacoes);

    printf("\namigo de amigo para: %s\n", musicas[id]);

    int achou = 0;

    for (int i = 0; i < numRecomendacoes; i++)
    {
        if (recomendacoes[i] != MUSICA_NAO_RECOMENDADA)
        {
            achou = 1;
            printf("- %s\n", musicas[recomendacoes[i]]);
        }
    }

    if (!achou)
    {
        printf("nenhuma recomendacao de segundo nivel\n");
    }

    free(recomendacoes);
}
