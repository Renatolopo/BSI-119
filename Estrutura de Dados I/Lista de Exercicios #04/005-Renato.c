#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
	int num;
	struct Lista* prox;
	struct Lista* ant;
} Lista;
Lista* getIn(Lista* l){
	while(l->ant){
		l = l->ant;
	}
	return l;
}
Lista* getFim(Lista* l){
	while(l->prox){
		l = l->prox;	
	}
	return l;
}
Lista* setLista(Lista* l, int r){
	Lista* nv = (Lista*)malloc(sizeof(Lista));
	printf("Numero: ");
	scanf(" %i",&nv->num);
	if(r == 1){
		if(l){
			Lista* in = getIn(l);
			nv->prox = in;
			in->ant = nv;
			nv->ant = NULL;
		}else{
			nv->prox = NULL;
			nv->ant = NULL;
		}
		return nv;
	}else if(r == 2){
		if(l){
			Lista* fim = getFim(l);
			nv->ant = fim;
			nv->prox =NULL;
			fim->prox = nv;
		}else{
			nv->prox = NULL;
			nv->ant = NULL;
		}
		return nv;
	}
	return nv;
}


void getInicio(Lista* lis){
	Lista* l = getIn(lis);
	printf("******************************\n");
	while(l){
		printf("%i\n",l->num);
		l = l->prox;
	}
	printf("******************************\n");
}
void getLsFim(Lista* l){
	Lista* fim = getFim(l);
	printf("******************************\n");
	while(fim){
		printf("%i\n",fim->num);
		fim = fim->ant;
	}
	printf("******************************\n");
}
Lista* freeInicio(Lista* l){
	Lista* in = getIn(l);
	Lista* ax = in;
	free(in);
	ax = ax->prox;
	ax->ant = NULL;
	printf("inicio excluido com sucesso!\n");
	return ax;

}
Lista* freeFim(Lista* l){
	Lista* fim = getFim(l);
	Lista* ax = fim;
	free(fim);
	ax = ax->ant;
	ax->prox = NULL;
	printf("fim excluido com sucesso!\n");
	return ax;
}
int main(){
	Lista* l = NULL;
	while(1){
		printf("******************************\n");
		printf("1-cadastrar inicio\n2-cadastrar final\n3-excluir inicio\n4-excluir final\n5-imprimir apartir do inicio\n6-imprimir apartir do final\n7-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			l = setLista(l,1);
			break;
			case 2:
			l = setLista(l,2);
			break;
			case 3:
			l = freeInicio(l);
			break;
			case 4:
			l = freeFim(l);
			break;
			case 5:
			getInicio(l);
			break;
			case 6:
			getLsFim(l);
			break;
			case 7:
			return 0;
			break;
		}
	}
}
