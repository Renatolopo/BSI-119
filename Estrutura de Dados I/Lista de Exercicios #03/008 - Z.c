#include <stdio.h>

typedef struct{

	char titulo[99], autor[99], area[99];
	int ano, loc;

}Livro;

int main(){

	len = 5;

	Livro l[len];

	for(int x=0; x<len; x++){
		printf("Titulo: ");
		scanf(" %[^\n]s", l[x].titulo);
		printf("Autor: ");
		scanf(" %[^\n]s", l[x].autor);
		printf("Àrea do conhecimento: ");
		scanf(" %[^\n]s", l[x].area);
		printf("Ano: ");
		scanf(" %i",&l[x].ano);

		printf("\n");
	}

	for(int x=0; x<len, x++){
		
	}
}