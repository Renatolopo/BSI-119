#include <string.h>
#include <stdio.h>

typedef struct{

	char titulo[99], autor[99], area[99];
	int ano, loc;

}Livro;

int main(){

	int quant, comp, cont=1;

	printf("Insira a quantidade de livros a serem cadastrados: ");
	scanf(" %i",&quant);

	Livro cadastro[quant];

	for(int x=0; x < quant; x++){

		// printf("Insira o título do livro: ");
		// scanf(" %[^\n]s", cadastro[x].titulo);

		// printf("Insira o nome do autor do livro: ");
		// scanf(" %[^\n]s", cadastro[x].autor);

		printf("Insira área de conhecimento do livro: ");
		scanf(" %[^\n]s", cadastro[x].area);

		// printf("Insira o ano do livro: ");
		// scanf(" %i", &cadastro[x].ano);

	}

	// verifica a quantidade de areas do conhecimento existem
	for(int i=1; i < quant; i++){
		if(strcmp(cadastro[0].area, cadastro[i].area) != 0)
			cont++;
	}

}