#include <stdio.h>
#include <stdlib.h>

typedef struct Torrent{
	char nome[99],link[99];
	struct Torrent* prox;
} Torrent;

Torrent* setTorrent(Torrent *ant){
	Torrent* t=(Torrent*)malloc(sizeof(Torrent));

	printf("nome:\n");
	scanf(" %[^\n]s",t->nome);
	printf("link:\n");
	scanf(" %[^\n]s",t->link);
	if(ant == NULL){
		t->prox = NULL;
	}else{
		t->prox = ant;
	}
	return t;
}

Torrent* getTorrent(Torrent* t){
	printf("nome do torrent:\n");
	char nm[99];
	scanf(" %[^\n]s",nm);
	Torrent* ax=t;
	Torrent* ax2=t;
	int c=0;
	while(t){
		
		if(strcmp(nm,t->nome)==0){
			printf("nome: %s \t link: %s\n", t->nome, t->link);
	
			for(int i=1;i<c;i++){
				ax2 = ax2->prox;
			}
			
			ax2->prox = t->prox;
			t->prox = ax;

			return t;
		}else{
			t = t->prox;
			
		}
		c++;
	}
	printf("não existe nenhum torrent com esse nome.\n");
	return 0;
}
void getLista(Torrent *t){
	printf("***********************\n");
	while(t){
		printf("nome: %s \t *****link: %s\n", t->nome, t->link);
		t = t->prox;
	}
	printf("***********************\n");
}

int main(){
	Torrent *t = NULL;
	while(1){
		printf("***********************\n");
		printf("1-cadastra um Torrent\n2-buscar um torrent\n3-listar todos os torrent\n4-sair\n");
		int r;
		scanf(" %i", &r);
		switch(r){
			case 1:
			t = setTorrent(t);
			break;
			case 2:
			t = getTorrent(t);
			break;
			case 3:
			getLista(t);
			break;
			case 4:
			return 0;
			break;
		}
	}
}
