#include "racionais.h"
#include "stdlib.h"
#include "stdio.h"


int aleat (int min, int max){ 

	return (min + rand()%(max+1-min));
}


struct racional sorteia_r (int n){ 

	int numerador,denominador;
	struct racional r;

	numerador = aleat (0,n);
	denominador = aleat (0,n);
	r = cria_r (numerador,denominador);
	r.valido = valido_r (r);

	if (r.valido)
	      r = simplifica_r (r);

	return r;

}

/* coloca dois inteiros na struct */
struct racional cria_r (int numerador, int denominador){ 

	struct racional r;

	r.num = numerador;
	r.den = denominador;

	return r;

}

/* Retorna 0 se o denominador for nulo*/
int valido_r (struct racional r){ 

	if(r.den != 0)
		return(1);

	return 0;
}


int mdc (int a, int b ){

	if (a % b == 0)
		return b;

	return mdc(b,(a%b));
}


int mmc (int a, int b ){

	int num,den;
	
	num = (a * b);
	den = mdc (a, b);

	return num/den;
}


struct racional simplifica_r (struct racional r){ 

	int divisor;

	divisor = mdc(r.num, r.den);
	
	r.num = (r.num/divisor);
	r.den = (r.den/divisor);
	
	/* migra o sinal do denominador negativo para o numerador */
	/* troca o sinal do numero caso o numerador e denominador forem negativos */
	if (r.den < 0){ 
		r.num = r.num *(-1);
		r.den = r.den *(-1);
	}

    return(r);
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
struct racional soma_r (struct racional r1, struct racional r2){

	int denominador,numerador;
	struct racional r;

	denominador = mmc(r1.den,r2.den);
	numerador = ((denominador/r1.den * r1.num) + (denominador/r2.den * r2.num));
	
	r.num = numerador;
	r.den = denominador;
	
	r = simplifica_r(r);

	return r;
}

/* calcula o mmc dos denominadores */
/* divide o mmc pelos denominadores e multiplica pelos numeradores */
/* subtrai os numeradores */
struct racional subtrai_r (struct racional r1, struct racional r2){

	int denominador,numerador;
	struct racional r;

	denominador = mmc(r1.den,r2.den);
	numerador = ((denominador/r1.den * r1.num) - (denominador/r2.den * r2.num));
	
	r.num = numerador;
	r.den = denominador;
	
	r = simplifica_r(r);

	return r;
}


struct racional multiplica_r (struct racional r1, struct racional r2){

	int denominador,numerador;
	struct racional r;

	numerador = (r1.num * r2.num);
	denominador = (r1.den * r2.den);
	
	r.num = numerador;
	r.den = denominador;
    
    	r = simplifica_r(r);

	return r;
}

/* Faz multiplicação cruzada */
struct racional divide_r (struct racional r1, struct racional r2){ 

	int denominador,numerador;
	struct racional r;

	numerador = (r1.num * r2.den);
	denominador = (r2.num * r1.den);

	r.num = numerador;
	r.den = denominador;

	r.valido = valido_r (r);
	
	if (r.valido)
		r = simplifica_r(r);

	return r;
}
