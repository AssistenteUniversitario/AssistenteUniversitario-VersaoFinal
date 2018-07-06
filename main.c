#include <stdlib.h>
#include <stdio.h>
#include "assistUniv.h"

int main()
{
    mkdir("Assistente Universitario");
    mkdir("Assistente Universitario\\Data");
    Aluno *alunos = NULL;
    alunos = carregaAluno(alunos);
    int opcao;
    do
    {
        system("cls");
        int cont = 0;
        int alunoEscolhido = 0;
        int i;
        Aluno *aux = NULL;
        aux = alunos;
        printf("\n\n\t\t\tBem vindo. Escolha um aluno para acessar e/ou cadastrar suas informacoes:");
        if (aux == NULL)
        {
            printf("\nNao ha alunos cadastrados.");
            printf("\n\n1. Cadastrar novo aluno");
            printf("\n0. Sair");
        }else{
            printf("\n\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::ASSISTENTE::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::UNIVERSITARIO:::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");

            while (aux != NULL)
            {
                cont++;
                printf("\n\t%d. %s", cont, aux->nome);
                aux = aux->prox;
            }
            printf("\n\n\n\t-----------------------------------------");
            printf("\n\n\t%d. Cadastrar novo aluno", cont + 1);
            printf("\n\t%d. Remover aluno", cont + 2);
            printf("\n\t0. Sair");
        }
        printf("\n\n\tDigite o numero correspondente: ");
        scanf("%d", &opcao);
        while (opcao < 0 || opcao > cont+2)
        {
            printf("\n\t\t\tDigite um numero validdo: ");
            scanf("%d", &opcao);
        }
        if (opcao == cont+1)
        {
            alunos = setAluno(alunos);
        }else{
            if (opcao > 0 && opcao < cont+1)
            {
                aux = alunos;
                for (i = 1; i <= opcao-1; i++)
                {
                    aux = aux->prox;
                }
                (*aux) = menuAluno(*aux);
            }else{
                if (opcao != 0)
                {
                    aux = alunos;
                    printf("\n\nDigite qual aluno deseja remover: ");
                    scanf("%d", &alunoEscolhido);
                    alunos = removeAluno(alunos, alunoEscolhido);
                }
            }
        }
    }while (opcao != 0);
    printf("\n\t\t\tAte Logo ;)\n\n");
    gravaAluno(alunos);
}
