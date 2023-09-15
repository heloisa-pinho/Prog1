#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

/* A diferenca desta implementação com relacao ao TP2
 * eh que os racionais devem alocados dinamicamente */

/* acrescente demais includes que voce queira ou precise */

/* 
 * Implemente aqui as funcoes definidas no racionais.h.
 * Caso queira, voce pode definir neste arquivo funcoes
 * adicionais que serao internas a este arquivo.
 *
 * Por exemplo, as funções mdc e mmc devem ser
 * implementadas neste arquivo.
*/

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
int mdc (int a, int b){

	if (a % b == 0)
	return b;

	return mdc(b,(a%b));
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
int mmc (int a, int b){

	int num,den;
    num = (a * b);
    den = mdc (a, b);

    return num/den;
}

struct racional *cria_r (long int numerador, long int denominador){

	struct racional *r;
	
	r = malloc (sizeof (struct racional));
	
	if (!r) 
		return NULL;

    r->num = numerador;
    r->den = denominador;
    
    simplifica_r (r);
    
    return r;
}

void destroi_r (struct racional *r){

	free (r);
}

int numerador_r (struct racional *r, long int *num){
	
	if (!r)
		return 0;
		
	*num = r->num;
	return 1;
}

int denominador_r (struct racional *r, long int *den){

	if (!r)
		return 0;
	
	*den = r->den;
	return 1;
}

int valido_r (struct racional *r){

	if
}

void imprime_r (struct racional *r){

	if (r == 0){
		printf("NULO");
		return;
	}

    if (r->num == 0){
        printf("0");
        return;
    }
	
    if (r->den == 1){
        printf("%ld",r->num);
        return;
    }

    if (r->num == r->den){ 
        printf("1");
        return;
    }

    if (!valido_r(r)) {
        printf("INVALIDO");
        return;
    }

    printf("%ld/%ld",r->num,r->den);
    return;
}

int compara_r (struct racional *r1, struct racional *r2){
		
	long int denominador,num_r1,num_r2;
	
    denominador = mmc(r1->den,r2->den);
    num_r1 = (denominador/r1->den * r1->num);
    num_r2 = (denominador/r2->den * r2->num);
    
    if ((!r1) || (!r2) || (!valido_r(r1)) || (!valido_r(r2)))
		return -2;
		
	if (num_r1 < num_r2) 
        return -1;
		
    if (num_r1 > num_r2)
        return 1;
        
    return 0;
}

int simplifica_r (struct racional *r){

	int divisor;
	
    if (!valido_r(r))
        return 0;
	
    divisor = mdc(r->num, r->den);
	
    r->num = (r->num/divisor);
    r->den = (r->den/divisor);
	
	/* migra o sinal do denominador negativo para o numerador */
	/* troca o sinal do numero caso o numerador e denominador forem negativos */
    if (r->den < 0){ 
        r->num = r->num *(-1);
        r->den = r->den *(-1);
    }
    return 1;
}

int soma_r (struct racional *r1, struct racional *r2, struct racional *r3){

	r3->den = mmc(r1->den,r2->den);
    r3->num = ((r3->den/r1->den * r1->num) + (r3->den/r2->den * r2->num));
	
    simplifica_r(r3);
	
    if ((!valido_r(r1)) || (!valido_r(r2))  || (!valido_r(r3)))
        return 0;

    return 1; 
}

int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	r3->den = mmc(r1->den,r2->den);
    r3->num = ((r3->den/r1->den * r1->num) - (r3->den/r2->den * r2->num));
	
    simplifica_r(r3);
	
    if ((!valido_r(r1)) || (!valido_r(r2))  || (!valido_r(r3)))
        return 0;

    return 1; 
}

int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	
    r3->num = (r1->num * r2->num);
    r3->den = (r1->den * r2->den);
	
    simplifica_r(r3);
	
    if ((!valido_r(r1)) || (!valido_r(r2))  || (!valido_r(r3)))
        return 0;

    return 1; 	
}

int divide_r (struct racional *r1, struct racional *r2, struct racional *r3){
	
	r3->num = (r1->num * r2->den);
    r3->den = (r2->num * r1->den);
	
    simplifica_r(r3);
	
    if ((!valido_r(r1)) || (!valido_r(r2))  || (!valido_r(r3)))
        return 0;
		
    return 1; 
}	  
