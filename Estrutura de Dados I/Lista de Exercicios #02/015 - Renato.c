#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main (void)
{
	int n,x,y;
	printf("informe o tamanho do vetor: ");
	scanf(" %i", &n);
	printf("informe x: ");
	scanf(" %i", &x);
	printf("informe Y: ");
	scanf(" %i", &y);

	int vet[n],i,acu=0,c,repetido=0,maisrepetido=0,moda;
	srand(time(NULL));
	for(i=0;i<n;i++){
		vet[i]= x+rand()%y;
		repetido =0;
		for(c=0;c<i;c++){
			if(vet[i]==vet[c]){
				repetido ++;
			}


		}
		if(repetido > maisrepetido){
				maisrepetido = repetido;
				moda = vet[i];
			}
		printf("%i ",vet[i]);
		acu += vet[i];
	}
	float media = (float) acu/n;
	printf("\n");
	printf("media = %.2f \n", media);
	printf("moda = %i \n", moda);
	int aux;
	for(i=0;i<n;i++){
		for(c=0;c<i;c++){
			if(vet[i] < vet[c]){
				aux = vet[i];
				vet[i] = vet[c];
				vet[c] = aux;
			}
		}
		
	}
	int aux2 = n / 2;
	float mediana;
	printf("\n");
	//for(i=0;i<n;i++){
		//printf("%i ",vet[i]);
		
	//}
	if(n%2 == 0){
		mediana = (float) (vet[aux2]+vet[(aux2-1)])/2;
	}
	else{
		mediana = (float) vet[aux2];
	}
	printf("\n");
	printf("mediana = %.2f \n",mediana);
	aux =0;
	for(i=0;i<n;i++){
		aux += (vet[i]-media)*(vet[i]-media);
	}
	aux2 = (aux*1)/n;
	double desvio = aux2 ^ 1/2;
	printf("\n");
	printf("desvio padrão = %.2f \n",desvio);
	return 0;



}
