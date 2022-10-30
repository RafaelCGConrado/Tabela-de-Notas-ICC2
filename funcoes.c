#include "funcoes.h"


ALUNO *cria_vetor(){

    ALUNO *arr = (ALUNO *) malloc(sizeof(ALUNO));
    if(arr) return arr;
    return NULL;


}
void leitura(ALUNO *arr, int n_alunos, int n_notas){

 for(int i = 0; i < n_alunos; i++){
        scanf("%s", arr[i].nome);
        arr[i].notas = (int *) malloc(n_notas * sizeof(int));
        for(int j = 0; j < n_notas; j++){
            scanf("%d", &arr[i].notas[j]);
        }

        arr = realloc(arr, (i + 2) * sizeof(ALUNO));
    }
}


void printa(ALUNO *arr, int n_alunos, int n_notas){

    for(int i = 0; i < n_alunos; i++){
        printf("%s\n", arr[i].nome);
        for(int j = 0; j < n_notas; j++){
            printf("%d\n", arr[i].notas[j]);
        }
        printf("%.3lf\n", arr[i].media);
        printf("\n\n");
    }

}

void calcula_media(ALUNO *arr, int n_alunos, int n_notas){

    
    for(int i = 0; i < n_alunos; i++){
        
        double soma = 0;
        for(int j = 0; j < n_notas; j++){
            soma = soma + (arr[i].notas[j]);
        }
        arr[i].media = (soma) / n_notas;
    }



}
