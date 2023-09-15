/* Arquivo MAIN que usa o TAD racionais */

#include "racionais.h"
#include "stdio.h"
#include <stdlib.h>

/* coloque funcoes desejadas aqui. 
 * Exemplo: ordenar, eliminar invalidos... */
void ler_vetor(struct racional **v, int tam){
	
	int i;
	long int num,den;
	
	for (i = 0; i < tam; i++){
	    scanf("%ld,%ld",&num,&den);
	    v[i] = cria_r(num,den);
	}
}

void imprime_vetor(struct racional **v, int tam){
    
    int i;
    
    for (i = 0; i < tam; i++){
        imprime_r(v[i]);
        printf(" ");
    }
    printf(" ");
}

void elimina_invalido(struct racional **v, int *n){
    
    int i;
	
    for (i = 0; i < *n; i++){
        if (!valido_r(v[i])){
            v[i] = v[(*n) - 1];
            i--;
            --*n;
        }
    }
}

void troca (struct racional **v, int pos_menor,int i){

    struct racional *menor;
    menor = v[pos_menor];
    v[pos_menor] = v[i];
    v[i] = menor;
		
}

int menor_posicao (struct racional **v, int n, int i){
	
    int pos_menor,j,c;
	
    pos_menor = i;
	
    for(j = i+1;j < n; j++){
        c = compara_r(v[pos_menor],v[j]);
        
	if (c == 1)
            pos_menor = j;
    }
	
    return pos_menor;
}

void ordena_vetor(struct racional **v, int tam){

	int i,pos_menor;
	
    for (i = 0;i < (tam-1);i++){
        pos_menor = menor_posicao(v,tam,i);
        troca (v,i,pos_menor);
    }		
}    

void soma_vetor (struct racional **v,struct racional *soma, int n){
	
    int i;
	
    *soma = *v[0];
	
    for (i = 1; i < n; i++)
        soma_r(v[i], soma, soma);
}

void free_rac (struct racional **v, int tam){
    
    int i;
    
    for (i = 1; i<tam; i++)
        destroi_r(v[i]);
}

int main (){
    /* vetor de ponteiros para racionais */
    struct racional **v,*soma;  /* equivalente a struct racional *v[] */
    int n;

    scanf("%d",&n);
    
    v = malloc (n * sizeof(struct racional*));
    soma = malloc (sizeof(struct racional));
    
    ler_vetor(v,n);
/*    imprime_vetor(v,n);
    
    elimina_invalido(v,&n);
    imprime_vetor(v,n);
    
    ordena_vetor(v,n);
    imprime_vetor(v,n);
    
    soma_vetor(v, soma, n);
    printf("a soma de todos os elementos eh: ");
    imprime_r (soma);*/
    
    free_rac(v,n);
    free (v);
    destroi_r(soma);
    printf("\n");
    
    return 0;
}
