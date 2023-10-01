#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "agenda.c"

int main()
{
    int opcoes;
    struct agenda contatos[100];

    do{
        printf("||----------------------------------------------------|| \n");
        printf("||--------------------- Agenda -----------------------|| \n");
        printf("||----------------------------------------------------|| \n\n"); 
        printf("1-Cadastro \n");
        printf("2-Status da Agenda \n");
        printf("3-Pesquisar Contatos \n");
        printf("4-Alterar Contatos \n");
        printf("5-Excluir Contatos \n");
        printf("6-Exibir Contatos \n");
        printf("0-sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcoes);

        switch(opcoes)
        {
            case 1:
                cadastro(contatos);
                break;
            case 2:
                statusagenda(contatos);
                break;
            case 3:
                pesquisarcontatos(contatos);
                break;
            case 4:
                alterarcontatos(contatos);
                break;
            case 5:
                excluircontatos(contatos);
                break;
            case 6:
                exibircontatos(contatos);
                break;
            case 0:
                opcoes = 0;
                printf("||--------------------------------------------------------------|| \n");
                printf("||-------------------- Programa Encerrado ----------------------|| \n");
                printf("||--------------------------------------------------------------|| \n\n"); 
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
        }
    }
    while(opcoes != 0);


    return 0;

}