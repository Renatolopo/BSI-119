#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[99],hospedagem;
	int numhr;
} Cliente;

void setCliente(Cliente c[], int x){
	printf("nome: \n");
	scanf(" %[^\n]s",c[x].nome);
	printf("possui hospedagem [s/n]\n");
	scanf(" %c",&c[x].hospedagem);
	printf("número de horas de acesso:\n");
	scanf(" %i", &c[x].numhr);
}
int maior(Cliente c[], int x){
	int maior=0;
	for(int i=0;i<x;i++){
		if(c[i].numhr > maior){
			maior = c[i].numhr;
		}
	}
	return maior;
}
void getExtrato(Cliente c[], int x){
	printf("=================================================\n");
	printf("nome \t\t horas de acesso \t hospedagem \t valor bruto \t valor do desconto \t valor final\n ");
	float fat=0;
	for(int i=0;i<x;i++){
		printf("%s\t %i horas \t\t\t %c \t\t ", c[i].nome, c[i].numhr, c[i].hospedagem);
		float aux=80;
		if(c[i].numhr >100){
			aux += (c[i].numhr-100)* 1.85;
		}
		if(c[i].hospedagem == 's'){
			aux += 20;
		}
		printf("R$%.2f \t\t",aux);
		float desc =0;
		if(c[i].numhr == maior(c,x)){
			desc = (20*aux)/100;
			aux -= desc;

		}
		printf("R$%.2f \t\t R$%.2f\n", desc,aux);
		fat += aux;

	}
	printf("\n\n Faturamento total: R$%.2f\n",fat);
	printf("=================================================\n");
}


int main()
{
	Cliente c[50];
	int x=0;
	while(1){
		printf("1-cadastrar clientes\n2-extrato de faturamento da empresa\n3-sair\n");
		int r;
		scanf(" %i", &r);
		switch(r){
			case 1:
			setCliente(c,x);
			x++;
			break;
			case 2:
			getExtrato(c,x);
			break;
			case 3:
			return 0;
			break;
		}
	}
}
