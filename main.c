#include "funcoes.h"


int main(){

    //Inicialização, leitura e cálculos das médias
    int n_alunos, n_notas;
    scanf("%d %d", &n_alunos, &n_notas);
    
    ALUNO *alunos[n_alunos];
    leitura(alunos, n_alunos, n_notas);

    calcula_media(alunos, n_alunos, n_notas);
    double maior = maior_media(alunos, n_alunos);


    //processo de ordenação
    int dois_k = encontra_k(n_alunos);
    ALUNO *arvore[dois_k];

   
    
    constroi_arvore(alunos, arvore, dois_k, n_alunos, n_notas);
    torneio_sort(arvore, alunos, dois_k, n_alunos, n_notas);



    printa_final(alunos, n_alunos, maior);

    free(*alunos);
    free(*arvore);

    return 0;
}    
