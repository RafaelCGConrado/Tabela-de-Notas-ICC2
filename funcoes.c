#include "funcoes.h"

void leitura(ALUNO **alunos, int n_alunos, int n_notas){

    //Lê os dados da entrada, armazena nos vetores
    //e faz alocações necessárias
    for(int i = 0; i < n_alunos; i++){
            alunos[i] = (ALUNO *)malloc(sizeof(ALUNO));
            scanf("%s", alunos[i] -> nome);
            alunos[i] -> notas = (int *)malloc(n_notas * sizeof(int));
            for(int j = 0; j < n_notas; j++){
                scanf("%d", &alunos[i]->notas[j]);
            }
            //o desempate fica setado como 0 por padrão
            //(será modificado se necessário)
            alunos[i] -> desempate = 0;
        }


}



void calcula_media(ALUNO **alunos, int n_alunos, int n_notas){

    //Percorre vetor de notas, acumula as notas na variavel
    //soma e divide pelo numero de notas
    for(int i = 0; i < n_alunos; i++){
        
        double soma = 0;
        for(int j = 0; j < n_notas; j++){
            soma = soma + (alunos[i]->notas[j]);
        }
        alunos[i] -> media = (soma) / n_notas;
    }



}

double maior_media(ALUNO **alunos, int n_alunos){
    
    //Percorre todas as medias e compara com a maior media
    //registrada até então. Se for maior, substituimos o valor.
    double maior = 0;
    for(int i = 0; i < n_alunos; i++){
        if(alunos[i] -> media > maior) maior = alunos[i] -> media;
    }
    return maior;

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

    //A intenção é descobrir qual é a maior potência de 2 maior ou igual ao
    //número de alunos
    int k = 1;
    while(k  < n_alunos){
        k = k * 2;
    }
    return 2 * k;

}


int compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas){

   //Retorno 1 - Primeiro Aluno vence
   //Retorno -1 - Segundo Aluno Vence


    //Importante verificar os casos em que temos um ponteiro apontando
    //para NULL
    if(aluno1 != NULL && aluno2 == NULL) return 1;
    if(aluno2 != NULL && aluno1 == NULL) return -1;

    

    if(aluno1 != NULL && aluno2 != NULL){
        
        //De forma geral, comparamos as médias.
        //Se as médias forem iguais, partimos para o critério
        //de desempate.
        if(aluno1 -> media > aluno2 -> media) return 1;
        else if(aluno2 -> media > aluno1 -> media) return -1;

        if(aluno1 -> media == aluno2 -> media){
            
            for(int i = 0; i < n_notas; i++){
                
               //É fundamental aqui registrar se o valor da nota
               //referente ao desempate é MAIOR do que o desempate
               //registrado anteriormente.
                if(aluno1 -> notas[i] > aluno2 -> notas[i]){
                    if(i+1 > aluno1 -> desempate) aluno1 -> desempate = i+1;
                   
                    return 1;
                }

                if(aluno1 -> notas[i] < aluno2 -> notas[i]){
                    if(i+1 > aluno2 -> desempate) aluno2 -> desempate = i+1;
                    
                    return -1;

                }
                


            }
        }



    }


}


void constroi_arvore(ALUNO **alunos, ALUNO **arvore, int tamanho_arvore, int n_alunos, int n_notas){

    //Primeiro, setamos toda a arvore para NULL para futuras comparações
    for(int i = 0; i < tamanho_arvore; i++) arvore[i] = NULL;

    //Preenche as folhas com os alunos a serem ordenados
    //Também adiciona um index que será útil na função de heapify
    for(int i = 0; i < n_alunos; i++){
        arvore[tamanho_arvore + i - n_alunos] = alunos[i];
        arvore[tamanho_arvore + i - n_alunos]->index = tamanho_arvore + i - n_alunos;
    }

}

void heapify(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas, int j){

    for(int i = tamanho_arvore - 1; i >= 2; i-=2){
        

        if(arvore[i] != NULL && arvore[i-1] != NULL){

            if(arvore[i] -> media == -1 && arvore[i-1] -> media == -1) arvore[i/2] -> media = -1;

            else{
                if(compara_alunos(arvore[i], arvore[i-1], n_notas) == 1){
            
                    arvore[i/2] = arvore[i];
                }

                if(compara_alunos(arvore[i], arvore[i-1], n_notas) == -1){

                    arvore[i/2] = arvore[i-1];
                }
            }

        }

        if(arvore[i] != NULL && arvore[i-1] == NULL){

            arvore[i/2] = arvore[i];

        }

        if(arvore[i] == NULL && arvore[i-1] != NULL){

            arvore[i/2] = arvore[i-1];
        }


    }
    
    if(arvore[1] != NULL){
        alunos[j] = arvore[1];
        arvore[arvore[1] -> index] -> media = -1;
    }


}

void torneio_sort(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas){


    for(int j = 0; j < n_alunos; j++){
        heapify(arvore, alunos, tamanho_arvore, n_alunos, n_notas, j);
    }

}

void printa_final(ALUNO **alunos, int n_alunos, double maior_media){

    printf("Maior media: %.3lf\n", maior_media);
    for(int i = 0; i < n_alunos; i++){
        printf("%d. %s", i+1, alunos[i] -> nome);
        if(i != n_alunos - 1){

            if(alunos[i] -> desempate != 0){
                printf(" - desempate: nota %d", alunos[i] -> desempate);
            }

            else{
                printf(" - media");
            }


        }

        printf("\n");
    }

    
}
