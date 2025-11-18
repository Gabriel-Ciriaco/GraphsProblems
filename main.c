#include <stdio.h>
#include <stdlib.h>

#include "musicas.h"
#include "grafoLista.h"
#include "grafoMatriz.h"

/* exibe catalogo */
void exibirListaMusicas() {
    printf("\n=========== CATALOGO ===========\n");
    for (int i = 0; i < MAX_MUSICAS; i++) {
        printf("%d - %s\n", i, musicas[i]);
    }
    printf("================================\n");
}

/* menu clean */
void menuPrincipal() {
    printf("\n========================================\n");
    printf("       SISTEMA DE RECOMENDACAO MUSICAL\n");
    printf("========================================\n");

    printf("\nMenu principal:\n");
    printf("----------------------------------------\n");
    printf("1. recomendar musicas\n");
    printf("2. amigo de amigo\n");
    printf("3. verificar caminho\n");
    printf("4. visualizar grafo\n");
    printf("5. listar catalogo\n");
     printf("6. criar playlist de musicas\n");
    printf("0. sair\n");
    printf("----------------------------------------\n");
    printf("opcao: ");
}

int main() {
    int tipo = 0;
    printf("usar grafo lista (1) ou grafo matriz (2)? ");
    if (scanf("%d", &tipo) != 1) {
        printf("entrada invalida\n");
        return 0;
    }

    int opcao = -1;

    if (tipo == 1) {
        GrafoLista* g = criaGrafoLista(MAX_MUSICAS);
        if (g == NULL) {
            printf("erro ao criar grafo lista\n");
            return 0;
        }

        montarGrafoLista(g);

        while (opcao != 0) {
            menuPrincipal();
            if (scanf("%d", &opcao) != 1) {
                printf("entrada invalida\n");
                break;
            }

            if (opcao == 1) {
                exibirListaMusicas();
                int id;
                printf("id da musica: ");
                if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }
                if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }
                recomendarMusicasLista(g, id);
            }
            else if (opcao == 2) {
                exibirListaMusicas();
                int id;
                printf("id da musica: ");
                if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }
                if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }
                recomendarAmigoDeAmigoLista(g, id);
            }
            else if (opcao == 3) {
                exibirListaMusicas();
                int a, b;
                printf("origem: ");
                if (scanf("%d", &a) != 1) { printf("entrada invalida\n"); continue; }
                printf("destino: ");
                if (scanf("%d", &b) != 1) { printf("entrada invalida\n"); continue; }
                if (a < 0 || a >= MAX_MUSICAS || b < 0 || b >= MAX_MUSICAS) {
                    printf("id invalido\n");
                    continue;
                }
                if (verificarCaminhoLista(g, a, b)) {
                    printf("existe caminho\n");
                } else {
                    printf("nao existe caminho\n");
                }
            }
            else if (opcao == 4) {
                imprimeGrafoLista(g);
            }
            else if (opcao == 5) {
                exibirListaMusicas();
             }
            else if (opcao == 6) {
                exibirListaMusicas();
                int ids[3];
                printf("Digite os IDs de 3 musicas para criar a playlist:\n");
                for (int i = 0; i < 3; i++) {
                    printf("Musica %d: ", i + 1);
                    if (scanf("%d", &ids[i]) != 1) {
                        printf("Entrada invalida\n");
                        continue;
                    }
                    if (ids[i] < 0 || ids[i] >= MAX_MUSICAS) {
                        printf("ID invalido\n");
                        i--;
                    }
                }
                criarPlaylistLista(g, ids);
            }
            else if (opcao == 0) {
                printf("saindo...\n");
            }
            else {
                printf("opcao invalida\n");
            }
        }

        destroiGrafoLista(g);
    }
    else if (tipo == 2) {
        GrafoMatriz* g = criaGrafoMatriz(MAX_MUSICAS);
        if (g == NULL) {
            printf("erro ao criar grafo matriz\n");
            return 0;
        }

        montarGrafoMatriz(g);

        while (opcao != 0) {
            menuPrincipal();
            if (scanf("%d", &opcao) != 1) {
                printf("entrada invalida\n");
                break;
            }

            if (opcao == 1) {
                exibirListaMusicas();
                int id;
                printf("id da musica: ");
                if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }
                if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }
                recomendarMusicasMatriz(g, id);
            }
            else if (opcao == 2) {
                exibirListaMusicas();
                int id;
                printf("id da musica: ");
                if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }
                if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }
                recomendarAmigoDeAmigoMatriz(g, id);
            }
            else if (opcao == 3) {
                exibirListaMusicas();
                int a, b;
                printf("origem: ");
                if (scanf("%d", &a) != 1) { printf("entrada invalida\n"); continue; }
                printf("destino: ");
                if (scanf("%d", &b) != 1) { printf("entrada invalida\n"); continue; }
                if (a < 0 || a >= MAX_MUSICAS || b < 0 || b >= MAX_MUSICAS) {
                    printf("id invalido\n");
                    continue;
                }
                if (verificarCaminhoMatriz(g, a, b)) {
                    printf("existe caminho\n");
                } else {
                    printf("nao existe caminho\n");
                }
            }
            else if (opcao == 4) {
                imprimeGrafoMatriz(g);
            }
            else if (opcao == 5) {
                exibirListaMusicas();
            }

            else if (opcao == 6) {
                exibirListaMusicas();
                int ids[3];
                printf("Digite os IDs de 3 musicas para criar a playlist:\n");
                for (int i = 0; i < 3; i++) {
                    printf("Musica %d: ", i + 1);
                    if (scanf("%d", &ids[i]) != 1) {
                        printf("Entrada invalida\n");
                        continue;
                    }
                    if (ids[i] < 0 || ids[i] >= MAX_MUSICAS) {
                        printf("ID invalido\n");
                        i--;
                    }
                }
                criarPlaylistMatriz(g, ids);
            }
            else if (opcao == 0) {
                printf("saindo...\n");
            }
            else {
                printf("opcao invalida\n");
            }
        }

        destroiGrafoMatriz(g);
    }
    else {
        printf("opcao invalida, execute novamente e escolha 1 ou 2\n");
    }

    return 0;
}

