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

	// Laço principal do jogo
	while(1){

		// Ordena os vetores
		for(int x=0; x < 5; x++){
			for(int y=0; y < 5; y++){
				// Ordena o vetor user
				if(user[x] < user[y]){

					aux = user[x];
					user[x] = user[y];
					user[y] = aux;
				}

				// Ordena o vetor comp
				if(comp[x] < comp[y]){

					aux = comp[x];
					comp[x] = comp[y];
					comp[y] = aux;
				}
			}
		}

		printf("- - - - - - - - - - - - - - - - - - - -\n");

		// Mostra as cartas do jogador
		printf("\n\n============== Suas cartas =============\n");
		for(int x=0; x < 5; x++){
			if(user[x] != 19)
				printf("%i\t", user[x]);
		}

		// Mostra as cartas do computador
		printf("\n\n========= Cartas do computador =========\n");
		for(int x=0; x < 5; x++){
			if(comp[x] != 19)
				printf("%i\t", comp[x]);
		}

		// Pede ao usuário sua jogada
		printf("\n\nEscolha uma carta: ");
		scanf(" %i",&jog);

		// Escolhe a carta do computador

		printf("Carta jogada pelo computador: %i", com);

}
