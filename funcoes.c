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
            alunos[i] -> desempate = 0;
        }


}



void calcula_media(ALUNO **alunos, int n_alunos, int n_notas){

    //Percorre vetor de notas, soma e divide
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

    //A intenção é descobrir qual é a maior potência de 2 maior ou igual ao
    //número de alunos
    int k = 1;
    while(k  < n_alunos){
        k = k * 2;
    }
    return k;

}

int compara_alunos(ALUNO *aluno1, ALUNO *aluno2, int n_notas){

    //RETORNA 0 -> aluno1 'melhor' do que o aluno 2
    //retorna 1 -> aluno 2 'melhor'


    //Caso 1: Médias de ambos os alunos são iguais
    //Compararemos as outras notas até encontrarmos a maior
    if(aluno1 -> media == aluno2 -> media && aluno1 -> media != 0 && aluno2 -> media !=0){
        for(int i = 0; i < n_notas; i++){
            if(aluno1 -> notas[i] > aluno2 -> notas[i]){ 
                aluno1 -> desempate = i + 1;
                return 0;
            }
            
            
            else if(aluno2 -> notas[i] > aluno1 -> notas[i]){
                aluno2 -> desempate = i + 1;
                return 1;
            }
        }
    }

    //Caso 2 e 3: Média de um dos alunos é maior. Não há necessidade
    //de desempate
    if(aluno1 -> media > aluno2 -> media) return 0;
    
    else return 1;

}

void swap(ALUNO *aluno1, ALUNO *aluno2){

    ALUNO aux = *aluno2;
    *aluno2 = *aluno1;
    *aluno1 = aux;

}

void constroi_arvore(ALUNO **alunos, ALUNO **arvore, int tamanho_arvore, int n_alunos, int n_notas, int posicao){

    for(int i = tamanho_arvore - 1; i > 2; i++){
        // // if(arvore[i-1] -> media == -1 && arvore[i] -> media) arvore[i/2] -> media = -1;
    
        // // else{
            
        // //     int comp = compara_alunos(arvore[i], arvore[i-1], n_notas);
        // //     if(comp == 0) arvore[i/2] = arvore[i];
        // //     else if(comp == 1) arvore[i/2] = arvore[i-1];

        // // }

        // if(i < tamanho_arvore - n_alunos){

        //     arvore[i] -> media = 0;
        //     arvore[i-1] -> media = 0;
        // }

    
    }

    //Importante lembrar que desconsideramos o indice 0 da árvore
    // alunos[posicao] = arvore[1];
    // arvore[arvore[1] -> maior_folha] -> media = -1;


}

void torneio_sort(ALUNO **arvore, ALUNO **alunos, int tamanho_arvore, int n_alunos, int n_notas){

    for(int i = 0; i < n_alunos; i++){

        arvore[(tamanho_arvore + i) - n_alunos] = alunos[i];
        arvore[(tamanho_arvore + i) - n_alunos] -> maior_folha = (tamanho_arvore + i) - n_alunos;

    }


    // //O ERRO ESTÁ AQUI!!!!!
    //FICA TRANQUILO, VOCE VAI CONSEGUIR RESOLVER
    //O RAFA DO FUTURO VAI ESTAR TE CHAMANDO DE IMBECIL
    // for(int j = 0; j < n_alunos; j++){

    //     constroi_arvore(alunos, arvore, tamanho_arvore, n_alunos, n_notas, j);
    // }

}
