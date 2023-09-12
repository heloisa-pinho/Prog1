#include<stdio.h>

	int main()
	{
		int n,soma,mult;

		scanf("%d",&n);
		mult=n*37;
		soma=0;

		while (mult!=0)
		{
			soma=(mult%10)+soma;
			mult=mult/10;
		}

		if(soma==n)
			printf("SIM\n");
		else
			printf("NAO\n");

		return 0;
	}
