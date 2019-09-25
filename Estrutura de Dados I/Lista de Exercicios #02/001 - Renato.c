#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, x;
	printf("informe  N: \n");
	scanf(" %i", &n);
	printf("informe X: \n");
	scanf(" %i", &x);
	int vet[n], i;
	srand(time(NULL));
	for(i=0; i<n; i++){
		vet[i] = rand()%x;;
	}
	int c;
	for(c=0; c<n; c++){
		printf("%i  ",vet[c]);
	}
	printf("\n");
	printf("numeros repetidos: \n");
	int i2,i3,cont;
	for(i2=0; i2<x; i2 ++){
		cont =0;
		for(i3=0; i3<n; i3++){
			if(i2 == vet[i3]){
				cont ++;
			}
			if(cont >= 2){
				printf("%i  ",vet[i3]);
				break;
			}
		}

	}
	
				
			
		
	
}
