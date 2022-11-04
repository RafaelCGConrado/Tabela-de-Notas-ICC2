#include <stdio.h>
#include <stdlib.h>


typedef struct alunos ALUNO;

struct alunos{
    char nome[30];
    int *notas;
    double media;
    int desempate;
    int maior_folha;
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

//Efetua troca de posição entre dois alunos
void swap(ALUNO *aluno1, ALUNO *aluno2);


//Faz as comparações, desempata e retorna o "melhor" aluno
int compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas);

//Constrói a árvore utilizada na ordenação
void constroi_arvore(ALUNO **alunos, ALUNO **arvore, int tamanho_arvore, int n_alunos, int n_notas, int posicao);

//Algoritmo de ordenação
void torneio_sort(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas);
