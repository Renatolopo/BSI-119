#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x, y;
	printf("informe X: \n");
	scanf(" %i", &x);
	printf("informe Y: \n");
	scanf(" %i", &y);

	srand(time(NULL));
	int vetx[x], vety[y];
	int aux;
	aux = x+y;
	printf("**********************************\n");
	printf("vetor x:\n");
	printf("**********************************\n");
	int i,n,c,retorno; 
	for(i=0; i<x; i++)
	{
		while(1)
		{
			n = rand()%aux;
			retorno=0;
			for(c=0;c<i;c++)
			{
				if(n == vetx[c])
					retorno++;
			}
			if(retorno == 0)
			{
				vetx[c] = n;
				printf("%i ",vetx[c]);
				break;
			}

		}
	}
	printf("\n");
	printf("**********************************\n");
	printf("vetor y:\n");
	printf("**********************************\n");


	for(i=0; i<y; i++)
	{
		while(1)
		{
			n = rand()%aux;
			retorno=0;
			for(c=0;c<i;c++)
			{
				if(n == vety[c])
					retorno++;
			}
			if(retorno == 0)
			{
				vety[c] = n;
				printf("%i ",vety[c]);
				break;
			}

		}
	}
	printf("\n");
	printf("**********************************\n");

	printf("interseção de X com Y: \n");
	
	for(i=0; i<x; i++)
	{
		
		for(c=0; c<y; c++)
		{
			if(vetx[i] == vety[c]){
				printf("%i  ",vetx[i]);
				
			}
			

		}
	}
	int cont;
	printf("\n");
	printf("numeros exclusivos de X:\n");
	for(i=0; i<x; i++)
	{
		cont=0;
		for(c=0; c<y; c++)
		{
			if(vetx[i] == vety[c]){
				cont++;
				
			}

		}
		if(cont == 0){
			printf("%i  ",vetx[i]);
		}
	}
	printf("\n");
	printf("numeros exclusivos de Y:\n");
	for(i=0; i<y; i++)
	{
		cont=0;
		for(c=0; c<x; c++)
		{
			if(vety[i] == vetx[c]){
				cont++;
				
			}


		}
		if(cont == 0){
			printf("%i  ",vety[i]);
		}
	}

	int uni[x+y],cont2=x;
	for(i=0; i<x; i++){
		uni[i] = vetx[i];
		
	}
	for(i=0; i<y; i++){
		cont=0;
		for(c=0; c<x; c++){
			if(vety[i] == vetx[c])
				cont++;
		}
		if(cont == 0){
		 	uni[x+i] = vety[i];
		 	cont2++;
		 }
		 else
		 	x --;
		
	}

	printf("\n");
	printf("uniao de X com Y:\n");
	for(i=0; i<cont2; i++){
		printf("%i ",uni[i]);
	}


}
