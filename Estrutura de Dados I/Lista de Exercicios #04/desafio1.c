#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
	int num;
	struct Pilha* prox;
} Pilha;

Pilha* setPilha(Pilha* ant){
	Pilha* p=(Pilha*)malloc(sizeof(Pilha));

	printf("numero:\n ");
	scanf(" %i",&p->num);
	
	p->prox = ant;
	return p;
}
void getPosi(Pilha *p, int i){
	int c=0;
	while(p){
		if(c == i)
			printf(" %i\n",p->num);
		c++;
		p = p->prox;
	}
}
void getPilha(Pilha *p){
	printf("***************\n");
	Pilha *ax = p;
	int c=0;
	while(p){
		c++;
		p = p->prox;
	}
	for(int i=c;i>=0;i--){
		getPosi(ax,i);
	}
	printf("***************\n");
}
int main(){
	Pilha* p=NULL;
	while(1){
		printf("***************\n");
		printf("1-cadastrar\n2-listar\n3-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			p = setPilha(p);
			break;
			case 2:
			getPilha(p);
			break;
			case 3:
			return 0;
			break;
		}
	}
}
