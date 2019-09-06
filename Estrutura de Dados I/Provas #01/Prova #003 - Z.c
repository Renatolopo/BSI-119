#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
		for(int x=0; x < 5; x++){
			if(comp[x] > jog && comp[x] < 14){
				com = comp[x];
				break;
			} else
				com = comp[0];
		}

		printf("Carta jogada pelo computador: %i", com);

		// Condição de ganhar a rodada e consequencias
		if(jog > com){
			printf("\n- - - - - - - - - - - - - - - - - - - -");
			printf("\nVocê ganhou a rodada!\n");

			// Converte a carta escolhida pelo usuário para 19
			for(int x=0; x < 5; x++){
				if(user[x] == jog){
					user[x] = 19;
					break;
				}
			}

			// Randomiza uma nova carta para o computador
			for(int x=0; x < 5; x++){
				if(comp[x] == com){
					comp[x] = 1 + rand() % 13;
					break;
				}
			}

		} else if(com > jog){
			printf("\n- - - - - - - - - - - - - - - - - - - -");
			printf("\nO computador ganhou a rodada!\n");

			// Converte a carta escolhida pelo computador para 19
			for(int x=0; x < 5; x++){
				if(comp[x] == com){
					comp[x] = 19;
					break;
				}
			}

			// Randomiza uma nova carta para o jogador
			for(int x=0; x < 5; x++){
				if(user[x] == jog){
					user[x] = 1 + rand() % 13;
					break;
				}
			}
		}

		for(int x=0; x < 5; x++){
			if(user[x] == 19)
				cont_jog++;

			if(comp[x] == 19)
				cont_comp++;
		}

		if(cont_jog == 5){
			winner = 1;
			break;
		}

		if(cont_comp == 5){
			winner = 0;
			break;
		}
	}

	if(winner == 1){
		printf("\n\n- - - - - - - - - - - - - - - - - - - -\n");
		printf("O jogador venceu o jogo!\n");
		printf("- - - - - - - - - - - - - - - - - - - -\n");
	} else {
		printf("\n\n- - - - - - - - - - - - - - - - - - - -\n");
		printf("O computador venceu o jogo!\n");
		printf("- - - - - - - - - - - - - - - - - - - -\n");
	}

}
