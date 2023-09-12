#include <stdio.h>

int main()
{
	int i,j,k,n,produto;

	scanf("%d", &n);

	i=1;
	produto=i*j*k;
	while (produto < n)
	{
		produto=i*(i+1)*(i+2);
		i++;
	}

	if (produto==n) 
		printf("1\n");
	else
		printf("0\n");

	return 0;

}


