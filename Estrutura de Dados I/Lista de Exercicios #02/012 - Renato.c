#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, x;
	printf("informe o tamanho do vetor: ");
	scanf(" %i",&n);
	printf("informe o ate a onde os numeros serão sorteados: ");
	scanf(" %i",&x);
	int vet[n],i,cont=n,c;
	printf("\n");
	srand(time(NULL));

	int cm=0,maior=0,menor=x,nm=0,nme,c2;
	for(i=0;i<n;i++)
	{
		c2=0;
		vet[i] = rand()%x;
		printf("%i ",vet[i]);
		cm=0;
		for(c=0;c<i;c++){
			
			if(vet[i]==vet[c]){
				c2 ++;
				cm ++;
			}
			if(cm > maior){
				maior = cm;
				nm = vet[i];
			}
			if(cm < menor){
				menor = cm;
				nme = vet[i];
			}

		}
		if(c2 != 0)
			cont --;

	}
	printf("\n");
	printf("Quantos números diferentes foram sorteados: %i \n",cont);
	printf("O número mais vezes sorteado: %i \n",nm);
	int mais=0,nrep=0;
	printf("O número menos vezes sorteado: ");
	cont=0;
	c2 =0;
	int aux =0;
	for(i=0;i<0;i++)
	{
		mais = 0;
		aux = 0;
		for(c=0;c<i;c++){
			if(vet[i] == vet[c]){
				
				aux ++;
			}
		}
		if(mais == 1){
			nrep ++;
			printf(" %i",vet[i]);
		}
		if(aux != 0)
			cont = cont + aux +1;

	}
	int naore = n - cont;
	if(nrep == 0)
		printf("%i ",nme);
	printf("\n");
	printf("Quantidade de números não-repetitivos sorteados: %i \n",naore);

	

}
