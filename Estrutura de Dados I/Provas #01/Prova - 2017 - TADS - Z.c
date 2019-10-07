#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Em produção

int main(){

	int aux, jogada, cont_a, i, j, cont_j, cont_c;
	int user[5], comp[5];
	int flag=1;

	// Define a seed
	srand(time(NULL));

	// Randomiza os numeros dos vetores
	for(int i=0; i < 5; i++){
		user[i] = 1 + rand() % 13;
		comp[i] = 1 + rand() % 13;
	}

	//Laço principal do jogo;	
	while(1){
		cont_j = 0;
		cont_c = 0;
		flag = 1;

		// Verificação de win!
		for(int x=0; x<5; x++){
			if(user[x] == 0)
				cont_j++;
			if(comp[x] == 0)
				cont_c++;
		}

		if(cont_j == 5){
			printf("\nO Usuário venceu!\n");
			break;
		}

		if(cont_c == 5){
			printf("\nO Computador venceu!\n");
			break;
		}

		// Ordena o vetor comp
		for(int x=0; x<5; x++){
			for(int y=0; y<x; y++){
				if(comp[x] < comp[y]){

					aux = comp[x];
					comp[x] = comp[y];
					comp[y] = aux;

				}
			}
		}

		// Mostra as cartas do usuário
		printf("\nCartas do usuário:\n");
		for (int i = 0; i < 5; ++i){
			if(user[i] > 0){
				printf("%i\t", user[i]);
			}
		}

		// Mostra as cartas do usuário
		printf("\n\nCartas do Computador:\n");
		for (int i = 0; i < 5; ++i){
			if(comp[i] > 0){
				printf("%i\t", comp[i]);
			}
		}

		printf("\n");


		// Laço para pedir ao usuário uma carta
		while(flag){

			// pede ao usuário para jogar uma carta
			printf("\nEscolha uma carta para jogar: ");
			scanf(" %i",&jogada);

			for(j=0; j<5; j++){
				if(jogada == user[j]){
					// user[j] = 0;
					flag = 0;
					break;
				}

				if(j == 4){
					printf("Jogada Inválida!\n");
				}
			}
		}

		// Seleciona a jogada do computador
		cont_a = 0;
		for(int x=0; x<5; x++){
			if(comp[x] > jogada){
				printf("Carta jogada pelo computador: %i\n", comp[x]);
				printf("Computador venceu a rodada\n");
				user[j] = 1 + rand() % 13;
				comp[x] = 0;
				break;
			}

			if(comp[x] > 0){
				cont_a++;
			}

			if(cont_a == 1){
				i = x;
			}

			if(x == 4){
				printf("Carta jogada pelo computador: %i\n", comp[i]);
				printf("Usuário venceu a rodada\n");
				comp[i] = 1 + rand() % 13;
				user[j] = 0;
			}
		}

		printf("-------------------------------------");
	}

	printf("-------------------------------------\n");

}
