#include "funcoes.h"


int main(){

    int n_alunos, n_notas;
    scanf("%d %d", &n_alunos, &n_notas);
    
    ALUNO *alunos[n_alunos];
    leitura(alunos, n_alunos, n_notas);

    calcula_media(alunos, n_alunos, n_notas);


    //processo de ordenação
    int k = encontra_k(n_alunos);
    ALUNO *arvore[2 * k];



    //excluir isso depois
    ALUNO *vencedor = compara_alunos(alunos[0], alunos[3], n_notas);
    printf("Nome do vencedor: %s\n\n", vencedor->nome);

    printa(alunos, n_alunos, n_notas);


    return 0;
}    
