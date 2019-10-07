#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	srand(time(NULL));
	printf("Quantos participante: ");
	scanf(" %i", &n);
	printf("\n");

	char nome[n][99],n2[n][99];
	int i,tempo[n],t2[n],c;
	
	for(i=0;i<n;i++){
		printf("Competidor %i: ",i+1);
		scanf(" %[^\n]s",nome[i]);
		printf("\n");
	}
	for(i=0;i<n;i++){
 		tempo[i]=10+rand()%100;
	}	
	printf("-----------------------------------\n");
	printf("Grid largada \t Tempo gasto:\n");
	for(i=0;i<n;i++){
		printf("%i. %s: \t %i\n",i+1,nome[i],tempo[i]);
		
	}
	printf("-----------------------------------\n");
	for(i=0;i<n;i++){
		t2[i]=tempo[i];

		for(c=0;c<99;c++){
			n2[i][c]=nome[i][c];
		}
	}
	

	int aux,x;
	char aux2;
	for(i=0;i<n;i++){
		for(c=0;c<n;c++){
			if(tempo[i]<tempo[c]){
				aux = tempo[c];
				tempo[c] = tempo[i];
				tempo[i]=aux;

				for(x=0;x<99;x++){
					aux2 = nome[c][x];
					nome[c][x]=nome[i][x];
					nome[i][x]=aux2;
				}
			}

		}

	}
	printf("posição final \t Tempo gasto:\n");
	for(i=0;i<n;i++){
		printf("%i. %s: \t %i\n",i+1,nome[i],tempo[i]);
		
	}
	printf("-----------------------------------\n");
	int cont=0,c2;
	char posin[n][99];
	printf("posições inalteradas: \n");
	for(i=0;i<n;i++){
		c2=0;
		for(c=0;c<n;c++){
			if(tempo[i]==t2[i]){
				for(x=0;x<99;x++){
					posin[cont][x]=n2[i][x];

			}
			cont++;
			for(x=0;x<cont;x++){
				printf("%s \n",posin[x]);
			}
			break;
			}
			
			
		}
		

	}
	int maior=-99,alter,menor=99;
	char mais[99], menos[99];
	for(i=0;i<n;i++){
		for(c=0;c<n;c++){
			if(t2[i]==tempo[c]){
				alter = i-c;
				if(alter > maior){
					maior = alter;
					//printf("maior %i\n",alter);
					for(x=0;x<99;x++){
						mais[x] = nome[c][x];
					}
				}
				if(alter < menor){
					menor = alter;
					//printf("menor %i\n",alter);
					for(x=0;x<99;x++){
						menos[x]=nome[c][x];
					}
				}
			} 

		}

	}
	printf("-----------------------------------\n");
	printf("Maior reação:\n");
	printf("%s \t %i\n",mais,maior);
	printf("-----------------------------------\n");
	printf("pioror reação:\n");
	printf("%s \t %i\n",menos,menor);
	printf("-----------------------------------\n");
}
