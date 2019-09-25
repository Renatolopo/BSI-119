#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	printf("insira o valor de N: \n");
	scanf(" %i",&n);
	printf("**********************************\n");
	srand(time(NULL));
	int baralho[n], i,num,c,retorno;

	for(i=0; i<n; i++)
	{
		while(1)
		{
			num = 1+rand()%n;
			retorno = 0;
			for(c=0; c<i; c++)
			{
				if(num == baralho[c])
					retorno ++;
			}
			if(retorno == 0)
			{
				baralho[c] = num;
				printf("%i\n", baralho[c]);
				break;
			}

			
		}	
	}
}
