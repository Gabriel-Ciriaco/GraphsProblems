#ifndef MUSICAS_H
#define MUSICAS_H

#include "structures/adjacency_list/grafoLista.h"
#include "structures/adjacency_matrix/grafoMatriz.h"

#include <stdbool.h>

#define MAX_MUSICAS 52

extern char* musicas[MAX_MUSICAS];

/* lista */
void montarGrafoLista(GrafoLista* g);
void recomendarMusicasLista(GrafoLista* g, int id);
void recomendarAmigoDeAmigoLista(GrafoLista* g, int id);
bool verificarCaminhoLista(GrafoLista* g, int origem, int destino);
void criarPlaylistLista(GrafoLista* g, int musicasIds[3]);




/* matriz */
void montarGrafoMatriz(GrafoMatriz* g);
void recomendarMusicasMatriz(GrafoMatriz* g, int id);
void recomendarAmigoDeAmigoMatriz(GrafoMatriz* g, int id);
bool verificarCaminhoMatriz(GrafoMatriz* g, int origem, int destino);
void criarPlaylistMatriz(GrafoMatriz* g, int musicasIds[3]);

#endif
