#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int k,x,y;
	int soma = 0,cont=0;
	float media;
	while(1){
		printf("digite K: \n");
		scanf(" %i", &k);
		if((k > 0) && (k < 1000))
			break;
	}
	printf("digite X: \n");
	scanf(" %i", &x);
	printf("digite Y: \n");
	scanf(" %i", &y);
	printf("**********************************\n");
	printf("numeros gerados: \n");

	srand(time(NULL));

	int	 v[k], i, cp=0, ci=0;
	int maior=0,menor=y; 

	for(i=0; i<k; i++){
		v[i] = x + rand()%y;
		if(v[i]%2 == 0)
			cp ++;
		else
			ci ++;
		if(v[i] > maior)
			maior = v[i];
		if(v[i] < menor)
			menor = v[i];

		soma += v[i];
		media = (float) soma/k;

	}



	for(i=0; i<k; i++){
		
		printf("%i ",v[i]);
		
		if(v[i] == maior)
			printf("maior");
		

		if(v[i] == menor)
			printf("menor");

		if(v[i] > media)
			cont ++;



		printf("\n");
		

	}
	printf("**********************************\n");
	printf("%i numeros pares e %i numeros impar.\n", cp, ci);
	printf("media = %.2f \n",media);
	printf("%i numeros acima da media. \n", cont);
	printf("**********************************\n");


}
