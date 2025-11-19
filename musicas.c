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
    "APT - bruno mars e rose",
    "Hino do Corinthians",
    "Hino do Sao Paulo F.C",
    "Sou Alvinegro da Vila Belmiro",
};

void montarGrafo(Grafo* g)
{
    if (g == NULL)
    {
        return;
    }

     /* COMBINAÇÕES REPETIDAS - SEGUNDA LISTA TEM PRIORIDADE */
insereAresta(g,0,2,9);    // boynextdoor - boynextdoor
insereAresta(g,1,3,8);    // nct - nct wish
insereAresta(g,27,28,7);  // txt - txt
insereAresta(g,31,32,10);  // got7 - got7
insereAresta(g,0,1,10);    // boynextdoor - nct
insereAresta(g,0,3,8);    // boynextdoor - nct wish
insereAresta(g,0,34,9);   // boynextdoor - superm
insereAresta(g,0,37,10);   // boynextdoor - enhypen
insereAresta(g,3,34,8);   // nct wish - superm
insereAresta(g,32,33,10);  // got7 - exo
insereAresta(g,13,14,8);  // green day - green day
insereAresta(g,41,42,9);  // legiao urbana - legiao urbana
insereAresta(g,45,46,10);  // skank - skank
insereAresta(g,35,36,9);  // oasis - arctic monkeys
insereAresta(g,6,7,10);    // ed sheeran - ed sheeran
insereAresta(g,8,9,9);    // one direction - one direction
insereAresta(g,49,50,7);  // bruno mars - bruno mars
insereAresta(g,4,5,9);    // shawn mendes - taylor swift
insereAresta(g,5,6,7);    // taylor swift - ed sheeran
insereAresta(g,4,8,9);    // shawn mendes - one direction
insereAresta(g,29,30,6);  // 5sos - maroon 5
insereAresta(g,19,20,10);  // turma do pagode - turma do pagode
insereAresta(g,20,21,9);  // turma do pagode - pixote
insereAresta(g,21,22,10);  // pixote - thiaguinho
insereAresta(g,23,24,10);  // mamonas - mamonas
insereAresta(g,10,11,8);  // racionais - gabriel pensador
insereAresta(g,11,12,7);  // gabriel pensador - gabriel pensador
insereAresta(g,41,43,7);  // legiao urbana - raimundos
insereAresta(g,46,47,6);  // skank - skank
insereAresta(g,50,51,7);  // bruno mars - bruno mars


insereAresta(g,1,28,6);   // nct - txt
insereAresta(g,27,25,4);  // txt - kateyes
insereAresta(g,13,15,7);  // green day - red hot
insereAresta(g,16,17,8);  // the killers - linkin park
insereAresta(g,17,18,9);  // linkin park - mcr
insereAresta(g,15,16,7);  // red hot - the killers
insereAresta(g,16,35,6);  // the killers - oasis
insereAresta(g,18,36,7);  // mcr - arctic monkeys
insereAresta(g,4,9,7);    // shawn mendes - one direction
insereAresta(g,6,8,6);    // ed sheeran - one direction
insereAresta(g,7,5,7);    // ed sheeran - taylor swift
insereAresta(g,22,19,8);  // thiaguinho - turma do pagode
insereAresta(g,49,51,9);  // bruno mars - bruno mars e rose
insereAresta(g,45,47,10); // skank - skank
insereAresta(g,42,43,7);  // legiao urbana - raimundos
insereAresta(g,9,29,6);   // one direction - 5sos
insereAresta(g,48,35,5);  // elvis - oasis
//--------------------------------------------------


insereAresta(g,37,38,7);  // enhypen - enhypen
insereAresta(g,0,27,6);   // boynextdoor - txt
insereAresta(g,1,27,6);   // nct - txt
insereAresta(g,26,3,8);   // huntrix - nct wish
insereAresta(g,34,33,9);  // superm - exo
insereAresta(g,34,1,9);   // superm - nct
insereAresta(g,13,16,10); // green day - the killers
insereAresta(g,14,17,8);  // green day - linkin park
insereAresta(g,16,36,3);  // the killers - arctic monkeys
insereAresta(g,42,45,9);  // legiao urbana - skank
insereAresta(g,39,40,1);  // olivia rodrigo - sabrina carpenter
insereAresta(g,36,41,6);  // arctic monkeys - legiao urbana
insereAresta(g,36,42,5);  // arctic monkeys - legiao urbana
insereAresta(g,36,6,3);   // arctic monkeys - ed sheeran

/*  ENTRE GNEROS DIFERENTES */
insereAresta(g,1,16,4);   // nct - the killers
insereAresta(g,27,5,5);   // txt - taylor swift
insereAresta(g,34,30,3);  // superm - maroon 5
insereAresta(g,27,9,7);   // txt - one direction
insereAresta(g,13,29,7);  // green day - 5sos
insereAresta(g,17,30,1);  // linkin park - maroon 5
insereAresta(g,36,5,2);   // arctic monkeys - taylor swift
insereAresta(g,35,6,6);   // oasis - ed sheeran
insereAresta(g,15,41,7);  // red hot - legiao urbana
insereAresta(g,17,43,6);  // linkin park - raimundos
insereAresta(g,14,45,6);  // green day - skank
insereAresta(g,4,22,1);   // shawn mendes - thiaguinho
insereAresta(g,6,20,1);   // ed sheeran - turma do pagode
insereAresta(g,49,19,1);  // bruno mars - turma do pagode
insereAresta(g,10,17,2);  // racionais - linkin park
insereAresta(g,11,36,1);  // gabriel pensador - arctic monkeys
insereAresta(g,12,43,7);  // gabriel pensador - raimundos
insereAresta(g,23,13,1);  // mamonas - green day
insereAresta(g,24,19,1);  // mamonas - pagode
insereAresta(g,23,10,2);  // mamonas - racionais
insereAresta(g,24,49,1);  // mamonas - bruno mars
insereAresta(g,10,6,1);   // racionais - ed sheeran
insereAresta(g,17,20,1);  // linkin park - turma do pagode
insereAresta(g,33,41,1);  // exo - legiao urbana
insereAresta(g,28,43,1);  // txt - raimundos

insereAresta(g,15,54,1);  // red hot - hino santos
insereAresta(g,48,13,3);  // elvis - green day
insereAresta(g,48,5,4);   // elvis - taylor swift


/* HINOS  */
insereAresta(g,52,53,1);  // corinthians - sao paulo
insereAresta(g,52,54,1);  // corinthians - santos
insereAresta(g,53,54,3);  // sao paulo - santos
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
