#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Gere aleatoriamente uma matriz N x N de inteiros 
sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela (linhas e colunas) 
e informe a localização do maior e do menor valor da matriz.*/
int main()
{
	int n,x,y;
	printf("informe N:\n");
	scanf(" %i",&n);
	printf("informe X:\n ");
	scanf(" %i",&x);
	printf("informe Y: \n");
	scanf(" %i",&y);
	srand(time(NULL));
	int matriz[n][n],i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			matriz[i][j]=x+rand()%y;
			printf("%i\t",matriz[i][j]);
		}
	}
	int maior=0, menor=y,indmaior,indmenor,indmaior2,indmenor2;
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			if(matriz[i][j] > maior){
				maior = matriz[i][j];
				indmaior = i;
				indmaior2 = j;
			}
			if(matriz[i][j]<menor){
				menor = matriz[i][j];
				indmenor = i;
				indmenor2 = j;
			}
		}
	}
	printf("\n");
	printf("menor número na linha %i coluna %i.\n",indmenor,indmenor2);
	printf("maior número na linha %i coluna %i.\n",indmaior,indmaior2);

}
