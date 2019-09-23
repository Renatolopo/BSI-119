#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre 0 e N^2 (inclusive).
Todo número sorteado, obrigatoriamente deve ser exclusivo em sua linha e em sua coluna. Imprima a matriz em
formato de tabela (linhas/colunas)*/
int main()
{
	int n;
	printf("informe N: ");
	scanf(" %i",&n);
	srand(time(NULL));
	int matriz[n][n],vetor[n],num,i,j,c,cont,c2,retorno;
	for(i=0;i<n;i++){
		printf("\n");

		for(j=0;j<n;j++){
			//um vetor para guardar os valores da coluna
			for(c2=0;c2<i;c2++){
					vetor[c2]=matriz[c2][j];
					//printf("\nvetor = %i \n",vetor[c2]);
				}
			while(1){

				num = 0+ rand()%(n^2)+1;
				cont =0;
				retorno =0;
				for(c=0;c<j;c++){
					if(matriz[i][c]==num)
						cont ++;
				}
				for(c2=0;c2<i;c2++){
					if(num== vetor[c2])
						retorno ++;
				}
				if((cont==0)&&(retorno==0)){
					matriz[i][j]=num;
					printf("%i\t",matriz[i][j]);
					break;
				}

			}

		}

	}
}
