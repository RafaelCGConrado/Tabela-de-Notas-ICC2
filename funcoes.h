#include <stdio.h>
#include <stdlib.h>


typedef struct alunos ALUNO;

struct alunos{
    char nome[30];
    //substituir isso aqui e deixar dinâmico
    int *notas;
    double media;
};

ALUNO *cria_vetor();

void leitura(ALUNO *arr, int n_alunos, int n_notas);

void printa(ALUNO *arr, int n_alunos, int n_notas);

void calcula_media(ALUNO *arr, int n_alunos, int n_notas);

void cria_arvore();
