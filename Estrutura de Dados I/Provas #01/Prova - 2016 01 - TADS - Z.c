#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int cont=0, cont_win=0,flag, aux, troca;
	int user[9], a;

	srand(time(NULL));

	// randomiza as cartas do jogador
	for(int x=0; x<9; x++)
		user[x] = 1 + rand() % 13;
	
	// mostra as cartas do jogador
	printf("Cartas Recebidas: ");
	for(int x=0; x<9; x++)
		printf("%i ", user[x]);
	printf("\n");

	// Laço principal do jogo!
	while(1){
		flag = 1;
		cont_win = 0;
		
		// Ordena as cartas
		for(int x=0; x<9; x++){
			for(int y=0; y<x; y++){
				if(user[x] < user[y]){

					aux = user[x];
					user[x] = user[y];
					user[y] = aux;
				}
			}
		}


		// Mostra as Cartas ordenadas
		printf("Cartas Ordenadas: ");
		for(int x=0; x<9; x++){
			if(user[x] != 0)
				printf("%i ", user[x]);
		}

		printf("\n");

		for(int x=0; x<7; x++){
			if(user[x] == user[x+1] && user[x] == user[x+2] && user[x] > 0){
				cont++;

				printf("\nVocê possui a trinca: %i %i %i", user[x], user[x+1], user[x+2]);
				
				user[x] = 0;
				user[x+1] = 0;
				user[x+2] = 0;

				x += 2;
			}

			if(user[x]+1 == user[x+1] && user[x]+2 == user[x+2] && user[x] > 0){
				cont++;
				
				printf("\nVocê possui a trinca: %i %i %i", user[x], user[x+1], user[x+2]);

				user[x] = 0;
				user[x+1] = 0;
				user[x+2] = 0;
				
				x += 2;
			}
		}

		// Laço de saida
		for(int x=0; x<9; x++){
			if(user[x] == 0)
				cont_win++;
		}

		if(cont_win == 9){
			printf("\n\nVocê ganhou!\n");
			break;		
		}

		// Laço mostra as cartas restantes
		if(cont > 0){
			printf("\n\nCartas Restantes: ");
			for(int x=0; x<9; x++){
				if(user[x] != 0)
					printf("%i ", user[x]);
			}
		}
		
		// Laço para a troca de carta
		while(flag){

			printf("\n\nEscolha uma carta para trocar: ");
			scanf(" %i",&troca);

			for(a=0; a<9; a++){
				if(user[a] == troca){
					user[a] = 1 + rand() % 13;
					flag = 0;
					break;
				}
			}
			
			if(flag == 1)
				printf("\nCarta escolhida não existe na sua mão!");
		}

		printf("\n\nCartas trocadas: %i -> %i\n\n", troca, user[a]);
	}
}