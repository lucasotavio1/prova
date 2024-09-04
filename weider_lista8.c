#include <stdio.h>
#include <stdlib.h>

struct ContaBancaria {
    unsigned int numero;
    char nome[30];
    unsigned int tipo;
    float saldo;
};

int main() {
    struct ContaBancaria contas[50];
    int qtdContas = 0, opcao, conta, flag, i;
    float valor, mCorrente, mPoupanca;

    do {
        system("clear");
        printf("Menu do sistema bancário - BANCO X\n");
        printf("==== == ======= ======== = ===== =\n\n");
        printf("1 - Criar uma nova conta\n");
        printf("2 - Fazer um depósito\n");
        printf("3 - Fazer um saque\n");
        printf("4 - Saldo de um cliente\n");
        printf("5 - Montante total de R$ do banco\n");
        printf("9 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                printf("CRIAÇÃO DE UMA CONTA\n");
                printf("======= == === =====\n\n");
                printf("Número da conta: %d\n", qtdContas + 1);
                contas[qtdContas].numero = qtdContas + 1;
                printf("Nome do cliente: ");
                scanf(" %s", contas[qtdContas].nome);
                printf("Tipo de conta (1-Corrente / 2-Poupança): ");
                scanf("%d", &contas[qtdContas].tipo);
                contas[qtdContas].saldo = 0;
                qtdContas++;
                break;

            case 2:
                system("clear");
                flag = 0;
                printf("FAZER UM DEPÓSITO\n");
                printf("===== == ========\n\n");
                printf("Informe a conta a depositar: ");
                scanf("%d", &conta);

                for (i = 0; i < qtdContas; i++) {
                    if (conta == contas[i].numero) {
                        flag = 1;
                        printf("Cliente: %s\n", contas[i].nome);
                        printf("Valor a depositar: ");
                        scanf("%f", &valor);
                        contas[i].saldo += valor;
                        printf("Depósito realizado com sucesso!\n\n");
                    }
                }
                if (flag == 0) {
                    printf("Conta não encontrada!\n");
                }
                scanf("%d", &flag);
                break;

            case 3:
                system("clear");
                flag = 0;
                printf("FAZER UM SAQUE\n");
                printf("===== == =====\n\n");
                printf("Informe a conta a sacar: ");
                scanf("%d", &conta);

                for (i = 0; i < qtdContas; i++) {
                    if (conta == contas[i].numero) {
                        flag = 1;
                        printf("Cliente: %s\n", contas[i].nome);
                        printf("Valor a sacar: ");
                        scanf("%f", &valor);

                        if (contas[i].saldo - valor < 0) {
                            printf("Saldo insuficiente!\n\n");
                        } else {
                            contas[i].saldo -= valor;
                            printf("Saque realizado com sucesso!\n\n");
                        }
                    }
                }
                if (flag == 0) {
                    printf("Conta não encontrada!\n");
                }
                scanf("%d", &flag);
                break;

            case 4:
                system("clear");
                flag = 0;
                printf("EXIBIR O SALDO DE UM CLIENTE\n");
                printf("====== = ===== == == =======\n\n");
                printf("Informe a conta: ");
                scanf("%d", &conta);

                for (i = 0; i < qtdContas; i++) {
                    if (conta == contas[i].numero) {
                        flag = 1;
                        printf("Cliente: %s\n", contas[i].nome);
                        if (contas[i].tipo == 1) {
                            printf("Tipo de conta: Corrente\n");
                        } else {
                            printf("Tipo de conta: Poupança\n");
                        }
                        printf("Saldo na conta: %.2f\n\n", contas[i].saldo);
                        scanf("%d", &flag);
                    }
                }
                break;

            case 5:
                system("clear");
                printf("MONTANTE DE DINHEIRO CONTIDO NO BANCO\n");
                printf("======== == ======== ======= == =====\n\n");
                mCorrente = mPoupanca = 0;

                for (i = 0; i < qtdContas; i++) {
                    if (contas[i].tipo == 1) {
                        mCorrente += contas[i].saldo;
                    } else if (contas[i].tipo == 2) {
                        mPoupanca += contas[i].saldo;
                    }
                }
                printf("Valor total em contas corrente: %.2f\n", mCorrente);
                printf("Valor total em contas poupança: %.2f\n\n", mPoupanca);
                scanf("%d", &flag);
                break;
        }
    } while (opcao != 9);

    return 0;
}
