#include <stdio.h>
#include <stdlib.h>


typedef struct alunos ALUNO;

struct alunos{
    char nome[30];
    int *notas;
    double media;
    int desempate;
    int index;
};

//Recebe os dados dos alunos e armazena nas structs
//respectivas
void leitura(ALUNO **alunos, int n_alunos, int n_notas);

//Calcula a média de cada aluno
void calcula_media(ALUNO **alunos, int n_alunos, int n_notas);

//Calcula a maior media da turma
double maior_media(ALUNO **alunos, int n_alunos);

//Printa os nomes, notas e média de cada aluno.
//Usada para testes ao longo do código.
void printa(ALUNO **alunos, int n_alunos, int n_notas);

//Encontra o K utilizado na criação da árvore
int encontra_k(int n_alunos);

//Faz as comparações, desempata e retorna o "melhor" aluno
int compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas);

//Efetua as trocas de posição
void troca(ALUNO *a1, ALUNO *a2);

//Constrói a árvore utilizada na ordenação
void constroi_arvore(ALUNO **alunos, ALUNO **arvore, int tamanho_arvore, int n_alunos, int n_notas);

//Maximiza o heap que será utilizado na ordenação
void heapify(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas, int posicao);


//Algoritmo de ordenação
void torneio_sort(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas);


//Printa seguindo a formatação pedida no final do programa
void printa_final(ALUNO **alunos, int n_alunos, double maior_media);
