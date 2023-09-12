/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include "stdio.h"
#include <stdlib.h>

#define MAX 100

void ler_vetor(struct racional v[],int n){

    int i;
	
	for (i = 0;i < n;i++)
            v[i] = sorteia_r (n);
}


void imprime_vetor(struct racional v[],int n){

    int i;
	
    for (i = 0;i < n;i++){
        imprime_r(v[i]);
        printf(" ");
    }
	
    printf("\n");
}


void elimina_invalido(struct racional v[], int *n){

    int i,j;
	
    for (i = 0; i < *n; i++){
        if (!valido_r(v[i])){
            for (j = i;j < *n;j++)
                v[j] = v[j+1];
            i--;
            --*n;
        }
    }
}


void troca (struct racional v[], int pos_menor,int i){

    struct racional menor;
    menor = v[pos_menor];
    v[pos_menor] = v[i];
    v[i] = menor;
		
}


int menor_posicao (struct racional v[], int n, int i){
	
    int pos_menor,j,c;
	
    pos_menor = i;
	
    for(j = i+1;j < n; j++){
        c = compara_r(v[pos_menor],v[j]);
        
	if (c == 1)
            pos_menor = j;
    }
	
    return pos_menor;
}


void ordena_vetor (struct racional v[], int *n){

    int i,pos_menor;
	
    for (i = 0;i < (*n-1);i++){
        pos_menor = menor_posicao(v,*n,i);
        troca (v,i,pos_menor);
    }		
}


void soma_vetor (struct racional v[], struct racional *soma, int n){
	
    int i;
	
    *soma = v[0];
	
    for (i = 1; i < n; i++)
        soma_r(v[i], *soma, soma);
}


int main (){

    int n;
    struct racional v[MAX],racional_soma;
		
    srand(0);
		
    scanf("%d",&n);
		
    while ((n <= 0) || (n > 100)){ 
        printf("Numero Invalido\n");
        scanf("%d",&n);
    }
	
    ler_vetor(v,n);
    imprime_vetor(v,n);

    elimina_invalido(v,&n);
    imprime_vetor(v,n);
	
    ordena_vetor(v,&n);
    imprime_vetor(v,n);
	
    soma_vetor(v,&racional_soma,n);
    printf("a soma de todos os elementos eh: ");
    imprime_r (racional_soma);
    printf("\n");
	
    return 0;
}
