#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int vet[1000];
	srand(time(NULL));
	int i,c,num,cont;
	srand(time(NULL));
	for(i=0;i<1000;i++){
		while(1){
			num=rand()%1000;
			cont=0;
			for(c=0;c<i;c++){
				if(num == vet[c])
					cont++;
			}
			if(cont == 0){
				vet[i]=num;
				printf("%i ",vet[i]);
				break;
			}
		}
	}
	for(i=0;i<1000;i++){
		vet[i] = vet[i];

	}
	printf("\n");
	printf("metodo bubble sort: \n");
	int aux;
	for(i=0;i<1000;i++){
		for(c=0;c<1000;c++){
			if(vet[c]>vet[i])
			{
				aux = vet[i];
				vet[i] = vet[c];
				vet[c] = aux;

			}
		}
	}
	for(i=0;i<1000;i++){
		printf("%i ",vet[i]);
	}
	int n, busca, max=999,min=0,cont2=0;
	printf("\n");
	printf("qual numero deseja encontrar: \n");
	scanf(" %i", &n);
	while(1){
		cont2++;
		busca = (max+min)/2;
		//printf("verificando....\n");
		if(vet[busca]==n){
			printf("%i encontrado em %i tentativas \n",n,cont2);
			break;
		}
		else if(vet[busca]<n){
			min = busca+1;
			//printf("menor....\n");
		}
		else if(vet[busca]>n){
			max = busca-1;
			//printf("maior....\n");
		}
		else if(min>max){
			printf("numero não existe\n");
			break;
		}
		else{
			printf("erro 404\n");}


	}

}
