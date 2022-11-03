#include "funcoes.h"

void leitura(ALUNO **alunos, int n_alunos, int n_notas){

    for(int i = 0; i < n_alunos; i++){
            alunos[i] = (ALUNO *)malloc(sizeof(ALUNO));
            scanf("%s", alunos[i] -> nome);
            alunos[i] -> notas = (int *)malloc(n_notas * sizeof(int));
            for(int j = 0; j < n_notas; j++){
                scanf("%d", &alunos[i]->notas[j]);
            }
        }


}



void calcula_media(ALUNO **alunos, int n_alunos, int n_notas){

    
    for(int i = 0; i < n_alunos; i++){
        
        double soma = 0;
        for(int j = 0; j < n_notas; j++){
            soma = soma + (alunos[i]->notas[j]);
        }
        alunos[i] -> media = (soma) / n_notas;
    }



}


void printa(ALUNO **alunos, int n_alunos, int n_notas){

    for(int i = 0; i < n_alunos; i++){
        
        printf("%s\n", alunos[i]->nome);
        for(int j = 0; j < n_notas; j++){
            printf("%d ", alunos[i]->notas[j]);
        }

        printf("\n%lf\n", alunos[i] -> media);
        printf("\n\n");
    }

}



int encontra_k(int n_alunos){

    int k = 1;
    while(k  < n_alunos){
        k = k * 2;
    }
    return k;

}

ALUNO *compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas){

    if(aluno1 -> media == aluno2 -> media){
        for(int i = 0; i < n_notas; i++){
            if(aluno1 -> notas[i] > aluno2 -> notas[i]) return aluno1;
            else if(aluno2 -> notas[i] > aluno1 -> notas[i]) return aluno2;
        }
    }

    if(aluno1 -> media > aluno2 -> media) return aluno1;
    
    else return aluno2;


}


void constroi_arvore(ALUNO **alunos, ALUNO **arvore, int pai, int tamanho_arvore){

    /*
    filho1 = constroi(2i)
    filho2 = constroi(2i+1)
    arvore[i] = melhor(filho1, filho2)
    
    'o caso base aqui pega direto do vetor original'

    */



}

void torneio_sort(ALUNO **alunos, int k, int n_alunos, int n_notas){




}
