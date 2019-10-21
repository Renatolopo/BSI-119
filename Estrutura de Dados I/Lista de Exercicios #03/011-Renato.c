#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char descring[99];
	char quanting[99];
} Ingrediente;


typedef struct{
	char nome[90],dificuldade;
	Ingrediente i[30];
	int qi;
	char tempo[99];
} Receita;

Ingrediente setIngrediente(){
	Ingrediente novo;

	printf("descrição:\n");
	scanf(" %[^\n]s",novo.descring);
	printf("quantidade: \n");
	scanf(" %[^\n]s",novo.quanting);
	return novo;
	

}


 void setReceita(Receita r1[],int x){
	 printf("======================================================\n");
 	printf("nome: \n");
 	scanf(" %[^\n]s", r1[x].nome);
 	printf("dificuldade (d-m-f):\n");
 	scanf(" %c",&r1[x].dificuldade);
 	printf("ingredientes\n");
 	while(1){
		r1[x].i[r1[x].qi] = setIngrediente();
		r1[x].qi++; 
		printf("tem mais ingredientes? s/n\n");
		char res;
		scanf(" %c",&res);
		if(res == 'n'){
			break;
		}
	}
 	printf("tempo:\n");
 	scanf(" %[^\n]s",r1[x].tempo);
 	printf("======================================================\n");

 	

}

int consulta(char x[99],char y[99]){
	int cont=0;
	for(int i=0;i<3;i++){
		if(x[i]==y[i]){
			cont ++;
		}
	}
	if(cont == 3)
		return 1;
	else
		return 0;
}

void getReceita(Receita r[], int c){
	char rece[99];
	printf("nome da receita:\n");
	scanf(" %[^\n]s",rece);
	int retorno=0;
	printf("======================================================\n");
	for(int i=0; i<c;i++){
		
		if(consulta(rece,r[i].nome)==1){
			retorno ++;
			printf("nome: %s tempo: %s Dificuldade: %c  \nIngredientes\n",r[i].nome, r[i].tempo, r[i].dificuldade);
			for(int x=0;x<r[i].qi;x++){
				printf("%s de %s\n",r[i].i[x].quanting, r[i].i[x].descring);
			}

		}
		
	}
	if(retorno==0){
		printf("essa receita não existe\n");
	}
	printf("======================================================\n");
}
void getIngrediente(Receita r[], int c){
	char ing[99];
	printf("nome do ingrediente:\n");
	scanf(" %[^\n]s",ing);
	int retorno =0;
	printf("======================================================\n");
	for(int i=0; i<c;i++){
		for(int j=0; j<r[i].qi;j++){
			if(consulta(ing,r[i].i[j].descring)==1){
				retorno ++;
				printf("nome: %s tempo: %s Dificuldade: %c  \nIngredientes\n",r[i].nome, r[i].tempo, r[i].dificuldade);
				for(int x=0;x<r[i].qi;x++){
					printf("%s de %s\n",r[i].i[x].quanting, r[i].i[x].descring);
				}

			}
		}
	}
	if(retorno == 0){
		printf("\nnão existe nehuma receita com esse ingrediente\n");
	}
	printf("======================================================\n");

}

int main()
{
	Receita r[50];
	int c=0;
	while(1){
		printf("1-cadastrar receita\n2-consultar uma receita\n3-Consultar todas as receitas que possuem um determinado ingrediente\n4-sair\n");
		int res;
		scanf(" %i",&res);
		switch(res){
			case 1: 
			setReceita(r,c);
			c++;
			break;

			case 2:
			getReceita(r,c);
			break;

			case 3:
			getIngrediente(r,c);
			break;

			case 4:
			return 0;
			break;
		}
		
 		
 		

	}
}

