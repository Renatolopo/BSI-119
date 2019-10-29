#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[99], profi[99], cpf[20];
	float renda;
} Associado;
int validaCpf(char cpf[99]){
	int aux[11],c=0;
	for(int i=0;i<20;i++){
		if((cpf[i] >= '0')&&(cpf[i] <= '9')){
			aux[c] = cpf[i] -'0';
			c++;
		}
	}
	int acm=0;
	for(int i=0;i<9;i++){
		acm += aux[i]*(10-i);
	}
	acm = acm*10;
	if(acm%11 ==aux[9]){
		acm=0;
		for(int i=0;i<10;i++){
			acm += aux[i]*(11-i);
		}
		acm = acm*10;
		if(acm%11 == aux[10]){
			return 1;
		}
	}
	
	return 0;
}
int cpfRepetido(char aux[99], Associado a[], int x){
	for(int i=0; i<x;i++){
		if(strcmp(aux,a[i].cpf)==0){
			//printf("cpf repetido");
			return 1;
		}
	}
	return 0;

}
void setAssociado(Associado a[], int x){
	printf("nome:\n");
	scanf(" %[^\n]s",a[x].nome);
	while(1){
		printf("CPF:\n");
		scanf(" %[^\n]s",a[x].cpf);
		if((validaCpf(a[x].cpf)==1)&&(cpfRepetido(a[x].cpf,a, x)==0))
			break;
		else
			printf("cpf invalido\n");
	}
	printf("Profissão:\n");
	scanf(" %[^\n]s",a[x].profi);
	printf("renda:\n");
	scanf(" %f",&a[x].renda);
}
void getLista(Associado a[], int x, int in){
	printf("===========================\n");
	printf("Nome  \t \t CPF  \t  Profissão  \t\t  renda\n");
	for(int i=in;i<x;i++){
		printf("%s \t %s \t %s \t %.f\n",a[i].nome, a[i].cpf, a[i].profi, a[i].renda);
	}
	printf("===========================\n");
}
void getNome(Associado a[], int x){
	char n[99];
	printf("nome:\n");
	scanf(" %[^\n]s",n);
	for(int i=0;i<x;i++){
		if(strcmp(n,a[i].nome)==0){
			getLista(a,i+1,i);
		}
	}
}
void getAcima(Associado a[], int x){
	printf("informe o valor:\n");
	float v;
	scanf(" %f", &v);
	for(int i=0; i<x;i++){
		if(a[i].renda > v){
			getLista(a,i+1,i);
		}
	}
}
void getMaior(Associado a[], int x){
	float maior =0;
	int gi;
	for(int i=0;i<x;i++){
		if(a[i].renda > maior){
			maior = a[i].renda;
			gi=i;
		}
	}
	getLista(a,gi+1,gi);

}

int main(){
	Associado a[50];
	int x=0;
	while(1){
		printf("===========================\n");
		printf("1-cadastrar\n2-listar todos os associados\n3-listar apartir de busca pelo nome\n4-Listagem dos associados com renda acima do valor X\n5-Listagem do associado com maior renda\n6-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			setAssociado(a,x);
			x++;
			break;
			case 2:
			getLista(a,x,0);
			break;
			case 3:
			getNome(a,x);
			break;
			case 4:
			getAcima(a,x);
			break;
			case 5:
			getMaior(a,x);
			break;

			case 6:
			return 0;
			break;

		}
	}
}
