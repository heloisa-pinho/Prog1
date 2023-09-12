#include<stdio.h>

int main()
{
	int k,quantidade,soma,divisor,n;

	scanf("%d",&k);
	quantidade=1;
	n=6;

	while (k>=quantidade)
	{
		soma=0;
		for (divisor=1;divisor<n;divisor++)
		{
			if(n%divisor == 0)
			{
				soma=soma+divisor;
			}
		}

		if (soma==n)
		{
			printf("%d ",n);
			quantidade++;
		}

		n++;
	}

	return 0;
}


