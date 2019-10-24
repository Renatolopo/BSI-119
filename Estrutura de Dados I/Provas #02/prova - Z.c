#include <string.h>
#include <stdio.h>

typedef struct{

	int cod_pessoa;
	char nome[99];

}Pessoa;

typedef struct{

	int cod_grupo;
	char desc[200];

}Grupo_social;

typedef struct{

	int cod_pessoa_a;
	int cod_pessoa_b;
	int cod_grupo_relacionamento;

}Relacionamento;


void cadastra_pessoa(Pessoa p[], int cont){

	printf("\nInsira o nome da pessoa: ");
	scanf(" %[^\n]s", p[cont].nome);

	p[cont].cod_pessoa = cont;

	printf("\n");
}

void cadastra_relacionamento(Pessoa p[], Grupo_social g[], int cont){
	char nome_a[99], nome_b[99];
	int teste, cod_a, cod_b;

	while(1){
		
		printf("Insira o primeiro nome: ");
		scanf(" %[^\n]s", nome_a);

		for(int x=0; x<cont; x++){
			teste = strcmp(nome_a, p[x].nome);
			
			if(teste == 0){
				cod_a = p[x].cod_pessoa;
				break;
			}
		}

		printf("\nNome não encontrado\nInsira um nome novamente!\n");
	}

	while(1){
		
		printf("Insira o segundo nome: ");
		scanf(" %[^\n]s", nome_b);

		for(int x=0; x<cont; x++){
			teste = strcmp(nome_b, p[x].nome);
			
			if(teste == 0){
				cod_b = p[x].cod_pessoa;
				break;
			}
		}

		printf("\nNome não encontrado\nInsira um nome novamente!\n");
	}

	







}

void relatorio_pessoas(Pessoa p[], int cont){
	for(int x=0; x<cont; x++){
		printf("\nCódigo: %i\nnome: %s", p[x].cod_pessoa, p[x].nome);
	}
	
	printf("\n\n");
}

int main(){
	
	Pessoa p[100];
	Grupo_social g[100];
	Relacionamento r[250];

	int cont_p=0, cont_r=0, cont_g=0;
	int opcao, flag=1;
	char nome[99];

	while(flag){
		printf("[ 1 ] - Cadastro de pessoa\n");
		printf("[ 2 ] - Cadastro de Relacionamento\n");
		printf("[ 3 ] - Relatório: Pessoas\n");
		printf("[ 4 ] - Relatório: Grupos Sociais\n");
		printf("[ 5 ] - Relatório: Relacionamentos\n");
		printf("[ 6 ] - Pessoa mais popular\n");
		printf("[ 7 ] - Pessoa mais influente\n");
		printf("[ 8 ] - Sair\n");

		printf("\nInsira uma das opções: ");
		scanf(" %i",&opcao);

		switch(opcao){
			case 1:
				cadastra_pessoa(p, cont_p);
				cont_p++;
				break;
			case 2:
				cadastra_relacionamento(p, g, cont_r);
				cont_r++;
				break;
			case 3:
				relatorio_pessoas(p, cont_p);
				cont_p++;
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				flag = 0;
				break;
		}
	}
}