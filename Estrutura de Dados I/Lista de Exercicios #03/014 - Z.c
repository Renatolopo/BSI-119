#include <string.h>
#include <stdio.h>

typedef struct{

	char nome_disciplina;
	int cod_discplina;
	int carga_horaria;
	int qtd_vagas;

}Disciplinas;

typedef struct{

	char nome_aluno[99];
	int matriculas[10];

}Aluno;

// Declara as funções

// Cadastra disciplina
void cadastra_disciplina(Disciplinas d[], int x){

	printf("Nome: ");
	scanf(" %s", d[x].nome_disciplina);
	printf("Carga horária: ");
	scanf(" %s", d[x].carga_horaria);
	printf("Quantidade de vagas: ");
	scanf(" %s", d[x].qtd_vagas);

	d[x].cod_discplina = x;
}

// cadastra aluno
int cadastrar_aluno(Disciplinas d[], int x, Aluno a[], int y){

	char nome_a[99], nome_d[99];
	int cont=0, teste, z;

	printf("Insira o nome do aluno: ");
	scanf(" %[^\n]s", nome_a);

	printf("\n========== Matriculas ==========");
	printf("Insira o nome da matéria: ");
	scanf(" %[^\n]s", nome_d);

	for(int i=0; i<x; i++){
		teste = strcmp(nome_d, d[x].nome_disciplina);
		if(teste == 0){
			cont++;
			z = i;
		}
	}

	if(cont > 0)
		cadastra_disciplina(d, x);	

}

int main(){

	Disciplinas d[99];
	Alunos a[99];

	int flag=1, cont_d=0, cont_a=0, opcao;

	while(flag){
		printf("[ 1 ] - Cadastrar disciplina\n");
		printf("[ 2 ] - Cadastrar aluno\n");
		printf("[ 3 ] - Relatório disciplina/aluno\n");
	
		switch(opcao){
			case 1:
				cadastra_disciplina(d, cont_d);
				cont_d++;
				break;
			case 2:
				cadastrar_aluno(d, cont_d, a, cont_a);
				cont_a++; 
			case 3:
				flag=0;
				break;
		
		}
	}
}