#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int k;
	printf("informe o numero de candidatos: ");
	scanf(" %i", &k);
	char can[k+1][99];
	printf("\n-----------------------------\n");
	int i;
	
	for(i=0;i<k;i++){
		printf("informe o nome do %i candidato:",i+1);
		scanf(" %s",can[i]);
	}
	int votos[k+2],n=0;
	for(i=0;i<k+2;i++){
		votos[i]=0;
	}
	int c=0;
	printf("\n");
	while(n<=k){
		c++;
		printf("\nvote:\n");
		scanf("%i",&n);
		if(n<0)
			votos[k+1]++;
		else if(n<=k)
			votos[n]++;

	}
	int maior=0,x;
	char vencedor[99];
	for(i=0;i<k+2;i++){
		if(votos[i]>maior){
			maior=votos[i];
			for(x=0;x<99;x++){
			vencedor[x]=can[i-1][x];
			}
		}

	}
	int por=(maior*100)/c;
	printf("\n------------------------------\n");


	for(i=0;i<k;i++){
		printf("%s\t%i\n",can[i],votos[i+1]);
	}
	printf("Braco\t%i\n",votos[0]);
	printf("nulo\t%i\n",votos[k+1]);
	printf("\n-----------------------------\n");
	printf("\n quantidade de votos: %i\n",c);
	printf("votos nulos: %i\n",votos[k+1]);
	printf("votos brancos: %i\n",votos[0]);
	printf("vencedor: %s\n",vencedor);
	printf("o percetual do vencedor: %i%%", 
	por);
}
