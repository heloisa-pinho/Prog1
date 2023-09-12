#include<stdio.h>

        int main()
	{
                int quantidade,ultimo,soma,dobro,metade,anterior;

                quantidade=2;
                scanf("%d",&anterior);
		scanf("%d",&ultimo);
                soma=anterior+ultimo;
                dobro=anterior*2;
                metade=anterior/2;
		
                while(ultimo!=dobro && ultimo!= metade)
		{
                        anterior=ultimo;
                        scanf("%d",&ultimo);
                        soma=soma+ultimo;
                        quantidade++;
                        dobro=anterior*2;
                        metade=anterior/2;
                }

                printf("%d %d %d %d\n", quantidade,soma,anterior,ultimo);

		return 0;

        }
