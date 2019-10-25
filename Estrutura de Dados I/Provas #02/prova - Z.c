#include <string.h>
#include <stdio.h>

// Define as structs
typedef struct{

	char nome_pessoa[99];
	int cod_pessoa;

}Pessoa;

typedef struct{

	int cod_pessoa_a;
	int cod_pessoa_b;
	int cod_grupo_relacionamento;

}Relacionamento;

typedef struct{

	char desc_grupo[99];
	int cod_grupo;
}Grupo;


// Define as funções

// Função para verificar se a pessoa está cadastrada
int verifica_pessoa(Pessoa p[], int x, char nome[]){

	int cont=0, teste;

	if(x > 0){
		for(int y=0; y<x; y++){
			teste = strcmp(nome, p[y].nome_pessoa);
			if (teste != 0)
				cont++;
		}

		if(cont == x)
			return 0;
		else
			return 1;
	} 
}

// Função para buscar o código da pessoa 
int busca_cod_pessoa(Pessoa p[], int x, char nome[]){

	int cont=0, teste;
	
	for(int y=0; y<x; y++){
		teste = strcmp(nome, p[y].nome_pessoa);
		if(teste == 0)
			return p[y].cod_pessoa;
		else
			cont++;
	}

	if(cont == x)
		return -1;
}

// Função busca código do grupo
int busca_grupo(Grupo g[], int z, char desc[]){
	int cont=0, teste;

	for(int x=0; x<z; x++){
		teste = strcmp(desc, g[x].desc_grupo);
		if(teste == 0){
			return g[x].cod_grupo;
		} else {
			cont++;
		}
	}

	if(cont == z)
		return -1;
}

// função para mostrar o nome da pessoa
void mostra_nome(Pessoa p[], int x, int cod){
	for(int i=0; i<x; i++){
		if(cod == p[i].cod_pessoa)
			printf("Nome: %s\n", p[i].nome_pessoa);
	}
}

// função oara mostrar a descrição do grupo
void mostra_desc(Grupo g[], int z, int cod){
	for(int i=0; i<z; i++){
		if(cod == g[i].cod_grupo){
			printf("Descrição: %s\n", g[i].desc_grupo);
			break;
		}
	}
}

// Função para cadastrar pessoas
int cadastro_pessoa(Pessoa p[], int x){
	char nome[99];
	int resultado;

	printf("Insira o nome da pessoa: ");
	scanf(" %[^\n]s", nome);

	resultado = verifica_pessoa(p, x, nome);

	if(resultado != 1){
		strcpy(p[x].nome_pessoa, nome);
		p[x].cod_pessoa = x;

		// printf("%s\n%i", p[x].nome_pessoa, p[x].cod_pessoa);
	} else {
		printf("\nNão foi possivel concluir o cadastro pois o nome já existe!\n");
		return 0;
	}


	printf("\n");
}

// Função Cadastra Grupo
int cadastro_grupo(Grupo g[], int z, char desc[]){

	strcpy(g[z].desc_grupo, desc);
	g[z].cod_grupo = z;
	// printf("grupo cadastrado com sucesso\n");
	return z+1;
}

// Função cadastra relacionamento
int cadastro_relacionamento(Pessoa p[], int x, Relacionamento r[], int y, Grupo g[], int z){
		
	int resultado, cod_a, cod_b, cont_g;
	char nome[99], desc[99];

	printf("Insira o nome da pessoa A: ");
	scanf(" %[^\n]s", nome);

	resultado = busca_cod_pessoa(p, x, nome);

	if(resultado >= 0){
		cod_a = resultado;

		printf("Insira o nome da pessoa B: ");
		scanf(" %[^\n]s", nome);

		resultado = busca_cod_pessoa(p, x, nome);

		if(resultado >= 0){
			cod_b = resultado;

			if(cod_a != cod_b){
				r[y].cod_pessoa_a = cod_a;
				r[y].cod_pessoa_b = cod_b;

				printf("Insira a descrição do grupo: ");
				scanf(" %[^\n]s", desc);

				resultado = busca_grupo(g, z, desc);
				
				if(resultado >= 0){
					
					r[y].cod_grupo_relacionamento = resultado;
					printf("\n");
			
				} else {
					
					cont_g = cadastro_grupo(g, z, desc);
					resultado = busca_grupo(g, cont_g, desc);
					
					r[y].cod_grupo_relacionamento = resultado;
					// printf("%i codigo do grupo\n", r[y].cod_grupo_relacionamento);
					printf("\n\n");
					return cont_g;
				}

			} else {
				printf("Não é possivel cadastrar um relacionamento de duas pessoas iguais\n\n");
				return -1;
			}
		} else {
			printf("Pessoa B não encontrada!\n\n");
			return -1;
		}
	} else {
		printf("Pessoa A não encontrada!\n\n");
		return -1;
	}
}

// função mostra o relatório das pessoas cadastradas
void relatorio_pessoa(Pessoa p[], int x){
	for(int y=0; y<x; y++){
		printf("\nNome: %s", p[y].nome_pessoa);
	}

	printf("\n\n");
}

// função mostra o relatório de grupos sociais
void relatorio_grupos_sociais(Grupo g[], int z){
	int cont=0;

	for(int i=0; i<z; i++){
		if(g[i].cod_grupo == 0 && cont == 0){
			printf("Codigo: %i\nDescrição: %s\n\n", g[i].cod_grupo, g[i].desc_grupo);
			cont++;
		} else if(g[i].cod_grupo != 0){
			printf("Codigo: %i\nDescrição: %s\n\n", g[i].cod_grupo, g[i].desc_grupo);
		} 
	}
}

void relatorio_relacionamentos(Pessoa p[], int x, Relacionamento r[], int y, Grupo g[], int z){
	for(int i=0; i<y; i++){
		printf("\n");
		mostra_nome(p, x, r[i].cod_pessoa_a);
		mostra_nome(p, x, r[i].cod_pessoa_b);
		mostra_desc(g, z, r[i].cod_grupo_relacionamento);
		printf("\n");
	}
}

void pessoa_popular(Pessoa p[], int x, Relacionamento r[], int y){
	int cont=0, cont_a, cod;
	char nome[99];

	for(int i=0; i<x; i++){
		cont_a = 0;

		for(int j=0; j<y; j++){
			if(p[i].cod_pessoa == r[j].cod_pessoa_a || p[i].cod_pessoa == r[j].cod_pessoa_b)
				cont_a++;
		}

		if(cont == 0){
			cont = cont_a;
			strcpy(nome, p[i].nome_pessoa);
		} else {
			if(cont_a > cont)
				strcpy(nome, p[i].nome_pessoa);
		}
	}

	printf("Pessoa mais popular: %s\n", nome);
}

void pessoa_influente(Pessoa p[], int x, Relacionamento r[], int y, int z){
	
	int cont=0, cont_a;
	char nome[99];

	for(int i=0; i<x; i++){
		cont_a = 0;
		
		for(int j=0; j<y; j++){
			if(r[j].cod_grupo_relacionamento == j){
				if(p[i].cod_pessoa == r[j].cod_pessoa_a || p[i].cod_pessoa == r[j].cod_pessoa_b )
					cont_a++;
			}
		}

		if(cont == 0){
			cont = cont_a;
			strcpy(nome, p[i].nome_pessoa);
		} else {
			if(cont_a > cont)
				strcpy(nome, p[i].nome_pessoa);
		}
	}

	printf("Pessoa mais influente: %s\n", nome);	
}

// Código main
int main(){

	Relacionamento r[99];
	Pessoa p[99];
	Grupo g[99];

	int cont_p=0, cont_r=0, cont_g=0;
	int flag=1, opcao, result;

	while(flag){
		printf("[ 0 ] - Sair\n");
		printf("[ 1 ] - Cadastro de pessoa\n");
		printf("[ 2 ] - Cadastro de Relacionamento\n");
		printf("[ 3 ] - Relatório: Pessoas\n");
		printf("[ 4 ] - Relatório: Grupos sociais\n");
		printf("[ 5 ] - Relatório: Relacionamentos\n");
		printf("[ 6 ] - Pessoa mais popular\n");
		printf("[ 7 ] - Pessoa mais influente\n");

		printf("Selecione uma das opções acima: ");
		scanf("	%i",&opcao);

		switch(opcao){
			case 0:
				flag = 0;
				break;
			case 1:
				result = cadastro_pessoa(p, cont_p);
				if(result == 0){
					cont_p--;
				}

				cont_p++;
				break;
			case 2:
				result = cadastro_relacionamento(p, cont_p, r, cont_r, g, cont_g);
				if (result == -1){
					cont_r--;
				} else {
					cont_g++;
				}

				cont_r++;
				break;
			case 3:
				relatorio_pessoa(p, cont_p);
				break;
			case 4:
				relatorio_grupos_sociais(g, cont_g);
				break;
			case 5:
				relatorio_relacionamentos(p, cont_p, r, cont_r, g, cont_g);
				break;
			case 6:
				pessoa_popular(p, cont_p, r, cont_r);
				break;
			case 7:
				pessoa_influente(p, cont_p, r, cont_r, cont_g);
				break;


		}
	}
}