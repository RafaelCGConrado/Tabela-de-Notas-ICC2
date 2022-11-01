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

int encontra_k(int n_alunos){

    int k = 1;
    while(k  < n_alunos){
        k = k * 2;
    }
    return k;

}

ALUNO *cria_arvore(int k){

    ALUNO *p = (ALUNO *)calloc(2 * k, sizeof(ALUNO));
    if(p) return p;
    return NULL;

}

void torneio_sort(ALUNO *arr, ALUNO *arvore, int k, int n_alunos){

    int tam_arvore = 2 * k;
    //1a etapa: preencher as folhas!
    //ou seja, ultimos elementos do vetor arvore
    int pos_arvore = tam_arvore - 1;
    for(int i = 0; i < n_alunos; i++){
        arvore[pos_arvore] = arr[i];
        pos_arvore--;
    }
    //transformar essa bagaça em funcao


    //2o passo: dividir em pares e encontrar
    //o maior de cada um -> pai
    //obs criterio 1 -> media
    //criterio 2 -> 1a nota, 2a nota .......




    


}

void printa_arvore(ALUNO *arvore, int k){
    for(int i = 0; i < 2 * k; i++){
        printf("%s\n", arvore[i].nome);
    }
}
