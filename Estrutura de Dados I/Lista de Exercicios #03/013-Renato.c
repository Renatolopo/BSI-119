#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[99], email[99], tel[99], grupo[99];
} Contato;

int validaEmail(char e[99]){
	int c1=0,c2=0;
	for(int i=0;i<20;i++){
		if(e[i]=='@'){
			c1 ++;
		}
		if(e[i]=='.'){
			c2 ++;
		}
	}
	if((c1==1)&&(c2!=0)){
		return 1;
	}else{
		return 0;
	}
}
void grupos(Contato c[], int x){
	printf("--------------------------\n");
	for(int i=0;i<x;i++){

		int cont=0;
		for(int j=0;j<i;j++){
			if(strcmp(c[i].grupo,c[j].grupo)==0){
				cont ++;
			}
		}
		if(cont==0){
			printf("%s\n",c[i].grupo);
		}

	}
	printf("--------------------------\n");
}

void setContato(Contato c[],int x){
	printf("==============================================\n");
	printf("nome:\n");
	scanf(" %[^\n]s",c[x].nome);
	
	while(1){
		printf("Email:\n");
		scanf(" %s",c[x].email);
		if(validaEmail(c[x].email)==1){
			break;
		}else{
			printf("email invalido\n");
		}
	}
	printf("telefone:\n");
	scanf(" %[^\n]s",c[x].tel);
	printf("Grupo de afinidade\n");
	if(x>0)
		grupos(c,x);
	scanf(" %[^\n]s",c[x].grupo);
	printf("==============================================\n");
}
void getGrupo(Contato c[], int x){
	char aux[99];
	if(x>0)
		grupos(c,x);
	printf("nome do grupo:\n");
	scanf(" %[^\n]s",aux);
	int cont=0;
	printf("--------------------------\n");

	for(int i=0;i<x;i++){
		if(strcmp(aux,c[i].grupo)==0){
			printf("%s\n",c[i].nome);
			cont ++;
		}
	}
	if(cont==0){
		printf("não há nenhum grupo com esse nome\n");
	}

	printf("--------------------------\n");
}

void getContato(Contato c[], int x){
	char aux[99];
	while(1){
		printf("informe o email do contato:\n");
		scanf(" %[^\n]s",aux);
		if(validaEmail(aux)==1)
			break;
		else
			printf("email invalido\n");

	}
	int cont=0;
	printf("--------------------------\n");
	for(int i=0;i<x;i++){
		if(strcmp(aux,c[i].email)==0){
			cont++;
			printf("nome:%s\nemail:%s\ntelefone:%s\ngrupo de afinidade:%s\n",c[i].nome, c[i].email, c[i].tel, c[i].grupo);
		}
	}
	if(cont==0){
		printf("não há nenhum email com esse nome\n");
	}
	printf("--------------------------\n");

}

int main(){
	Contato c[99];
	int cont =0;
	while(1){
		int r;
		printf("1-cadastrar contato\n2-consultar contatos de um grupo\n3-consultar um contato especifico\n4-sair\n");
		scanf(" %i",&r);
		switch(r){
			case 1:
			setContato(c,cont);
			cont++;
			break;

			case 2:
			getGrupo(c,cont);
			break;

			case 3:
			getContato(c,cont);
			break;

			case 4:
			return 0;
			break;
		}

	}
}
