#include<stdio.h>

int main()
{
	int n,quant,ultimo,penultimo,soma;

	scanf("%d",&n);
	quant=0;
	ultimo=1;
	penultimo=0;

	while(n!=quant)
	{
		printf("%d",ultimo); 
 		printf(" ");
	        soma= ultimo + penultimo;
		penultimo=ultimo;
		ultimo=soma;	
		quant++;
			
	}

	return 0;

}
