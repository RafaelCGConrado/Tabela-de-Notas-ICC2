#include <stdio.h>
#include <stdlib.h>


typedef struct alunos ALUNO;

struct alunos{
    char nome[30];
    //substituir isso aqui e deixar dinâmico
    int *notas;
    double media;
};

//Recebe os dados dos alunos e armazena nas structs
//respectivas
void leitura(ALUNO **alunos, int n_alunos, int n_notas);

//Calcula a média de cada aluno
void calcula_media(ALUNO **alunos, int n_alunos, int n_notas);

//Printa os nomes, notas e média de cada aluno.
//Usada para testes ao longo do código.
void printa(ALUNO **alunos, int n_alunos, int n_notas);

//Encontra o K utilizado na criação da árvore
int encontra_k(int n_alunos);

//Faz as comparações, desempata e retorna o "melhor" aluno
ALUNO *compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas);

//Constrói a árvore utilizada na ordenação
void constroi_arvore(ALUNO **arvore, int pai, int tamanho_arvore);

//Algoritmo de ordenação
void torneio_sort(ALUNO **alunos, int k, int n_alunos, int n_notas);
