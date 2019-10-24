#include <string.h>
#include <stdio.h>

// Define as structs
typedef struct{

	char nome_pessoa[99];
	int cod_pessoa;

}Pessoa;

typedef struct{

	char desc_grupo[99];
	int cod_grupo;
}Grupo;

typedef struct{

	int cod_pessoa_a;
	int cod_pessoa_b;
	int cod_grupo_relacionamento;

}Relacionamento;


// Define as funções
void cadastro_pessoa(Pessoa p[], int x){
	int flag=1, teste;
	char nome[99];

	while(flag){
		int cont=0;

		printf("Insira o nome da pessoa: ");
		scanf(" %[^\n]s", nome);

		if(x > 0){
			for(int y=0; y<x; y++){
				teste = strcmp(nome, p[y].nome_pessoa); 
				if(teste != 0)
					cont++;
			}
			
			if(cont == x)
				flag = 0;

		} else {
			break;
		}

	}

	strcpy(p[x].nome_pessoa, nome);
	p[x].cod_pessoa = x;

	// printf("%s\n%i", p[x].nome_pessoa, p[x].cod_pessoa);

	printf("\n");
}

void cadastro_grupo(){
}

void cadastro_relacionamento(Relacionamento r[], int x){
}


// Código main
int main(){

	Relacionamento r[99];
	Pessoa p[99];
	Grupo g[99];

	int opcao, flag=1;
	int cont_p=0, cont_r=0;

	while(flag){
		printf("[ 1 ] - Cadastro de pessoa: ");
		printf("[ 2 ] - Cadastro de Relacionamento");
		scanf("	%i",&opcao);

		switch(opcao){
			case 0:
				flag = 0;
				break;
			case 1:
				cadastro_pessoa(p, cont_p);
				cont_p++;
				break;
			case 2:
				cadastro_relacionamento(r, cont_r);
				cont_r++;
				break;
		}
	}
}