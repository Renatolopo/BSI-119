#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int vet[30],i,aux = 0,cont=0,c=0,menor=30;
	srand(time(NULL));
	while(1)
	{
		cont=0;
		menor = 30;
		for(i=0;i<aux;i++){
			printf("%i ",vet[i]);
		}
		for(i=aux;i<30;i++)
		{
			vet[i] = rand()%5;
			printf("%i ",vet[i]);

			if((vet[i]==0)&&(i < menor)){
				aux = i;
				cont ++;
				menor = i;
					
			}
			

		}
		if((cont == 0)&&(c != 0))
			break;
		printf("\n");
		
		c++;
		
	}
}
