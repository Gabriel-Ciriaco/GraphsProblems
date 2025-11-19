#include "musicas.h"
#include "structures/graphs.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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
    printf("1.  recomendar musicas\n"); //recomendacao direta
    printf("2.  amigo de amigo\n");// amigo de amigo
    printf("3.  verificar caminho\n"); // dfs
    printf("4.  visualizar grafo\n");
    printf("5.  listar catalogo\n");
    printf("6.  criar playlist de musicas\n"); // recomendacao direta
    printf("7.  menor caminho entre musicas\n"); // dijkstra
    printf("8.  mapa de similaridade\n"); // prim
    printf("9.  explorar subgenero\n"); //bfs
    printf("10. identificar generos musicais\n"); // componentes conexos
    printf("\n0. sair\n");
    printf("----------------------------------------\n");
    printf("opcao: ");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int tipo = 0;

    printf("usar grafo lista (1) ou grafo matriz (2)? ");

    if (scanf("%d", &tipo) != 1)
    {
        printf("entrada invalida\n");
        return 0;
    }

    Grafo* g = criaGrafo(tipo, MAX_MUSICAS);

    if (g == NULL)
    {
        printf("erro ao criar grafo lista\n");
        return 0;
    }

    int opcao = -1;

    montarGrafo(g);

    while (opcao != 0)
    {
        menuPrincipal();

        if (scanf("%d", &opcao) != 1)
        {
            printf("entrada invalida\n");
            break;
        }

        if (opcao == 1)
        {
            exibirListaMusicas();

            int id;

            printf("id da musica: ");

            if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }

            if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }

            recomendarMusicas(g, id);
        }

        else if (opcao == 2)
        {
            exibirListaMusicas();

            int id;

            printf("id da musica: ");

            if (scanf("%d", &id) != 1) { printf("entrada invalida\n"); continue; }

            if (id < 0 || id >= MAX_MUSICAS) { printf("id invalido\n"); continue; }

            recomendarAmigoDeAmigo(g, id);
        }

        else if (opcao == 3)
        {
            exibirListaMusicas();

            int a, b;

            printf("origem: ");

            if (scanf("%d", &a) != 1) { printf("entrada invalida\n"); continue; }

            printf("destino: ");

            if (scanf("%d", &b) != 1) { printf("entrada invalida\n"); continue; }

            if (a < 0 || a >= MAX_MUSICAS || b < 0 || b >= MAX_MUSICAS)
            {
                printf("id invalido\n");
                continue;
            }

            if (verificarCaminho(g, a, b))
            {
                printf("\n\nexiste caminho\n");
            }
            else
            {
                printf("\n\nnao existe caminho\n");
            }
        }

        else if (opcao == 4)
        {
            imprimeGrafo(g);
        }

        else if (opcao == 5)
        {
            exibirListaMusicas();
        }

        else if (opcao == 6)
        {
            exibirListaMusicas();

            int ids[NUM_MUSICAS_BASE_PLAYLIST];

            printf("Digite os IDs de %d musicas para criar a playlist:\n",
                   NUM_MUSICAS_BASE_PLAYLIST);

            for (int i = 0; i < NUM_MUSICAS_BASE_PLAYLIST; i++)
            {
                printf("Musica %d: ", i + 1);

                if (scanf("%d", &ids[i]) != 1)
                {
                    printf("Entrada invalida\n");
                    continue;
                }

                if (ids[i] < 0 || ids[i] >= MAX_MUSICAS)
                {
                    printf("ID invalido\n");
                    i--;
                }
            }

            criarPlaylist(g, ids);
        }
        else if (opcao == 7)
        {
            exibirListaMusicas();
            int origem;
            printf("Musica de origem: ");
            if (scanf("%d", &origem) != 1) { printf("entrada invalida\n"); continue; }

            int* caminho = dijkstra(g, origem);

            if (!caminho)
            {
                printf("\nCaminho não encontrado.\n");
                return 1;
            }

            for (int i = 0; i < g->numVertices; i++)
                if (caminho[i] != INT_MAX)
                    printf("%s -> %d\n", musicas[i], caminho[i]);

            free(caminho);
        }
        else if (opcao == 8)
        {
            int origem;
            exibirListaMusicas();
            printf("Musica inicial para gerar o mapa: ");
            if (scanf("%d", &origem) != 1) { printf("entrada invalida\n"); continue; }

            int* mst = prim(g);

            printf("\nSIGNIFICADO\n");

            printf("Este mapa mostra como as músicas se conectam pela similaridade.\n");
            printf("Quando aparece [A] <---> B, significa que B é a música mais parecida com A naquele ponto.\n");
            printf("No fim, o mapa revela grupos naturais de músicas com estilo, ritmo ou vibe parecidos.\n");


            printf("\n====== MAPA GERADO PELO PRIM ======\n");
            for (int i = 0; i < g->numVertices; i++)
            {
                if (musicas[mst[i]] && i != -1)
                    printf("  • %-30s  <--->  %s\n", musicas[i], musicas[mst[i]]);
            }

            printf("=========================================\n");

            free(mst);
        }
        else if (opcao == 9)
        {
            exibirListaMusicas();
            int origem;
            printf("Explorar subgenero a partir de: ");
            if (scanf("%d", &origem) != 1) { printf("entrada invalida\n"); continue; }

            int visitados[MAX_MUSICAS] = {0};

            buscaLargura(g, origem, visitados);

            printf("\nResultado Musicas:\n");
            for (int i = 0; i < MAX_MUSICAS; i++)
                if (visitados[i])
                    printf("%s\n", musicas[i]);
        }
        else if (opcao == 10)
        {
            encontraComponentes(g);
        }
        else if (opcao == 0)
        {
            printf("saindo...\n");
        }

        else
        {
            printf("opcao invalida\n");
        }
    }

    destroiGrafo(g);

    return 0;
}
