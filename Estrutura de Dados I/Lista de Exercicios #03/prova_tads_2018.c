#include <stdio.h>
#include <string.h>

typedef struct{
	int num,acento[40],vend[40];
	char origem[99],destino[99];
	float valor;

} Voo;
int validaRota(char origem[99], char destino[99], Voo v[], int x){
	for(int i=0;i<x;i++){
		if((strcmp(origem,v[i].origem)==0)&&(strcmp(destino,v[i].destino)==0)){
			return i;
		}
	}
	return -1;
}
void getVoo(Voo v[], int x){
	while(1){
		printf("origem:\n");
		scanf(" %[^\n]s",v[x].origem);
		printf("destino:\n");
		scanf(" %[^\n]s",v[x].destino);
		if(validaRota(v[x].origem, v[x].destino, v, x)==-1){
			break;
		}
		printf("essa rota já existe\n");
	}
	printf("numero do voo:\n");
	scanf(" %i",&v[x].num);
	printf("valor da passagem:\n");
	scanf(" %f",&v[x].valor);
}
void getRelatorio(Voo v[], int x){
	printf("Num Vôo\t Origem\t Destino\t Qtde.Vendido\t Qtde.Disponível\t Valor Assento\n");
	for(int i=0;i<x;i++){
		int c=0;
		for(int j=0;j<40;j++){
			if(v[i].vend[j] == 1)
				c++;
		}
		printf("%i \t %s\t %s\t \t%i \t\t%i \t\tR$%.2f\n",v[i].num, v[i].origem, v[i].destino, c, 40-c, v[i].valor);
	}
}
void getVender(Voo v[], int x){
	char origem[99], destino[99];
	while(1){
		printf("origem:\n");
		scanf(" %[^\n]s",origem);
		printf("destino:\n");
		scanf(" %[^\n]s",destino);
		if(validaRota(origem, destino, v, x)!=-1)
			break;
	}
	int y = validaRota(origem, destino, v, x);
	printf("origem: %s\ndestino: %s\nnumero do voo: %i\nvalor: R$%.2f\n",origem,destino, v[y].num, v[y].valor);
	printf("assentos vendidos: ");
	for(int i=0;i<40;i++){
		if(v[y].vend[i] == 1)
			printf("%i ",v[y].acento[i]);
	}
	printf("\nassentos disponiveis: ");
	for(int i=0;i<40;i++){
		if(v[y].vend[i] == 0)
			printf("%i ",v[y].acento[i]);
	}
	printf("\nInforme os Assentos Desejados ou -1 pra sair:\n");
	int cont=0;
	while(1){
		int n;
		scanf(" %i",&n);
		for(int i=0;i<40;i++){
			if(n == v[y].acento[i]){
				if(v[y].vend[i]==0){
					v[y].vend[i] = 1;
					cont++;
				}else{
					printf("assento indisponivel, venda não realizada\n");
				}
			}
		}
		if(n>40)
			printf("assento indisponivel\n");
		if(n<0)
			break;
	}
	printf("total vendidos: %i\n",cont);
	printf("total da venda: R$%.2f\n",cont*v[y].valor);

}
int main(){
	Voo v[50];
	int x=0;
	for(int k=0;k<50;k++){
		for(int i=0;i<40;i++){
			v[k].acento[i] = i+1;
			v[k].vend[i] = 0;
		}
	}
	while(1){
		printf("=============================\n");
		printf("1-cadastrar Voo\n2-Relatorio resumo de voos\n3-vender passagens aérea\n4-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			getVoo(v,x);
			x++;
			break;
			case 2:
			getRelatorio(v,x);
			break;
			case 3:
			getVender(v,x);
			break;
			case 4:
			return 0;
			break;
		}
	}
}
