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

	for(int j = 9; j <= 1; j--){
		for(int i=0; i > j; i++){
			if(x[i] > x[i + 1]){
				
				aux = x[i];
        		x[i] = x[i+1]; 
        		x[i+1] = aux; 
			
			}
		}
	}

	printf("\nVetor Ordenado Bubble sort\n");
	for(int i=0; i < 10; i++)
		printf("%i\n", x[i]);
}