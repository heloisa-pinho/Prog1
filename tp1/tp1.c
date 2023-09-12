/* Arquivo MAIN que usa o TAD racionais */

#include <stdio.h>
#include "racionais.h"
#include <stdlib.h>

int main (){

	int n,max,i;
	struct racional r_soma,r_sub,r_mult,r_div,r1,r2;
	
		/* inicializa a semente randomica */
		srand(0);
		
		scanf("%d",&n);
		
		/*confere se o numero esta entre 0 e 100 */
		while ((n <= 0) || (n >= 100)){ 
			printf("Numero Invalido");
			scanf("%d",&n);
		}
		
		scanf("%d",&max);
		
		/* confere se o numero esta entre 0 e 30 */
		while ((max <= 0) || (max >= 30)){
			printf("Numero Invalido");
			scanf("%d",&max);
		}
	    
	    	for (i = 1; i <= n; i++){
	    		printf("%d: ",i);
	    		
	    		r1 = sorteia_r(max);
	    		r2 = sorteia_r(max);
	    		
	    		imprime_r(r1);
	    		printf(" ");
	    		
	    		imprime_r(r2);
	    		printf(" ");
	    		
	    		if ((!r1.valido) || (!r2.valido)){
	    			printf( "NUMERO INVALIDO\n" );
	    			return(1);
	    		}
	    		
	    		r_soma = soma_r (r1,r2);
	    		r_sub = subtrai_r (r1,r2);
	    		r_mult = multiplica_r (r1,r2);
	    		r_div = divide_r (r1,r2);
	    		
	    		if (!r_div.valido) {
	    			printf("NUMERO INVALIDO\n");
	    			return (1);
	    		}
	    		
	    		imprime_r(r_soma);
	    		printf(" ");
	   
	    		imprime_r(r_sub);
	    		printf(" ");
	    		
	    		imprime_r(r_mult);
	    		printf(" ");
	    		
	    		imprime_r(r_div);
			printf("\n");
		}
		
	    	return 0;
}
