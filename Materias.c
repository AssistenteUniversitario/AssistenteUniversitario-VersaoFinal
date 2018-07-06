#include <stdlib.h>
#include <stdio.h>
#include "assistUniv.h"



ListaMaterias *setMaterias (ListaMaterias *materias)
{
    system("cls");
    if (materias == NULL)
    {
        materias = (ListaMaterias*) malloc(sizeof(ListaMaterias));
        materias->prox = NULL;
        printf("Digite o nome da materia:\n");
        fflush(stdin);
        scanf("%s[^\n]", &materias->nome);
        fflush(stdin);
        printf("\nDigite o numero da materia:\n");
        scanf("%d", &materias->numero);
        printf("\nDigite a carga horaria da materia:\n");
        scanf("%d", &materias->cargaHoraria);
        printf("\nDigite a ementa da materia:\n");
        fflush(stdin);
        scanf("%[^\n]s", materias->ementa);
        fflush(stdin);
        materias->aulas = NULL;
        materias->avaliacoes = NULL;
        materias->trabalhos = NULL;
        materias->quandidadeAulas = setQuantidadeAulas(materias->aulas);
        materias->quantidadeFaltas = setQuantidadeFaltas(materias->aulas);
        materias->prox = NULL;
        return materias;
    }else{
        ListaMaterias *novo;
        novo = malloc(sizeof(ListaMaterias));
        novo->prox = NULL;
        printf("Digite o nome da materia:\n");
        fflush(stdin);
        scanf("%s[^\n]", &novo->nome);
        fflush(stdin);
        printf("\nDigite o numero da materia:\n");
        scanf("%d", &novo->numero);
        printf("\nDigite a carga horaria da materia:\n");
        scanf("%d", &novo->cargaHoraria);
        printf("\nDigite a ementa da materia:\n");
        fflush(stdin);
        scanf("%[^\n]s", novo->ementa);
        fflush(stdin);
        novo->aulas = NULL;
        novo->avaliacoes = NULL;
        novo->trabalhos = NULL;
        novo->quandidadeAulas = setQuantidadeAulas(novo->aulas);
        novo->quantidadeFaltas = setQuantidadeFaltas(novo->aulas);
        novo->prox = materias;
        materias = novo;
        return materias;
    }
}

ListaMaterias editMateria (ListaMaterias materia)
{
    printf("Digite o nome da materia:\n");
    fflush(stdin);
    scanf("%s[^\n]", &materia.nome);
    fflush(stdin);
    printf("\nDigite o numero da materia:\n");
    scanf("%d", &materia.numero);
    printf("\nDigite a carga horaria da materia:n");
    scanf("%d", &materia.cargaHoraria);
    printf("\nDigite a ementa da materia:\n");
    fflush(stdin);
    scanf("%[^\n]s", materia.ementa);
    fflush(stdin);
    return materia;
}

ListaMaterias *removeMateria (ListaMaterias *materia, int numMateria)
{
    if (materia->prox != NULL)
    {
        ListaMaterias *aux = materia, *auxAntes = materia;
        while (aux->numero != numMateria)
        {
            auxAntes = aux;
            aux = aux->prox;
        }
        auxAntes->prox = aux->prox;
        if (aux == materia)
        {
            materia = materia->prox;
        }
        free(aux);
        return materia;
    }else{
        free(materia);
        return NULL;
    }
}

ListaMaterias *esvaziaMateria (ListaMaterias *materia)
{
    ListaMaterias *aux;
    aux = materia;
    while (aux != NULL)
    {
        aux->aulas = esvaziaAulas(materia->aulas);
        aux->avaliacoes = esvaziaAvaliacoes(materia->avaliacoes);
        aux->trabalhos = esvaziaTrabalho(materia->trabalhos);
        aux = materia->prox;
        free(materia);
        materia = aux;
    }
    return materia;
}

ListaMaterias *menuMaterias (ListaMaterias *materias)
{
    int opcao;
    ListaMaterias *aux = NULL;
    do
    {
        system("cls");
        int materiaEscolhida = 0, achou = 0;
        imprimeMaterias(materias);
        printf("\n\nEscolha sua opcao\n");
        printf("1. Cadastrar nova materia\n");
        printf("2. Editar materia\n");
        printf("3. Menu de Avaliacoes\n");
        printf("4. Menu Trabalhos/Projetos\n");
        printf("5. Menu de Aulas\n");
        printf("6. Remove materia\n");
        printf("0. Voltar\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                materias = setMaterias(materias);
                break;
            case 2:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja editar: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux ->numero == materiaEscolhida)
                    {
                        (*aux) = editMateria(*aux);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("Materia nao encontrada\n\n");
                    system("pause");
                }else{
                    printf("Materia editada\n\n");
                    system("pause");
                }
                break;
            case 3:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver as avaliacoes: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->avaliacoes = menuAvaliacoes(aux->avaliacoes);
                        achou = 1;
                        //break;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 4:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver os trabalhos/projetos: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->trabalhos = menuTrabalhos(aux->trabalhos);
                        achou = 1;
                        //break;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 5:

                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja ver as aulas: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        aux->aulas = menuAulas(aux->aulas);
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 0)
                {
                    printf("\nMateria nao encontrado\n\n");
                    system("pause");
                }
                break;
            case 6:
                aux = materias;
                system("cls");
                printf("Digite o numero da materia que deseja remover: ");
                scanf("%d", &materiaEscolhida);
                while (aux != NULL)
                {
                    if (aux->numero == materiaEscolhida)
                    {
                        achou = 1;
                    }
                    aux = aux->prox;
                }
                if (achou == 1)
                {
                    materias = removeMateria(materias, materiaEscolhida);
                }
                if (achou == 0)
                {
                    printf("Materia nao encontrada\n\n");
                    system("pause");
                }else{
                    printf("Materia removida\n\n");
                    system("pause");
                }
                break;
            case 0:
                break;
            default:
                printf("\n\nDigite uma opcao valida\n\n");
                system("pause");
                break;
        }
    }while (opcao != 0);
    return materias;
}

void imprimeMaterias(ListaMaterias *materia)
{
    if (materia != NULL)
    {
        ListaMaterias *aux = materia;
        while (aux != NULL)
        {
            materia->quandidadeAulas = setQuantidadeAulas(materia->aulas);
            materia->quantidadeFaltas = setQuantidadeFaltas(materia->aulas);
            printf("\nMateria: %s", aux->nome);
            printf("\nNumero da materia: %d", aux->numero);
            printf("\nCarga Horaria: %d", aux->cargaHoraria);
            printf("\nQuantidade de aulas: %d", aux->quandidadeAulas);
            printf("\nQuantidade de faltas: %d", aux->quantidadeFaltas);
            printf("\nEmenta: %s", aux->ementa);
            printf("\n\n\n");
            aux = aux->prox;
        }
    }else{
        printf("\nNao ha materias cadastradas.");
    }
}

void imprimeMateriasTexto(ListaMaterias *materia, PilhaPeriodos *periodo, Aluno *aluno)
{
    FILE *arq;
    char buffer[150];
    if (materia != NULL)
    {
        ListaMaterias *aux;
        aux = materia;
        while (aux != NULL)
        {
            sprintf(buffer, "Assistente Universitario\\%s\\Periodo %d",
                     aluno->nome, periodo->numero);
            mkdir (buffer);
            sprintf(buffer, "Assistente Universitario\\%s\\Periodo %d\\%s.txt",
                     aluno->nome, periodo->numero, aux->nome);
            arq = fopen(buffer, "w");
            materia->quandidadeAulas = setQuantidadeAulas(materia->aulas);
            materia->quantidadeFaltas = setQuantidadeFaltas(materia->aulas);
            fprintf(arq, "\nMateria: %s", aux->nome);
            fprintf(arq, "\nNumero da materia: %d", aux->numero);
            fprintf(arq, "\nCarga Horaria: %d", aux->cargaHoraria);
            fprintf(arq, "\nQuantidade de aulas: %d", aux->quandidadeAulas);
            fprintf(arq, "\nQuantidade de faltas: %d", aux->quantidadeFaltas);
            fprintf(arq, "\nEmenta: %s", aux->ementa);
            fprintf(arq, "\n\n\n");
            fprintf(arq, "Avaliacoes:\n\n\n");
            arq = imprimeAvaliacoesTexto(aux->avaliacoes, arq);
            fprintf(arq, "\n\n\nTrabalhos:\n\n\n");
            arq = imprimeTrabalhosTexto(aux->trabalhos, arq);
            fprintf(arq, "\n\n\nAulas:\n\n\n");
            arq =imprimeAulasTexto(aux->aulas, arq);
            fclose(arq);
            aux = aux->prox;
        }
    }
}

void gravaMateria(PilhaPeriodos *periodo, char *nome)
{
    FILE *arquivo;
    int cont = 0;
    char buffer1[150], buffer2[150];
    ListaMaterias *aux = periodo->materias;
    while (aux != NULL)
    {
        cont++;
        sprintf(buffer1, "Assistente Universitario\\Data\\%s.%d.M%d", nome, periodo->numero, cont);
        arquivo = fopen(buffer1, "wb");
        fwrite(aux, sizeof(ListaMaterias), 1, arquivo);
        fclose(arquivo);
        gravaAula(aux, nome, periodo->numero);
        gravaAvaliacao(aux, nome, periodo->numero);
        gravaTrabalho(aux, nome, periodo->numero);
        aux = aux->prox;
    }
    sprintf(buffer2, "Assistente Universitario\\Data\\%s.%d.M.txt", nome, periodo->numero);
    arquivo = fopen(buffer2, "w");
    fprintf(arquivo, "%d", cont);
    fclose(arquivo);
}

ListaMaterias *carregaMateria (PilhaPeriodos *periodo, char *nome)
{
    FILE *arquivo;
    ListaMaterias *aux = periodo->materias;
    char buffer1[150], buffer2[150];
    int cont = 0, i;
    sprintf(buffer1, "Assistente Universitario\\Data\\%s.%d.M.txt", nome, periodo->numero);
    arquivo = fopen(buffer1, "r");
    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &cont);
    }else{
        cont = 0;
        return NULL;
    }
    fclose(arquivo);
    remove(buffer1);
    for (i = cont; i >= 1; i--)
    {
        aux = NULL;
        sprintf(buffer2, "Assistente Universitario\\Data\\%s.%d.M%d", nome, periodo->numero, i);
        arquivo = fopen(buffer2, "rb");
        if (arquivo != NULL)
        {
            aux = (ListaMaterias*) malloc(sizeof(ListaMaterias));
            fread(aux, sizeof(ListaMaterias), 1, arquivo);
            aux->aulas = NULL;
            aux->aulas = carregaAula(aux, nome, periodo->numero);
            aux->avaliacoes = NULL;
            aux->avaliacoes = carregaAvaliacao(aux, nome, periodo->numero);
            aux->trabalhos = NULL;
            aux->trabalhos = carregaTrabalho(aux, nome, periodo->numero);
        }else{
            return NULL;
        }
        fclose(arquivo);
        remove(buffer2);
        aux->prox = periodo->materias;
        periodo->materias = aux;
    }
    return periodo->materias;
}

