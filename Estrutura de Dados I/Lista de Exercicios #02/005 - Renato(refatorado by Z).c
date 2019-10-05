#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x, y;

	printf("informe X: ");
	scanf(" %i", &x);
	printf("informe Y: ");
	scanf(" %i", &y);

	srand(time(NULL));
	
	int vetx[x], vety[y];
	int c, num, cont; 
	
	// Randomiza tipos inteiros não repetidos Vetx
	for(int i=0; i<x; i++){
		vetx[i] = rand()% x+y+1;

		while(1){
			cont = 0;

			for(c=0;c<i;c++)
				if(vetx[i] == vetx[c])
					cont++;

			if(cont == 0){
				break;
			}
			
			vetx[i] = rand()% x+y+1;
		}
	}

	// Randomiza tipos inteiros não repetidos Vety
	for(int i=0; i<y; i++){
		vety[i] = rand() % x+y+1;

		while(1){
			cont = 0;

			for(c=0; c<i; c++)
				if(vety[i] == vety[c])
					cont++;

			if(cont == 0){
				break;
			}

			vety[i] = rand() % x+y+1;
		}
	}

	// Mostra os valores de vetx  e vety
	printf("Vetor X: ");
	for(int i=0; i<x; i++)
		printf("%i ", vetx[i]);

	printf("\n");

	printf("Vetor Y: ");
	for(int i=0; i<y; i++)
		printf("%i ", vety[i]);
	
	// 
	printf("\nInterseção de X e Y");
}
