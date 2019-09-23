#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y;
	printf("informe a quantidade de caixas: \n");
	scanf(" %i",&x);
	printf("informe a quantidade de clientes na fila: \n");
	scanf(" %i",&y);
	int caixa[x],clientes[y],i;
	printf("Para cada um dos %i caixas, imforme o tempo gasto para registrar cada autenticação.\n",x);
	for(i=0;i<x;i++){
		printf("[%i]: ",i);
		scanf(" %i",&caixa[i]);
		printf("\n");
	}
	printf("para cada um dos %i clientes, informe a quantidade de documentos para a altenticação.\n",y);
	for(i=0;i<y;i++){
		printf("[%i]: ",i);
		scanf(" %i",&clientes[i]);
		printf("\n");

	}
	int atendido[x],tempo[x];
	for(i=0;i<x;i++){
		tempo[i]=caixa[i]*clientes[i];
		atendido[i]=1;
	}
	int r=x,menor,gi;
	while(1){
		if(r>=y)
			break;
		menor=999;
		for(i=0;i<x;i++){
			if(tempo[i]<menor){
				menor=tempo[i];
				gi=i;
			}

		}
		tempo[gi]+=caixa[gi]*clientes[r];
		atendido[gi]++;
		r++;
	}


	for(i=0;i<x;i++){
		printf("caixa %i atendeu %i clientes em %i minutos no total.\n",i,atendido[i],tempo[i]);
	}
}
