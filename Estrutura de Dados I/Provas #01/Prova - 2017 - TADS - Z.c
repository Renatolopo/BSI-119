#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Em produção

int main(){
	int jog, com, winner, cont_jog=0, cont_comp=0;
	int user[5], comp[5], aux;

	// Define a seed
	srand(time(NULL));

	// Randomiza os numeros dos vetores
	for(int i=0; i < 5; i++){
		user[i] = 1 + rand() % 13;
		comp[i] = 1 + rand() % 13;
	}
}
