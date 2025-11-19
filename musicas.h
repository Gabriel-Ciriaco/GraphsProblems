#ifndef MUSICAS_H
#define MUSICAS_H

#include "structures/graphs.h"

#include <stdbool.h>

#define MAX_MUSICAS 55
#define NUM_MUSICAS_BASE_PLAYLIST 3
#define MUSICA_NAO_RECOMENDADA -1

extern char* musicas[MAX_MUSICAS];

void montarGrafo(Grafo* g);
void recomendarMusicas(Grafo* g, int id);
void recomendarAmigoDeAmigo(Grafo* g, int id);
void criarPlaylist(Grafo* g, int musicasIds[NUM_MUSICAS_BASE_PLAYLIST]);

#endif
