#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int n, x,y;
	printf("informe N: \n");
	scanf(" %i",&n);
	printf("informe X: \n");
	scanf(" %i", &x);
	printf("informe Y: \n");
	scanf(" %i", &y);
	srand(time(NULL));
	printf("vetor gerado: \n");

	int vet[n];
	int i,maior=0, menor=y,maid,meid;
	for(i=0; i<n; i++){
		vet[i] = x + rand()%y;
		printf("%i ",vet[i]);
		if(vet[i] > maior){
			maior = vet[i];
			maid = i;
		}
		if(vet[i] < menor){
			menor = vet[i];
			meid = i;
		}

	}
	printf("\n");
	printf("maior numero na posição de indice %i e menor numero na posição de indice %i. \n",maid, meid);
}
