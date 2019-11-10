#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Avinhao{
	char origem[99],destino[99];
	int num, quant;
	struct Avinhao* prox;
} Avinhao;
Avinhao* getFim(void* l){
	Avinhao* a = l;			
	while(a->prox){
		a = a->prox;
	}
	return a;
}
Avinhao* setAvinhao(Avinhao* ax){
	Avinhao* a=(Avinhao*)malloc(sizeof(Avinhao));
	printf("numero do voo: ");
	scanf(" %d",&a->num);
	printf("cidade de origem: ");
	scanf(" %[^\n]s",a->origem);
	printf("cidade de destino: ");
	scanf(" %[^\n]s",a->destino);
	printf("quantidade de passageiros: ");
	scanf(" %d",&a->quant);
 	 if(!ax){
 	 	a->prox = NULL;
 	 	return a;
 	 }

 	 Avinhao* fim = getFim(ax);
 	 fim->prox = a;
	return ax;
}
void getLista(Avinhao* a){
	printf("*********************************\n");
	while(a){
		
		printf("numero: %i\t origem: %s\t destino: %s\t quantidade de passageiro: %i\n",a->num, a->origem, a->destino, a->quant);
		a = a->prox;
	}
	printf("*********************************\n");
}
Avinhao* getDecola(Avinhao* a){
	printf("avinhão nº %i decolado\n",a->num);
	free(a);
	a = a->prox;

	return a;
}
Avinhao* getAborta(Avinhao* a){
	printf("*********************************\n");
	printf("Voo abortado!\n");
	printf("*********************************\n");
	Avinhao* ax=a;
	Avinhao* fim = getFim(a);
	fim->prox = a;
	a = a->prox;
	ax->prox =NULL;
	return a;
}
void getPrimeiro(Avinhao* a){
	printf("*********************************\n");

	printf("numero: %i\t origem: %s\t destino: %s\t quantidade de passageiro: %i\n",a->num, a->origem, a->destino, a->quant);
	
	printf("*********************************\n");

}
int main(){
	Avinhao* a=NULL;
	while(1){
		printf("*********************************\n");
		printf("1-adicionar um avinhão\n2-Listar os aviões aguardando na fila de decolagem\n3-Autorizar decolagem de avião\n4-Abortar a decolagem de um avião\n5-Exibir as características do primeiro avião da fila\n6-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			a=setAvinhao(a);
			break;
			case 2:
			getLista(a);
			break;
			case 3:
			a = getDecola(a);
			break;
			case 4:
			a=getAborta(a);
			break;
			case 5:
			getPrimeiro(a);
			break;
			case 6:
			return 0;
			break;

		}
	}
}
