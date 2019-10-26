#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int carta,naipe;
} Baralho;
int validaCarta(int carta, int naipe, Baralho b[], int x){
	for(int i=0; i<x; i++){
		if((carta == b[i].carta)&&(naipe == b[i].naipe)){
			return 0;
		}
	}
	return 1;
}

void setJogador(Baralho b[], int x, int j[4][2]){
	for(int i=0;i<4;i++){
		while(1){
			j[i][0]= 1+rand()%13;
			j[i][1]= 1+rand()%4;
			if(validaCarta(j[i][0], j[i][1], b, x)==1){
				b[x].carta = j[i][0];
				b[x].naipe = j[i][1];
				x++;
				break;
			}
		}
	}
}
int getVencedor(int j[4][2]){
	int c=0;
	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){

			if(j[i][0] == j[x][0]){
				c++;
			}

		}
	}
	if(c == 8)
		return 1;
	c=0;
	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){

			if(j[i][1] == j[x][1]){
				c++;
			}

		}
	}
	if(c == 4)
		return 1;
	c=0;
	for(int i=0;i<4;i++){
		for(int x=0;x<4;x++){
			if((j[i][0] == j[x][0]-1)&&(j[i][1] != j[x][1])){
				for(int k=0;k<4;k++){
					if((j[x][0] == j[k][0]-1)&&(j[k][1] != j[x][1])&&(j[i][1] != j[k][1])){
						c++;
					}
				}
			}
		}
	}
	if(c!= 0)
		return 1;
	return 0;
	
}
void novaCarta(int j[4][2], Baralho b[], int x){
	while(1){
		int carta, naipe;
		int n = 0+rand()%3;
		carta = 1+rand()%13;
		naipe = 1+rand()%4;
		if(validaCarta(carta, naipe, b, x)==1){
			j[n][0] = carta;
			j[n][1] = naipe;
			b[x].carta = carta;
			b[x].naipe = naipe;
			break;
		}
	}
}

int main(){
	srand(time(NULL));
	Baralho b[52];
	int jogador1[4][2], jogador2[4][2];
	int x=0;
	setJogador(b, x, jogador1);
	setJogador(b, x, jogador2);
	while(1){
		printf("=====================================\n");
		printf("Jogador 1 cartas:\n");
		for(int i=0;i<4;i++){
			printf("%i de ",jogador1[i][0]);
			switch(jogador1[i][1]){
				case 1:
				printf("paus\n");
				break;
				case 2:
				printf("ouro\n");
				break;
				case 3:
				printf("espada\n");
				break;
				case 4:
				printf("copas\n");
				break;

			}
		}
		printf("\n\nJogador 2 cartas:\n");
		for(int i=0;i<4;i++){
			printf("%i de ",jogador2[i][0]);
			switch(jogador2[i][1]){
				case 1:
				printf("paus\n");
				break;
				case 2:
				printf("ouro\n");
				break;
				case 3:
				printf("espada\n");
				break;
				case 4:
				printf("copas\n");
				break;

			}
		}
		if(getVencedor(jogador1)==1){
			printf("jogador 1 venceu\n");
			break;
		}else if(getVencedor(jogador2)==1){
			printf("jogador 2 venceu\n");
			break;
		}
		getchar();
		novaCarta(jogador1, b, x);
		
		novaCarta(jogador2, b, x+1);
		x++;
		x++;
		
		if(x >= 52){
			printf("empate\n");
			
			
		}
		
	}
}
