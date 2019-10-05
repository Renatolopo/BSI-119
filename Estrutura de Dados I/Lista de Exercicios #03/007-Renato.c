#include <stdio.h>

typedef struct{
	int cod, quant;
	char descri[99];
	float valor;
} Produto;

int main()
{
	int n;
	printf("informe n\n");
	scanf(" %i",&n);
	Produto p[n];
	int i;
	for(i=0;i<n;i++){
		printf("produto %i\n",i+1);
		printf("descrição do produto\n");
		scanf(" %[^\n]s",p[i].descri);
		printf("codigo de barras\n");
		scanf(" %i",&p[i].cod);
		printf("quantidade em estoque\n");
		scanf("%i",&p[i].quant);
		printf("valor unitario\n");
		scanf(" %f",&p[i].valor);
		printf("---------------------------\n");
	}
	printf("MODO VENDAS\n");
	printf("---------------------------\n");

	float total=0;
	while(1){
		int co,qv;
		printf("codigo de barras do produto:\n");
		scanf("%i",&co);
		int retorno = 0,gi;
		for(i=0;i<n;i++){
			if(co == p[i].cod){
				retorno ++;
				gi=i;
			}
		}
		if(retorno!=0){
			printf("decrição:%s\tcod:%i\tquant:%i\tvalor:%.2f\n",p[gi].descri, p[gi].cod, p[gi].quant, p[gi].valor);
			printf("quantidade a ser vendido:\n");
			scanf("%i",&qv);
			if(qv <= p[gi].quant){
				total += qv*p[gi].valor;
				p[gi].quant -= qv;

			}else{
				printf("quantidade indisponivel\n");
			}


		}
		else if(co < 0){
			break;
		}
		else{
			printf("produto não existe\n");
		}

	}
	printf("Total: R$%.2f\n",total);
}
