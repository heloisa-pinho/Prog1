#include <stdio.h>

int main()
{
	int numero,quadrado,saida;

	saida=1;

	scanf("%d",&numero);
	while (numero!=0)
	{
		quadrado=numero*numero;
		scanf("%d",&numero);
		if (quadrado!=numero) 
			saida=0;
		scanf("%d",&numero);
	}

	printf("%d\n",saida);

	return 0;

}

