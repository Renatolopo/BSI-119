#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int k;
	printf("informe o tamanho do vetor:\n ");
	scanf(" %i", &k);
	int v[k],i,c,n,cont;
	srand(time(NULL));
	for(i=0;i<k;i++){
		while(1){
			n=rand()%k;
			cont = 0;
			for(c=0;c<i;c++){
				if(n == v[c])
					cont++;

			}
			if(cont == 0)
			{
				v[i]=n;
				printf("%i ",v[i]);
				break;
			}
		}
	}
	int vet[k];
	for(i=0;i<k;i++){
		vet[i] = v[i];

	}
	printf("\n");
	printf("metodo bubble sort: \n");
	int aux;
	for(i=0;i<k;i++){
		for(c=0;c<k;c++){
			if(v[c]>v[i])
			{
				aux = v[i];
				v[i] = v[c];
				v[c] = aux;

			}
		}
	}
	for(i=0;i<k;i++){
		printf("%i ",v[i]);
	}
	printf("\n");
	printf("metodo selection sort: \n");
	int menor;
	for(i=0;i<k;i++){
		menor = vet[i];
		for(c=0;c<k;c++){
			if(vet[c]>menor){
				aux = menor;
				menor = vet[c];
				vet[c] = aux;
			}
		}
		vet[i] = menor;

	}
	for(i=0;i<k;i++){
		printf("%i ",vet[i]);
	}

}
