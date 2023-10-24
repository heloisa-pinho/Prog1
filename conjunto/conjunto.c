#include<stdio.h>
#include<stdlib.h>
#include"conjunto.h"

struct conjunto *cria_cjt (int max){

	struct conjunto *c;
	
	c = malloc(sizeof(struct conjunto));
	
	if (!c)
	    return NULL;
	    
    c->max = max;
    c->card = 0;//null
    
    return c;
}

struct conjunto *destroi_cjt (struct conjunto *c){

    int i;
    i = 0;
    
    while(i <= c->card){
        c->v[i] = 0;//null
        i++;
    }
    
    c = NULL;
    free(c);
    
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

    if (!pertence_cjt(c,elemento)){
        c->card = c->card + 1;
        
        if (c->card > c->max)
            return 0;
        c->v[c->card] = elemento;
    }
    
    return 1;
}     

int retira_cjt (struct conjunto *c, int elemento){

    if (!pertence_cjt(c,elemento))
        return 0;
    
    int i;
    
    i = 0;
    c->v[c->card + 1] = elemento; //sentinela
    
    while (elemento != c->v[i])
        i++;
        
    if (i < (c->card + 1)){
        c->v[i] = c->v[c->card]; //subscreve o ultimo elemento no elemento a ser removido 
        c->card = c->card - 1;     
    }
    
    return 1;
}

int pertence_cjt (struct conjunto *c, int elemento){

    int i;
    i = 0;
    
    c->v[c->card + 1] = elemento; //sentinela
    
    while (elemento != c->v[i])
        i++;

    if (i > c->card)
        return 0;
    
    return 1;
}

int contido_cjt (struct conjunto *c1, struct conjunto *c2){

    int i;
    i = 0;
    
    if (c1->card > c2->card)
        return 0;
        
    while (i <= c2->card) {
        if (! pertence_cjt(c2,c1->v[i]))
            return 0;
        i++;
    }
    
    return 1;
}
        
/*int sao_iguais_cjt (struct conjunto *c1, struct conjunto *c2){

struct conjunto *diferenca_cjt (struct conjunto *c1, struct conjunto *c2)          
        
struct conjunto *interseccao_cjt (struct conjunto *c1, struct conjunto *c2)        
        
struct conjunto *uniao_cjt (struct conjunto *c1, struct conjunto *c2)    */    
        
struct conjunto *copia_cjt (struct conjunto *c){

    int i;
    struct conjunto *copia;
    
    copia = cria_cjt(c->card);
    copia->card = c->card;
    
    for (i = 0;i++;i=c->card){
        copia->v[i] = c->v[i];
    }
    
    return copia;
} 
           
/*struct conjunto *cria_subcjt_cjt (struct conjunto *c, int n)

void imprime_cjt (struct conjunto *c)*/

void inicia_iterador_cjt (struct conjunto *c){

    c->ptr = 0;
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
