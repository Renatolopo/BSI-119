#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int idade;
	char nome[99];
} Pessoa;

FILE* openfile(char a[]){
	FILE* arquivo = fopen(a,"rb+");
	if(!arquivo){
		arquivo = fopen(a,"wb+");
	}	
	if(!arquivo){
		printf("Não foi possivel abrir o arquivo\n");
		return 0;
	}
	return arquivo;
}


void setPesoa(FILE* arquivo){
	Pessoa p;
	printf("Nome: ");
	scanf(" %[^\n]s", p.nome);
	printf("Idade: ");
	scanf(" %i", &p.idade);
	fseek(arquivo,0,SEEK_END);
	fwrite(&p,sizeof(Pessoa),1,arquivo);
	
}
void getPesoa(FILE* arquivo){
	Pessoa p;
	fseek(arquivo,0,SEEK_SET);
	printf("---------------------------\n");
	
	while(fread(&p,sizeof(Pessoa),1,arquivo)){
		printf("Nome:%s \t idade: %i\n", p.nome, p.idade);
	}
}
int getTamanho(FILE* arquivo){
	Pessoa p;
	int cont = 0;
	fseek(arquivo,0,SEEK_SET);
	while(fread(&p,sizeof(Pessoa),1,arquivo)){
		cont++;
	}
	//printf("tamanho: %i\n",cont);
	return cont;

}
void getTroca(Pessoa p[], int i, int j){
	int ax;
	char aux[99];
	ax = p[i].idade;
	p[i].idade = p[j].idade;
	p[j].idade = ax;

	strcpy(aux, p[i].nome);
	strcpy(p[i].nome, p[j].nome);
	strcpy(p[j].nome, aux);


}
void getSelect(Pessoa p[], int c){
	printf("***** Ordenação Select ******\n");
	for(int i=0; i<c; i++){
		for(int j=0; j < c; j++){
			if(p[i].idade < p[j].idade){
				getTroca(p, i, j);
			}
		}
	}
	for(int i=0;i<c;i++){
		printf("Nome: %s\t Idade: %i\n",p[i].nome, p[i].idade);
	}

}
void getInsert(Pessoa p[], int c){
	printf("****** Ordenação Insert ******\n");
	int i;
	for(i=1;i<c;i++){
		int k = i;
		int cont = k-1;
		while(p[k].idade < p[cont].idade){
			getTroca(p, k, cont);
			cont --;
			k--;
			/*if(cont <= 0)
				break;*/
		}

	}
	for(i=0;i<c;i++){
		printf("Nome: %s\t Idade: %i\n",p[i].nome, p[i].idade);
	}
}


void getOrdena(FILE* arquivo, int op){
	int t = getTamanho(arquivo);
	Pessoa p[t];
	fseek(arquivo,0,SEEK_SET);
	int c=0;
	while(fread(&p[c],sizeof(Pessoa),1,arquivo)){
		c++;
	}
	/*for(int i = 0; i < c;i++){
		printf("%s\t %i\n",p[i].nome,p[i].idade);
	}*/
	switch(op){
		case 1:
			getSelect(p, c);
			break;
		case 2:
			getInsert(p, c);
			break;
	}


}


int main(){
	

	while(1){
		FILE* arquivo = openfile("Lista_de_pessoas.txt");
		printf("***** Main ********\n");
		printf("1-Cadastrar\t 2-Mostrar dados\t 3-sair\t 4-ordenar por seleção\t 5-ordna por inserção\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
				setPesoa(arquivo);
				
				break;
			case 2:
				getPesoa(arquivo);
				break;
			case 3:
				return 0;
				break;
			case 4:
				getOrdena(arquivo,1);
				break;
			case 5:
				getOrdena(arquivo,2);
				break;
		}
		fclose(arquivo);
		
	}

}