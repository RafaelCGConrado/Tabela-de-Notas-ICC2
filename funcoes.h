#include <stdio.h>
#include <stdlib.h>


typedef struct alunos ALUNO;

struct alunos{
    char nome[30];
    //substituir isso aqui e deixar dinâmico
    int *notas;
    double media;
};

//Cria vetor ALUNO da struct alunos e retorna
ALUNO *cria_vetor();

//Lê a entrada do usuário e armazena no vetor de ALUNO
void leitura(ALUNO *arr, int n_alunos, int n_notas);

//printa todos os elementos do vetor ALUNO. Usado para fazer
//testes no código
void printa(ALUNO *arr, int n_alunos, int n_notas);

//Calculo a média de notas de cada aluno e armazena na struct
//respectiva
void calcula_media(ALUNO *arr, int n_alunos, int n_notas);


//Encontra o K que será utilizado para alocar
//o vetor da árvore binaria
int encontra_k(int n_alunos);

//Cria o vetor que estrutura a árvore a 
//partir do K encontrado
ALUNO *cria_arvore(int k);

//Algoritmo de ordenação TORNEIO_SORT
void torneio_sort(ALUNO *arr, ALUNO *arvore, int k);
