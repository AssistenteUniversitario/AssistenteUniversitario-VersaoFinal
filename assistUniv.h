#include <stdlib.h>

struct Data
{
    int dia, mes, ano;
};
typedef struct Data Data;

struct Trabalhos
{
    Data data;
    char tema[20];
	char descricao[500];
	char link[120];
    float nota;
    float peso;
	int relevancia;
    struct Trabalhos *prox;
};
typedef struct Trabalhos ListaTrabalhos;

struct Avaliacoes
{
    Data data;
    char tema[20];
    float nota;
    float peso;
    struct Avaliacoes *prox;
};
typedef struct Avaliacoes ListaAvaliacoes;

struct Aulas
{
    Data data;
    char descricao[140];
    char tipo;
    int ministrada;
    int presenca;
    struct Aulas *prox;
};
typedef struct Aulas ListaAulas;


struct Materia
{
    int numero;
    char nome[30];
    char ementa[300];
    int cargaHoraria;
    ListaAulas *aulas;
    ListaAvaliacoes *avaliacoes;
    ListaTrabalhos *trabalhos;
    int quandidadeAulas;
    int quantidadeFaltas;
    struct Materia *prox;
};

typedef struct Materia ListaMaterias;


struct Periodo
{
    int numero;
    ListaMaterias *materias;
    struct Periodo *prox;
};
typedef struct Periodo PilhaPeriodos;


struct Curso
{
    char nome[50];
    PilhaPeriodos *periodos;
};
typedef struct Curso Curso;

struct Faculdade
{
    char nome[50];
    Curso curso;
    Data dataIngresso;
};
typedef struct Faculdade Faculdade;

struct Aluno
{
    char nome[50];
    Faculdade faculdade;
    int matricula;
    struct Aluno *prox;
};
typedef struct Aluno Aluno;



Aluno *setAluno(Aluno *aluno);
Aluno editAluno (Aluno aluno);
Aluno *removeAluno (Aluno *aluno, int alunoEscolhido);
void imprimeAluno(Aluno aluno);
void imprimeAlunoTexto(Aluno aluno);
Aluno menuAluno (Aluno aluno);
Aluno *menu(Aluno *alunos);
void grava(Aluno *aluno);
Aluno *carrega (Aluno *aluno);
void gravaAluno(Aluno *aluno);
Aluno *carregaAluno (Aluno *aluno);



PilhaPeriodos *inserePilhaPeriodos(PilhaPeriodos *topoPeriodos);
PilhaPeriodos editPeriodo(PilhaPeriodos periodo);
PilhaPeriodos *removePeriodo (PilhaPeriodos *topoPeriodo);
PilhaPeriodos *esvaziaPeriodo (PilhaPeriodos *topoPeriodo);
PilhaPeriodos *menuPeriodos (PilhaPeriodos *periodos, Aluno *aluno);
void imprimePeriodos(PilhaPeriodos *periodos);
void gravaPeriodo(Aluno *aluno);
PilhaPeriodos *carregaPeriodo (Aluno *aluno);




ListaMaterias *setMaterias (ListaMaterias *materias);
ListaMaterias editMateria (ListaMaterias materia);
ListaMaterias *removeMateria (ListaMaterias *materia, int numMateria);
ListaMaterias *esvaziaMateria (ListaMaterias *materia);
ListaMaterias *menuMaterias (ListaMaterias *materias);
void imprimeMaterias(ListaMaterias *materia);
void imprimeMateriasTexto(ListaMaterias *materia, PilhaPeriodos *periodo, Aluno *aluno);
void gravaMateria(PilhaPeriodos *periodo, char *nome);
ListaMaterias *carregaMateria (PilhaPeriodos *periodo, char *nome);




ListaAvaliacoes *setAvaliacoes (ListaAvaliacoes *avaliacoes);
ListaAvaliacoes editAvaliacoes (ListaAvaliacoes avaliacao);
ListaAvaliacoes *removeAvaliacao (ListaAvaliacoes *avaliacao, int avaliacaoEscolhida);
ListaAvaliacoes *esvaziaAvaliacoes (ListaAvaliacoes *avaliacoes);
ListaAvaliacoes *menuAvaliacoes (ListaAvaliacoes *avaliacoes);
void imprimeAvaliacoes(ListaAvaliacoes *avaliacoes);
FILE *imprimeAvaliacoesTexto(ListaAvaliacoes *avaliacoes, FILE *arq);
void gravaAvaliacao(ListaMaterias *materia, char *nome, int numPeriodo);
ListaAvaliacoes *carregaAvaliacao (ListaMaterias *materia, char *nome, int numPeriodo);


ListaTrabalhos *setTrabalhos (ListaTrabalhos *trabalhos);
ListaTrabalhos editTrabalhos (ListaTrabalhos trabalho);
ListaTrabalhos *removeTrabalho (ListaTrabalhos *trabalho, int trabalhoEscolhido);
ListaTrabalhos *esvaziaTrabalho (ListaTrabalhos *trabalho);
ListaTrabalhos *menuTrabalhos (ListaTrabalhos *trabalhos);
void imprimeTrabalhos(ListaTrabalhos *trabalhos);
void imprimeTrabalhosPorRelevancia(ListaTrabalhos *trabalhos, int relevancia);
FILE *imprimeTrabalhosTexto(ListaTrabalhos *trabalhos, FILE *arq);
void gravaTrabalho(ListaMaterias *materia, char *nome, int numPeriodo);
ListaTrabalhos *carregaTrabalho (ListaMaterias *materia, char *nome, int numPeriodo);



ListaAulas *setAulas(ListaAulas *aulas);
ListaAulas editAula(ListaAulas aula);
ListaAulas *removeAula (ListaAulas *aula, int aulaEscolhida);
ListaAulas *esvaziaAulas (ListaAulas *aulas);
int setQuantidadeAulas(ListaAulas *aulas);
ListaAulas *menuAulas (ListaAulas *aulas);
void imprimeAulas(ListaAulas *aulas);
FILE *imprimeAulasTexto(ListaAulas *aulas, FILE *arq);
int setQuantidadeFaltas(ListaAulas *aulas);
void gravaAula(ListaMaterias *materia, char *nome, int numPeriodo);
ListaAulas *carregaAula (ListaMaterias *materia, char *nome, int numPeriodo);
float indiceFrequencia(ListaMaterias *materia, ListaAulas *aulas);
void situacaoFrequencia(ListaMaterias *materia, ListaAulas *aulas);


Data setData();



Curso setCurso();
Curso editCurso (Curso curso);
void imprimeCurso(Curso curso);




Faculdade setFaculdade();
Faculdade editFaculdade(Faculdade faculdade);
void imprimeFaculdade(Faculdade faculdade);

