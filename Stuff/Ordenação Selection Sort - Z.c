#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int x[10];

	srand(time(NULL));

	for(int i=0; i < 10; i++)
		x[i] = 1 + rand() % 10;

	printf("\nVetor Original\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);

	// ordenação Selection Sort

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

	printf("\nVetor Ordenados Slection Sort\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);
}