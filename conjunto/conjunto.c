#include<stdio.h>
#include<stdlib.h>
#include"conjunto.h"

int aleatorio (int min, int max){ 

	return (min + rand()%(max+1-min));
}

int busca_binaria (struct conjunto *c, int elemento){

    int ini,meio,fim;
    ini = 1;
    fim = c->card;
    meio = (ini + fim)/2;
   
    while ((ini <= fim ) && ( elemento != c->v[meio])){
        if (elemento < c->v[meio])
            fim = meio - 1;
        else
            ini = meio + 1;
        meio = (ini + fim)/2;
    }
   
    if (fim < ini)
        return 0;
       
    return meio;
}        

struct conjunto *cria_cjt (int max){

struct conjunto *c;
int *v;

c = malloc(sizeof(struct conjunto));
v = malloc((max + 1) * sizeof(int));

if ((!c) || (!v))
   return NULL;
   
    c->max = max;
    c->card = 0;
    c->v = v;
    inicia_iterador_cjt(c);
   
    return c;
}

struct conjunto *destroi_cjt (struct conjunto *c){

    int i;
    i = 0;
   
    while(i <= c->card){
        c->v[i] = 0;//null
        i++;
    }
   
    free(c);
    c = NULL;
   
    return c;  
}

int vazio_cjt (struct conjunto *c){

    if (c->card == 0)
        return 1;
   
    return 0;
}

int cardinalidade_cjt (struct conjunto *c){

    int cardinalidade;
   
    cardinalidade = c->card;
   
    return cardinalidade;
}

int insere_cjt (struct conjunto *c, int elemento){

    int i = 0;
       
        if (c->card > c->max)
            return 0;
           
        c->v[0] = elemento; //sentinela
        i = c->card;    
        while (elemento < c->v[i]) {
            c->v[i + 1] = c->v[i];
            i--;
        }
        		
        c->card++;
        c->v[i + 1] = elemento;
   
    return 1;
}    

int retira_cjt (struct conjunto *c, int elemento){

    if (!pertence_cjt(c,elemento))
        return 0;
   
    int i;
     
    for (i = busca_binaria(c,elemento); i<=c->card; i++)
        c->v[i] = c->v[i+1];
   
    c->card = c->card - 1;
   
    return 1;    
}

int pertence_cjt (struct conjunto *c, int elemento){

    if (busca_binaria(c,elemento) != 0)
        return 1;
   
    return 0;
}

int contido_cjt (struct conjunto *c1, struct conjunto *c2){

    int i,j;
    i = 1;
    j = 1;
     
    if (c1->card > c2->card)
        return 0;
       
    while ((i <= c1->card) && ( j <= c2->card)) {
        if (c1->v[i] < c2->v[j])
            return 0;
        if (c1->v[i] > c2->v[j])
            j = j + 1;
        else{
            i = i + 1;
            j = j + 1;
        }
    }
   
    if (i > c1->card)
        return 1;
   
    return 0;
}
       
int sao_iguais_cjt (struct conjunto *c1, struct conjunto *c2){

    int i = 1;
   
    if (c1->card != c2->card)
        return 0;
       
    while ((i <= c1->card) && (c1->v[i] = c2->v[i])){
        i++;
    }
   
    if (i > c1->card)
        return 1;
   
    return 0;
}
   
struct conjunto *diferenca_cjt (struct conjunto *c1, struct conjunto *c2){

    int i,j,k;
    struct conjunto *dif;
   
    dif = cria_cjt(c1->card);
   
    i = 1;
    j = 1;
    k = 0;
   
    while ((i <= c1->card) && (j <= c2->card)){
        if (c1->v[i] < c2->v[j]){
            k++;
            dif->v[k] = c1->v[i];
            i++;
        }
        else if (c1->v[i] > c2->v[j])
            j++;
        else{ //iguais
            i++;
            j++;
        }
    }
      
        /* se ainda tem elementos no c1*/
    for(j = i; j <=c1->card; j++){
        k++;
        dif->v[k] = c1->v[j];
        printf("OI");
    }
       
    dif->card = k;
    return dif;
}                            
       
struct conjunto *interseccao_cjt (struct conjunto *c1, struct conjunto *c2){

    int i,j,k;
    struct conjunto *inter;  
   
    inter = cria_cjt(c1->max);
   
    i = 1;
    j = 1;
    k = 0;
   
    while ((i <= c1->card) && (j <= c2->card)){
        if (c1->v[i] < c2->v[j])
            i = i + 1;
        else
            if (c1->v[i] > c2->v[j])
                j = j + 1;
            else{ // elemento esta nos dois conjuntos
                k = k + 1;
                inter->v[k] = c1->v[i];
                i = i + 1;
                j = j + 1;
            }
    }
   
    inter->card = k;
   
    return inter;
}                    
           
struct conjunto *uniao_cjt (struct conjunto *c1, struct conjunto *c2){

    struct conjunto *uni;
    int i;
   
    uni = cria_cjt (c1->card + c2->card);
   
    for (i = 1; i <= c1->card; i++)
        uni->v[i] = c1->v[i];
    uni->card = c1->card;
   
    for (i = 1; i <= c2->card; i++)
        if (!pertence_cjt(uni, c2->v[i]))
            insere_cjt(uni,c2->v[i]);
   
    return uni;            
}        
     
struct conjunto *copia_cjt (struct conjunto *c){

    int i;
    struct conjunto *copia;
   
    copia = cria_cjt(c->card);
    copia->card = c->card;
   
    for (i = 1;i <= c->card; i++){
        copia->v[i] = c->v[i];
    }
   
    return copia;
}
           
struct conjunto *cria_subcjt_cjt (struct conjunto *c, int n){

    struct conjunto *subc;
    int aleat,i;
   
    subc = cria_cjt(n);
   
    if (n >= c->card){
        subc = copia_cjt(c);
        return subc;
    }
   
    if (n){
	    for (i = 0; i < n; i++){
		aleat = aleatorio(1, c->card);
		while (!pertence_cjt(c,c->v[aleat]))
		    	aleat = aleatorio(1, c->card);
		insere_cjt(subc, c->v[aleat]);
	    }
    }
    return subc;                      
}          

void imprime_cjt (struct conjunto *c){

    int i;
    i = 1;
    if (c->card == 0)
        printf("conjunto vazio\n");
   
    while (i <= c->card - 1){
        printf("%d ",c->v[i]);
        i++;
    }
   if (c->card != 0)
    printf("%d\n", c->v[c->card]);
}        

void inicia_iterador_cjt (struct conjunto *c){

    c->ptr = 1;
}

int incrementa_iterador_cjt (struct conjunto *c, int *ret_iterador){

if (c->ptr <= c->card){
   ret_iterador = c->v;
   c->ptr = c->ptr+1;
   return 1;
}

return 0;
}

/*Remove o ultimo elemento*/
int retira_um_elemento_cjt (struct conjunto *c){

    int elem_rem;
   
    elem_rem = c->v[c->card];
    c->card = c->card - 1;
   
    return elem_rem;
}
