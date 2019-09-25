#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo 
entre X e Y (inclusive).
Imprima-a em formato de tabela, e os valores que compõem a
 coluna que resulta na maior soma, e os valores da
linha que resulta na menor soma.*/

int main()
{
	int n,x,y;
	printf("informe N:\n ");
	scanf(" %i",&n);
	printf("informe X:\n");
	scanf(" %i",&x);
	printf("informe Y:\n");
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
	int maior=0,mai[n],mai2[n],acum,c;
	for(i=0;i<n;i++){
		acum =0;
		for(j=0;j<n;j++){
			acum += matriz[j][i];
			mai[j] = matriz[j][i];
		}
		if(acum > maior){
			maior = acum;
			for(c=0;c<n;c++){
				mai2[c] = mai[c]; 
			}

		}
	}
	int menor = 9999,men[n],men2[n];
	for(i=0;i<n;i++){
		acum =0;
		for(j=0;j<n;j++){
			acum += matriz[i][j];
			men[j] = matriz[i][j];
		}
		if(acum < menor){
			menor = acum;
			for(c=0;c<n;c++){
				men2[c]=men[c];
			}
		}
	}





	printf("\n");
	printf("maiores: ");
	for(i=0;i<n;i++){
		printf("%i ",mai2[i]);
	}
	printf("\n");
	printf("menores: ");
	for(i=0;i<n;i++){
		printf("%i ",men2[i]);
	}



}
