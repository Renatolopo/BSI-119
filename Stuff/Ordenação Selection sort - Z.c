#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int x[10];

	srand(time(NULL));

	for(int i=0; i < 10; i++)
		x[i] = rand() % 21;

	printf("\nVetor Original\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);

	// ordenação

	int aux;

	for(int i=0; i < 10; i++){
		for(int j=0; j < 10; j++){
			if(x[j] > x[i]){

				aux = x[i];
				x[i] = x[j];
				x[j] = aux;

			}
		}
	}

	printf("\nVetor Ordenados\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);
}