#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livraria {
    int codigo;
    char titulo[30];
    char autor[30];
    char estilo[30];
    float preco;
};

int main() {
    struct livraria vetLivros[50];
    int i, qtdLivros = 0, opcao, flag;
    char searchAutor[30], searchEstilo[30], searchTitulo[30];
    float media;

    do {
        system("clear");
        printf("-------------------------\n");
        printf("|---Livraria do Lucas---|\n");
        printf("-------------------------\n");
        printf("------Menu de opções-----\n");
        printf("1 - Incluir livro na biblioteca\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Procure um livro pelo autor\n");
        printf("4 - Procure um livro pelo título\n");
        printf("5 - Procure um livro pelo estilo\n");
        printf("6 - Média dos preços dos livros da livraria do Lucas\n");
        printf("9 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                printf("Código do livro: %d\n", qtdLivros + 1);
                vetLivros[qtdLivros].codigo = qtdLivros + 1;
                printf("Informe o nome do livro: ");
                scanf("%s", vetLivros[qtdLivros].titulo);
                printf("Informe o autor do livro: ");
                scanf("%s", vetLivros[qtdLivros].autor);
                printf("Informe o estilo do livro: ");
                scanf("%s", vetLivros[qtdLivros].estilo);
                printf("Informe o preço do livro: ");
                scanf("%f", &vetLivros[qtdLivros].preco);
                qtdLivros++;
                break;

            case 2:
                system("clear");
                printf("---Todos os livros da livraria do Lucas---\n");
                for (i = 0; i < qtdLivros; i++) {
                    printf("Código: %d\n", vetLivros[i].codigo);
                    printf("Título: %s\n", vetLivros[i].titulo);
                    printf("Autor: %s\n", vetLivros[i].autor);
                    printf("Estilo: %s\n", vetLivros[i].estilo);
                    printf("Preço: %.2f\n", vetLivros[i].preco);
                    printf("--------------------------------------\n");
                }
                scanf("%d", &flag);
                break;

            case 3:
                system("clear");
                printf("Digite o nome do autor: ");
                scanf("%s", searchAutor);
                flag = 0;
                for (i = 0; i < qtdLivros; i++) {
                    if (strcmp(vetLivros[i].autor, searchAutor) == 0) {
                        flag = 1;
                        printf("Código: %d\n", vetLivros[i].codigo);
                        printf("Título: %s\n", vetLivros[i].titulo);
                        printf("Autor: %s\n", vetLivros[i].autor);
                        printf("Estilo: %s\n", vetLivros[i].estilo);
                        printf("Preço: %.2f\n", vetLivros[i].preco);
                        printf("--------------------------------------\n");
                    }
                }
                if (!flag) {
                    printf("Nenhum livro encontrado com o autor: %s\n", searchAutor);
                }
                scanf("%d", &flag);
                break;

            case 4:
                system("clear");
                printf("Digite o nome do título: ");
                scanf("%s", searchTitulo);
                flag = 0;
                for (i = 0; i < qtdLivros; i++) {
                    if (strcmp(vetLivros[i].titulo, searchTitulo) == 0) {
                        flag = 1;
                        printf("Código: %d\n", vetLivros[i].codigo);
                        printf("Título: %s\n", vetLivros[i].titulo);
                        printf("Autor: %s\n", vetLivros[i].autor);
                        printf("Estilo: %s\n", vetLivros[i].estilo);
                        printf("Preço: %.2f\n", vetLivros[i].preco);
                        printf("--------------------------------------\n");
                    }
                }
                if (!flag) {
                    printf("Nenhum livro encontrado com o título: %s\n", searchTitulo);
                }
                scanf("%d", &flag);
                break;

            case 5:
                system("clear");
                printf("Digite o nome do estilo: ");
                scanf("%s", searchEstilo);
                flag = 0;
                for (i = 0; i < qtdLivros; i++) {
                    if (strcmp(vetLivros[i].estilo, searchEstilo) == 0) {
                        flag = 1;
                        printf("Código: %d\n", vetLivros[i].codigo);
                        printf("Título: %s\n", vetLivros[i].titulo);
                        printf("Autor: %s\n", vetLivros[i].autor);
                        printf("Estilo: %s\n", vetLivros[i].estilo);
                        printf("Preço: %.2f\n", vetLivros[i].preco);
                        printf("--------------------------------------\n");
                    }
                }
                if (!flag) {
                    printf("Nenhum livro encontrado com o estilo: %s\n", searchEstilo);
                }
                scanf("%d", &flag);
                break;

            case 6:
                system("clear");
                printf("-----------------------------------\n");
                printf("|---Média dos preços dos livros---|\n");
                printf("-----------------------------------\n");
                if (qtdLivros > 0) {
                    float precoTotal = 0;
                    for (i = 0; i < qtdLivros; i++) {
                        precoTotal += vetLivros[i].preco;
                    }
                    media = precoTotal / qtdLivros;
                    printf("Média dos preços: %.2f Reais\n", media);
                } else {
                    printf("Nenhum livro cadastrado.\n");
                }
                scanf("%d", &flag);
                break;
        }
    } while (opcao != 9);

    return 0;
}
