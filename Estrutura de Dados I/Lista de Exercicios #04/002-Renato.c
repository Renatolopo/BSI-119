#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Artigo{
	char autor[99], titulo[99], ac[99];
	int ano;
	struct Artigo* prox;
} Artigo;

Artigo* setArtigo(Artigo* ant){
	printf("****************************\n");
	Artigo* a =(Artigo*)malloc(sizeof(Artigo));
	printf("autor:\n");
	scanf(" %[^\n]s",a->autor);
	printf("titulo:\n");
	scanf(" %[^\n]s",a->titulo);
	printf("area de conhecimento:\n");
	scanf(" %[^\n]s",a->ac);
	printf("ano:\n");
	scanf(" %i",&a->ano);
	if(ant == NULL){
		a->prox = NULL;
	}else{
		a->prox = ant;
	}
	return a;
}
int getCont(Artigo* a){
	int c=0;
	while(a){
		c++;
		a = a->prox;
	}
	printf("****************************\n");
	printf("\n%i Artigos alocados na lista\n",c);	
	return c;
}
void getMeio(Artigo* a){
	int c = 0;
	Artigo* ax=a;
	while(a){
		c++;
		a = a->prox;
	}
	int m = c/2,x=0;
	while(ax){
		if(x == m){
			printf("%s esta mais próximo do meio da lista\n",ax->titulo);
		}
		ax = ax->prox;
		x++;
	}
}
void getImprime(Artigo *a){
	printf("titulo: %s autor: %s área de conhecimento: %s ano de publicação: %i\n",a->titulo, a->autor, a->ac, a-> ano);
}
void getLista(Artigo* a){
	printf("****************************\n");	
	while(a){
		getImprime(a);
		a = a->prox;
	}
	printf("****************************\n");	
}
void getIntervalo(Artigo *a){
	int a1,a2;
	printf("de: \n");
	scanf(" %i",&a1);
	printf("ate: \n");
	scanf(" %i",&a2);
	while(a){
		if((a->ano >= a1)&&(a->ano <= a2)){
			getImprime(a);
		}
		a = a->prox;
	}

}
Artigo* getAnterior(Artigo* l, Artigo* alvo){
	while(l){
		if(l->prox == alvo)
			return l;
		l = l->prox;
	}
	
	return  l ;
}

Artigo* getExcluir(Artigo* a){
	printf("Titulo do artigo que deseja apagar:\n");
	char t[99];
	scanf(" %[^\n]s",t);
	
	Artigo* x=a;
	
	if(strcmp(t,a->titulo)==0){
		free(a);
		printf("excluido com sucesso\n");
		a = a->prox;
		return a;
	}
	else{
		while(a){
			if(strcmp(t,a->titulo)==0){
				Artigo* anterior = getAnterior(x,a);
				anterior->prox = a->prox;
				free(a);
				printf("excluido com sucesso\n");
				return x;
			}
			a = a->prox;
	
		}
	}
	printf("titulo não encontrado\n");
	return x;
}
int main(){
	Artigo *a = NULL;
	while(1){
		printf("****************************\n");						
		printf("1-cadastrar\n2-quantidades de lista\n3-artigo mais próximo possíveldo meio da lista\n4-listar todos\n5-listar artigos entre um intervalo de tempo\n6-excluir artigo\n7-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			a = setArtigo(a);
			break;
			case 2:
			getCont(a);
			break;
			case 3:
			getMeio(a);
			break;
			case 4:
			getLista(a);
			break;
			case 5:
			getIntervalo(a);
			break;
			case 6:
			a = getExcluir(a);
			break;
			case 7:
			return 0;
			break;

	}

	}
}
