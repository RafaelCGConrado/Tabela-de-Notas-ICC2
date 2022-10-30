#include "funcoes.h"


int main(){

    ALUNO *arr = cria_vetor();


    int n_alunos, n_notas;
    scanf("%d %d", &n_alunos, &n_notas);

    //SUBSTITUIR TODA ESSA PARTE PELA FUNCAO
    //LEITURA
    for(int i = 0; i < n_alunos; i++){
        scanf("%s", arr[i].nome);
        arr[i].notas = (int *) malloc(n_notas * sizeof(int));
        for(int j = 0; j < n_notas; j++){
            scanf("%d", &arr[i].notas[j]);
        }

        arr = realloc(arr, (i + 2) * sizeof(ALUNO));
    }
   

    //2a etapa: ordenação dessa bagaça
    //por onde começar?


    calcula_media(arr, n_alunos, n_notas);

    printa(arr, n_alunos, n_notas);
    free(arr);
}
