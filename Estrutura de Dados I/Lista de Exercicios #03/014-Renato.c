#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[99];
	int codigo,cargah,quantv,nma;
} Disiplinas;

typedef struct{
	char nome[99];
	int matricula[10];
} Alunos;
void setDisiplina(Disiplinas d[],int c){
	printf("nome da disciplina:\n");
	scanf(" %[^\n]s",d[c].nome);
	printf("codigo:\n");
	scanf(" %i",&d[c].codigo);
	printf("carga horarira:\n");
	scanf(" %i",&d[c].cargah);
	printf("quantidade de vagas:\n");
	scanf(" %i",&d[c].quantv);
}
void setAluno(Alunos a[], int c,Disiplinas d[],int k){
	printf("nome do aluno:\n");
	scanf(" %[^\n]s",a[c].nome);
	printf("matriculas\n");
	int x=0;
	while(1){
		printf("nome da disiplina (digite 0 para sair):\n");
		char aux[99];
		scanf(" %[^\n]s",aux);
		int cont=0;
		for(int i=0;i<k;i++){
			if((strcmp(aux,d[i].nome)==0)&&(d[i].nma < d[i].quantv)&&(d[i].cargah < 40)){
				a[i].matricula[x] = d[i].codigo;
				d[i].nma += 1;
				cont++;
			}
		}
		if(cont==0)
			printf("erro de matricula\n");
		if(aux[0]=='0')
			break;
		
		x++;
	}
}
void imprimir(Alunos a[], int c, Disiplinas d[],int x){
	printf("--------------------------------------------------------------------------\n");
	for(int i=0;i<x;i++){
		
		printf("Disciplina: %s    \t   %ih/a     \t    vagas: %i/%i\n",d[i].nome, d[i].cargah, d[i].nma, d[i].quantv);
		printf("Aluno:              \t Carga horarira\n");
		for(int j=0;j<c;j++){
			for(int k=0;k<10;k++){
				if(d[i].codigo==a[j].matricula[k]){
					printf("%s      \t \n",a[j].nome);
				}
			}
		}

	}
	printf("--------------------------------------------------------------------------\n");
	
}

int main()
{
	Disiplinas d[50];
	for(int i=0;i<50;i++){
		d[i].nma=0;
	}
	Alunos a[50];
	int c=0,x=0;


	while(1){
		printf("1 - Cadastrar Disciplina\n2 - Cadastrar Aluno\n3 - Imprimir as Disciplinas e Alunos Matriculados\n4 - Sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			setDisiplina(d,c);
			c++;
			break;
			
			case 2:
			setAluno(a,x,d,c);
			x++;
			break;
			case 3:
			imprimir(a,c,d,x);
			break;
			case 4:
			return 0;
			break;
		}
		


	}
}
