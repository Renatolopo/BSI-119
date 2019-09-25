#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;
	while(1){
		printf("informe x (maior que 10 e par): \n");
		scanf(" %i", &x);
		if((x%2 == 0)&&(x >= 10)){
			break;
		}
	}
	srand(time(NULL));
	int num[x],i,cont,c,n;
	for(i=0;i<x;i++){
		cont=0;
		n = rand()%100;
		for(c=0;c<i;c++){
			if(n == num[c]){
				cont++;
			}
		}
		if(cont == 0){
			num[i] = n;
			printf("%i ",num[i]);
		}

	}
	printf("\n");
	printf("retorno: \n");
	int retorno[x];
	for(i=0;i<x/2;i++){
		retorno[i] = num[(x/2)+i];
		printf("%i ",retorno[i]);
	}
	for(i=0;i<x/2;i++){
		retorno[(x/2)+i] = num[i];
		printf("%i ",retorno[(x/2)+i]);

	}
}
