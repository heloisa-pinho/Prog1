#include<stdio.h>

	int main()
	{
		int quant,n,fatorial;

		scanf("%d",&n);
		quant=0;
		fatorial=1;

		while (quant!=n)
		{
			quant++;
			fatorial=fatorial*quant;
		}

		printf("%d\n",fatorial);
		
		return 0;
		
	}
