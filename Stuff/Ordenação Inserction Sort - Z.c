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

	// ordenação Insertion Sort

	int j, aux;

	for(int i=0; i < 10; i++){
		j = i;

		while((j != 0) && (x[j] > x[j - 1])){

			aux = x[j];
			x[j] = x[j - 1];
			x[j - 1] = aux;
			j--;

		}
	}

	printf("\nVetor Ordenado Insertion Sort\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);
}
