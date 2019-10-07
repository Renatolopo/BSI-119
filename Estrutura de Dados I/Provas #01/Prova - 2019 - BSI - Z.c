#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	int tabela[5][5], sorteio[25];
	int n, cont, aux, num, win;

	srand(time(NULL));

	// Gera a cartela 5x5 com numeros randomicos não repetitivos
	for(int x=0; x<5; x++){
		for(int y=0; y<5; y++){
			
			// Define n para o alcançe de numero a ser gerado
			if(x == 0){
				n = 1;
			} else if(x == 1){
				n = 16;
			} else if(x == 2){
				n = 31;
			} else if(x == 3){
				n = 46;
			} else if(x == 4){
				n = 61;
			}

			// Gera numeros aleatorio não repetitivos
			tabela[x][y] = n + rand() % 15;
			while(1){
				cont = 0;

				for(int c=0;c<y;c++)
					if(tabela[x][y] == tabela[x][c])
						cont++;

				if(cont == 0){
					break;
				}
				
				tabela[x][y] = n + rand() % 15;
			}
		}
	}

	// Zera a maatriz sorteio
	for(int i=0; i<25; i++){
		sorteio[i] = 0;
	}

	// Laço principal do sorteio
	while(1){
		win = 0;

		// Ordena a Tabela em ordem crescente
		for(int x=0; x<5; x++){
			for(int y=0; y<5; y++){
				for(int z=0; z<y; z++){
					if(tabela[x][y] < tabela[x][z]){

						aux = tabela[x][y];
						tabela[x][y] = tabela[x][z];
						tabela[x][z] = aux;

					}
				}
			}
		}

		// Mostra a tabela ordenada
		printf("\n=============== Cartela ===============\n");
		for(int x=0; x<5; x++){
			for(int y=0; y<5; y++){
				if(tabela[x][y] == 0)
					printf("  XX\t");
				else if (tabela[x][y] < 10)
					printf("  0%i\t", tabela[x][y]);
				else
					printf("  %i\t", tabela[x][y]);
			}

			printf("\n");
		}

		// Randomiza um numero não repetitivo para o sorteio
		num = 1 + rand() % 75;
		while(1){
			cont=0;

			for(int c=0; c<75; c++)
				if(num == sorteio[c])
					cont++;

			if(cont == 0)
				break;

			num = 1 + rand() % 75;

		}

		// Adiciona o numero sorteado em um vetor teste
		for (int i=0; i<75; i++){
			if(sorteio[i] == 0){
				sorteio[i] = num;
				break;
			}
		}

		// Verifica se o numero se encontra na cartela e o substitiu
		for(int x=0; x<5; x++){
			for(int y=0; y<5; y++){
				if(num == tabela[x][y])
					tabela[x][y] = 0;

				if(tabela[x][y] == 0)
					win++;
			}
		}

		// Condição da saida
		if(win == 25)
			break;
	}

	printf("\n=======================================\n");
	printf("============ - # BINGO # - ============\n");
	printf("=======================================\n");
}