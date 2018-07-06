#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "assistUniv.h"


Aluno *setAluno(Aluno *aluno)
{
    if (aluno == NULL)
    {
        aluno = (Aluno*) malloc(sizeof(Aluno));
        aluno->prox = NULL;
        system("cls");
        printf("Digite o nome do aluno:\n");
        fflush(stdin);
        scanf("%[^\n]s", &aluno->nome);
        fflush(stdin);
        printf("\nDigite o numero da matricula:\n");
        scanf("%d", &aluno->matricula);
        aluno->faculdade = setFaculdade();
        return aluno;
    }else{
        Aluno *novo;
        novo = (Aluno*) malloc(sizeof(Aluno));
        novo->prox = NULL;
        system("cls");
        printf("Digite o nome do aluno:\n");
        fflush(stdin);
        scanf("%[^\n]s", &novo->nome);
        fflush(stdin);
        printf("\nDigite o numero da matricula:\n");
        scanf("%d", &novo->matricula);
        novo->faculdade = setFaculdade();
        novo->prox = aluno;
        aluno = novo;
        return aluno;
    }
}

Aluno editAluno (Aluno aluno)
{
    system("cls");
    printf("Digite o nome do aluno:\n");
    fflush(stdin);
    scanf("%[^\n]s", &aluno.nome);
    fflush(stdin);
    printf("\nDigite o numero da matricula:\n");
    scanf("%d", &aluno.matricula);
    aluno.faculdade = editFaculdade(aluno.faculdade);
    return aluno;
}
Aluno menuAluno (Aluno aluno)
{
    int opcao;
    do
    {
        system("cls");
        imprimeAluno(aluno);
        printf("\n\n");
        printf("Escolha sua opcao:\n\n");
        printf("1. Editar aluno\n");
        printf("2. Menu de periodos\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                aluno = editAluno(aluno);
                break;
            case 2:
                aluno.faculdade.curso.periodos = NULL;
                aluno.faculdade.curso.periodos = carregaPeriodo(&aluno);
                aluno.faculdade.curso.periodos = menuPeriodos(aluno.faculdade.curso.periodos, &aluno);
                gravaPeriodo(&aluno);
                aluno.faculdade.curso.periodos = esvaziaPeriodo(aluno.faculdade.curso.periodos);
                break;
            case 0:
                break;
            default:
                printf("Digite opcao valida: ");
                scanf("%d", &opcao);
                break;
        }
        imprimeAlunoTexto(aluno);
    }while (opcao != 0);
    return aluno;
}

Aluno *removeAluno (Aluno *aluno, int alunoEscolhido)
{
    if (aluno->prox != NULL)
    {
        Aluno *aux = aluno, *auxAntes = aluno;
        int i = 0;
        for (i = 1; i < alunoEscolhido-1; i++)
        {
            auxAntes = aux;
            aux = aux->prox;
        }
        auxAntes->prox = aux->prox;
        if (aux == aluno)
        {
            aluno = aluno->prox;
        }
        free(aux);
        return aluno;
    }else{
        free(aluno);
        return NULL;
    }
}
void imprimeAluno(Aluno aluno)
{
    system("cls");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d", aluno.matricula);
    imprimeFaculdade(aluno.faculdade);
}

void imprimeAlunoTexto(Aluno aluno)
{
    FILE *arq;
    char buffer[150];
    sprintf(buffer, "Assistente Universitario\\%s", aluno.nome);
    mkdir(buffer);
    sprintf(buffer, "Assistente Universitario\\%s\\%s.txt", aluno.nome, aluno.nome);
    arq = fopen(buffer, "w");
    system("cls");
    fprintf(arq, "Nome: %s\n", aluno.nome);
    fprintf(arq, "Matricula: %d", aluno.matricula);
    imprimeFaculdadeTexto(aluno.faculdade, arq);
    fclose(arq);
}

void gravaAluno(Aluno *aluno)
{
    FILE *arquivo;
    int cont = 0;
    char buffer[150];
    Aluno *aux = aluno;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer, "Assistente Universitario\\Data\\%d", cont);
        arquivo = fopen(buffer, "wb");
        fwrite(aux, sizeof(Aluno), 1, arquivo);
        fclose(arquivo);
        aux = aux->prox;
    }
    arquivo = fopen("Assistente Universitario\\Data\\Num.txt", "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

Aluno *carregaAluno (Aluno *aluno)
{
    FILE *arquivo;
    Aluno *aux = aluno;
    char buffer[150];
    int cont = 0, i;
    arquivo = fopen("Assistente Universitario\\Data\\Num.txt", "r");
    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &cont);
    }else{
        cont = 0;
        return NULL;
    }
    fclose(arquivo);
    for (i = cont; i >= 1; i--)
    {
        aux = NULL;
        sprintf(buffer, "Assistente Universitario\\Data\\%d", i);
        arquivo = fopen(buffer, "rb");
        if (arquivo != NULL)
        {
            aux = (Aluno*) malloc(sizeof(Aluno));
            fread(aux, sizeof(Aluno), 1, arquivo);
            /*aux->faculdade.curso.periodos = NULL;
            aux->faculdade.curso.periodos = carregaPeriodo(aux);*/
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer);
        aux->prox = aluno;
        aluno = aux;
    }
    return aluno;
}
