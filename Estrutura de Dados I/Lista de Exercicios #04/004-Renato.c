#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Produto{
	char descri[99];
	int codigo,	quanti;
	float valor;
	struct Produto* prox;
} Produto;
Produto* getAnterior(Produto* lista, Produto* novo){
	Produto* ant=NULL;
	while(lista){
		if(lista->valor <= novo->valor){
			if((ant == NULL)||(ant->valor <= lista->valor)){
				ant = lista;
			}
		}
		lista = lista->prox;
	}
	return ant;
}
Produto* getPoximo(Produto* lista, Produto* novo){
	Produto* prox = NULL;
	while(lista){
		if(lista->valor > novo->valor){
			if((prox == NULL)||(prox->valor > lista->valor)){
				prox = lista;
			}
		}
		lista = lista->prox;
	}
	return prox;
}
Produto* setProduto(Produto* l){
	Produto* p = (Produto*)malloc(sizeof(Produto));
	printf("Descrição: ");
	scanf(" %[^\n]s",p->descri);
	printf("Codigo: ");
	scanf(" %d",&p->codigo);
	printf("Quantidade em estoque: ");
	scanf(" %d",&p->quanti);
	printf("Preço: ");
	scanf(" %f",&p->valor);

	Produto* ant = getAnterior(l,p);
	Produto* prox = getPoximo(l,p);
	
	if(ant){
		ant->prox = p;
	}
	
	if(prox){
		p->prox = prox;
	}
	if((!l)||(p->valor < l->valor))
		return p;
	else 
		return l;
}
void getProduto(Produto* p){
	printf("**************************\n");
	while(p){
		printf("Descrição: %s\t Codigo: %i\t Quantidade: %i\t Preço: R$%.2f\n",p->descri, p->codigo, p->quanti, p->valor);
		p = p->prox;
	}
	printf("**************************\n");
}
Produto* getAnt(Produto* lista, Produto* p){
	while(lista){
		if(lista->prox == p){
			return lista;
		}
		lista = lista->prox;
	}
	return NULL;
	
}
Produto* getFree(Produto* p){
	printf("codigo do Produto que deseja remover: ");
	int c;
	scanf(" %d",&c);
	Produto* lista = p;
	Produto* l = p;
	while(p){
		if(c == p->codigo){
			Produto* ant = getAnt(lista,p);
			
			if(!ant){
				free(p);
				p = p->prox;
				printf("excluido com sucesso!\n ");
				return p;

			}else{
				ant->prox = p->prox;
			}
			free(p);	
			printf("excluido com sucesso!\n ");
			return l;
		}
		p = p->prox;
	}
	printf("Não encontrado.\n");
	return l;
}
int main(){
	Produto* p=NULL;
	while(1){
		printf("**************************\n");
		printf("1-cadastrar\n2-Imprimir\n3-Excluir\n4-sair\n");
		int r;
		scanf(" %d",&r);
		switch(r){
			case 1:
			p = setProduto(p);
			break;
			case 2:
			getProduto(p);
			break;
			case 3:
			p = getFree(p);
			break;
			case 4:
			return 0;
			break;

		}
	}
}
