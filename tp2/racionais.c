#include "racionais.h"
#include "stdio.h"
#include <stdlib.h> 

/* retorna um numero aleatorio entre min e max, inclusive. */
int aleat (int min, int max){

    return(min + rand()%(max+1-min));

}

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

struct racional sorteia_r (int max){

    int numerador,denominador;
    struct racional r;

    numerador = aleat (-max,max);
    denominador = aleat (-max,max);
    r = cria_r (numerador,denominador);
	

    if (r.valido)
        simplifica_r (&r);

    return r;
}

/* coloca dois inteiros na struct */
struct racional cria_r (int numerador, int denominador){

    struct racional r;

    r.num = numerador;
    r.den = denominador;
    r.valido = valido_r (r);
    
    return r;

}

/* Retorna 0 se o denominador for nulo*/
int valido_r (struct racional r){

    if(r.den != 0)
    return(1);

    return 0;
}

int numerador_r (struct racional r){

    return r.num;
}

int denominador_r (struct racional r){

    return r.den;
}

/*iguala os denominadores com mmc
*divide pelo denominador e multiplica pelo numerador*/
int compara_r (struct racional r1, struct racional r2){

    int denominador,num_r1,num_r2;
	
    denominador = mmc(r1.den,r2.den);
    num_r1 = (denominador/r1.den * r1.num);
    num_r2 = (denominador/r2.den * r2.num);
	
    if (num_r1 < num_r2) 
        return -1;
		
    if (num_r1 > num_r2)
        return 1;
	
    return 0;
}
/*retorna 0 se for inavalido, caso contrario retorna 1*/
int simplifica_r (struct racional *r){
    int divisor;
	
    if (r->valido == 0)
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

void imprime_r (struct racional r){

    if (r.num == 0){
        printf("0");
        return;
    }
	
    if (r.den == 1){
        printf("%d",r.num);
        return;
    }

    if (r.num == r.den){ 
        printf("1");
        return;
    }

    if (r.valido == 0) {
        printf("INVALIDO");
        return;
    }

    printf("%d/%d",r.num,r.den);
    return;
}

/* calcula o mmc dos denominadores */
/* divide o mmc pelos denominadores e multiplica pelos numeradores */
/* soma os numeradores */
int soma_r (struct racional r1, struct racional r2, struct racional *r3){
		
    r3->den = mmc(r1.den,r2.den);
    r3->num = ((r3->den/r1.den * r1.num) + (r3->den/r2.den * r2.num));
	
    r3->valido = valido_r(*r3);
	
    simplifica_r(r3);
	
    if ((!r1.valido) || (!r2.valido)  || (!r3->valido))
        return 0;

    return 1; 	
}

/* calcula o mmc dos denominadores */
/* divide o mmc pelos denominadores e multiplica pelos numeradores */
/* subtrai os numeradores */
int subtrai_r (struct racional r1, struct racional r2, struct racional *r3){
		
    r3->den = mmc(r1.den,r2.den);
    r3->num = ((r3->den/r1.den * r1.num) - (r3->den/r2.den * r2.num));
	
    r3->valido = valido_r(*r3);
	
    simplifica_r(r3);
	
    if ((!r1.valido) || (!r2.valido)  || (!r3->valido))
        return 0;

    return 1; 	
	
	
}

int multiplica_r (struct racional r1, struct racional r2, struct racional *r3){
	
	
    r3->num = (r1.num * r2.num);
    r3->den = (r1.den * r2.den);
	
    r3->valido = valido_r(*r3);
	
    simplifica_r(r3);
	
    if ((!r1.valido) || (!r2.valido)  || (!r3->valido))
        return 0;

    return 1; 	
}

/* Faz multiplicação cruzada */
int divide_r (struct racional r1, struct racional r2, struct racional *r3){

    r3->num = (r1.num * r2.den);
    r3->den = (r2.num * r1.den);
	
    r3->valido = valido_r(*r3);
	
    simplifica_r(r3);
	
    if ((!r1.valido) || (!r2.valido)  || (!r3->valido))
        return 0;
		
    return 1; 	
}
