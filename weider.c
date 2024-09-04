#include <stdio.h>
#include <stdlib.h>
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
    int notaCadastrada;
};

int main()
{
    struct aluno alunos[50];
    int qtd=0, i, opcao, flag, matricula;
    float media;
    do{
        system("clear");
        printf("+-------------------------------------------+\n");
        printf("|            SISTEMA ACADEMICO BSI          |\n");
        printf("+-------------------------------------------+\n\n\n");
        printf("+-----------------MENU DE OPÇÕES------------+\n");
        printf("|                                           |\n");
        printf("| 1 - Cadastrar aluno                       |\n");
        printf("| 2 - Lançar notas                          |\n");
        printf("| 3 - Exibir todos alunos                   |\n");
        printf("| 4 - Exibir alunos aprovados               |\n");
        printf("| 5 - Exibir alunos reprovados              |\n");
        printf("| 6 - Alterar notas                         |\n");
        printf("| 9 - Sair                                  |\n");
        printf("|                                           |\n");
        printf("+-------------------------------------------+\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            CADASTRAR ALUNO                |\n");
                printf("+-------------------------------------------+\n\n\n");
                printf("Matrícula: %d\n", qtd+1);
                alunos[qtd].matricula = qtd+1;
                printf("Nome do aluno: ");
                scanf(" %[^\n]s", &alunos[qtd].nome);
                alunos[qtd].notaCadastrada=0;
                qtd++;
                break;
            case 2:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            LANÇAR NOTAS                   |\n");
                printf("+-------------------------------------------+\n\n");
                for(i=0;i<qtd;i++){
                    if(alunos[i].notaCadastrada == 0){
                        printf("\nMatrícula: %d\n", alunos[i].matricula);
                        printf("Nome do aluno: %s\n", alunos[i].nome);
                        printf("Nota 1: ");
                        scanf("%f", &alunos[i].n1);
                        printf("Nota 2: ");
                        scanf("%f", &alunos[i].n2);
                        printf("Nota 3: ");
                        scanf("%f", &alunos[i].n3);
                        alunos[i].notaCadastrada=1;
                    }
                }
                break;
            case 3:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            EXIBIR TODOS ALUNOS            |\n");
                printf("+-------------------------------------------+\n\n");
                printf("+------+------------------------------+\n");
                printf("|MATRIC|NOME DO ALUNO                 |\n");
                printf("+------+------------------------------+\n");
                for(i=0;i<qtd;i++){
                    printf("|%6d|", alunos[i].matricula);
                    printf("%-30s|\n", alunos[i].nome);
                }
                printf("+------+------------------------------+\n");
                scanf("%d", &flag);
                break;
            case 4:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            EXIBIR TODOS ALUNOS APROVADOS  |\n");
                printf("+-------------------------------------------+\n\n");
                printf("+------+------------------------------+----+\n");
                printf("|MATRIC|NOME DO ALUNO                 |NOTA|\n");
                printf("+------+------------------------------+----+\n");
                for(i=0;i<qtd;i++){
                    media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3;
                    if (media >= 6) {
                        printf("|%6d|", alunos[i].matricula);
                        printf("%-30s|", alunos[i].nome);
                        printf("%04.1f|\n", media);
                    }

                }
                printf("+------+------------------------------+----+\n");
                scanf("%d", &flag);
                break;
            case 5:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            EXIBIR TODOS ALUNOS REPROVADOS |\n");
                printf("+-------------------------------------------+\n\n");
                printf("+------+------------------------------+----+\n");
                printf("|MATRIC|NOME DO ALUNO                 |NOTA|\n");
                printf("+------+------------------------------+----+\n");
                for(i=0;i<qtd;i++){
                    media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3;
                    if (media < 6) {
                        printf("|%6d|", alunos[i].matricula);
                        printf("%-30s|", alunos[i].nome);
                        printf("%04.1f|\n", media);
                    }

                }
                printf("+------+------------------------------+----+\n");
                scanf("%d", &flag);
                break;
            case 6:
                system("clear");
                printf("+-------------------------------------------+\n");
                printf("|            ALTERAR NOTAS                  |\n");
                printf("+-------------------------------------------+\n\n");
                printf("Matrícula: ");
                scanf("%d", &matricula);
                for(i=0;i<qtd;i++){
                    if(alunos[i].matricula == matricula){
                        printf("Nome do aluno: %s\n", alunos[i].nome);
                        printf("Nota 1: ");
                        scanf("%f", &alunos[i].n1);
                        printf("Nota 2: ");
                        scanf("%f", &alunos[i].n2);
                        printf("Nota 3: ");
                        scanf("%f", &alunos[i].n3);
                    }
                }
                break;
        }
    } while(opcao != 9);


}
