#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(){
	int n;

	printf("Quantos competidores: ");
	scanf(" %i",&n);

	int tempo[n], p_inicial[n], p_final[n], dif[n];
	char nome[n][99];

	srand(time(NULL));

	for(int x=0; x<n; x++){
		printf("Nome do competidor %i: ", x+1);
		scanf(" %[^\n]s", nome[x]);
		
		tempo[x] = 10 + rand() % 91;
		p_inicial[x] = x+1;
		p_final[x] = x+1;
	}


	printf("-----------------------------------------------------------\n");
	printf("Grid de Largada:\tTempo Gasto\n");
	for(int x=0; x<n; x++){
		printf("%i. %s\t%i\n", p_inicial[x], nome[x], tempo[x]);
	}

	// Organização com base no tempo gasto;
	int aux_1;
	char aux_2[99];

	for(int x=0; x<n; x++){
		for(int y=0; y<x; y++){
			if(tempo[x] < tempo[y]){

				aux_1 = tempo[x];
				tempo[x] = tempo[y];
				tempo[y] = aux_1;

				strcpy(aux_2, nome[x]);
				strcpy(nome[x], nome[y]);
				strcpy(nome[y], aux_2);

				aux_1 = p_final[x];
				p_final[x] = p_final[y];
				p_final[y] = aux_1;
			}
		}
	}


	printf("-----------------------------------------------------------\n");
	printf("Grid de Chegada:\tTempo Gasto\n");
	
	for(int x=0; x<n; x++){
		printf("%i. %s\t%i\n", p_inicial[x], nome[x], tempo[x]);
	}

	printf("-----------------------------------------------------------\n");
	printf("Posições Inalteradas\n");

	for(int x=0; x<n; x++){
		if(p_inicial[x] == p_final[x])
			printf("%s\n", nome[x]);
	}

	// ##################### //
	// Maior ou menor reação //
	// ##################### //

	int maior, menor;
	for(int x=0; x<n; x++){
		dif[x] = p_final[x] - p_inicial[x];
	}

	for(int x=0; x<n; x++){
		if(x == 0){
			menor = dif[x];
			maior = dif[x];
			continue;
		}

		if(dif[x] > maior)
			maior = dif[x];

		if(dif[x] < menor)
			menor = dif[x];
	}

	printf("-----------------------------------------------------------\n");
	printf("Maior Reação (Mais posições ganhas)\n");

	for(int x=0; x<n; x++){
		if(maior == dif[x])
			printf("%s\t+%i\n", nome[x], dif[x]);
	}

	printf("-----------------------------------------------------------\n");
	printf("Pior Reação (Mais posições perdidas)\n");

	for(int x=0; x<n; x++){
		if(menor == dif[x])
			printf("%s\t%i\n", nome[x], dif[x]);
	}
}