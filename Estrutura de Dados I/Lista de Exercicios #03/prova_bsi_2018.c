#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct{
		char tipo, descri[99];
		float valor;
} 	Movimentacao;

typedef struct{
	int num[4];
	char nome[99];
	float saldo;
	Movimentacao m[50];
	int cont;
} Conta;


int valida(int n[4]){
	if(n[3] == (n[0]*3+ n[1]*4 + n[2]*5)%10){
		return 1;
	}else{
		return 0;
	}
}
int contaExiste(int n[4], int x, Conta c[],int *k){
	for(int i=0;i<x;i++){
		if((n[0]==c[i].num[0])&&(n[1]==c[i].num[1])&&(n[2]==c[i].num[2])&&(n[3]==c[i].num[3])){
			*k = i;
			return 1;
		
		}
	}
	return 0;
}

void setConta(Conta c[], int x){
	
	printf("nome:\n");
	scanf(" %[^\n]s",c[x].nome);
	while(1){
		c[x].num[0]=rand()%9;
		c[x].num[1]=rand()%9;
		c[x].num[2]=rand()%9;
		c[x].num[3]=rand()%9;
		int k;
		if((valida(c[x].num)==1)&&(contaExiste(c[x].num,x,c, &k)==0)){
			printf("numero da conta: ");
			for(int i=0;i<4;i++){
				printf("%i",c[x].num[i]);
			}
			break;
		}


	}
	printf("\n");
		
}
void setMovi(int x, Conta c[]){
	printf("numero da conta:\n");
	char aux[4];
	int n[4],k;
	scanf(" %[^\n]s",aux);
	for(int i=0;i<4;i++){
		n[i] = aux[i]-'0';
	}
	if(valida(n)==1){
		if(contaExiste(n,x,c,&k)==1){
			printf("credito ou debito [c/d]:\n");
			scanf(" %c",&c[k].m[c[k].cont].tipo);
			printf("Descrição:\n");
			scanf(" %[^\n]s",c[k].m[c[k].cont].descri);
			printf("valor:\n");
			scanf(" %f",&c[k].m[c[k].cont].valor);
			if(c[k].m[c[k].cont].tipo == 'c'){
				c[k].saldo = c[k].saldo + c[k].m[c[k].cont].valor;
			}
			else if(c[k].m[c[k].cont].tipo == 'd'){
				c[k].saldo = c[k].saldo - c[k].m[c[k].cont].valor;
			}

			c[k].cont ++;

		}else{
			printf("conta inexistente\n");
		}

	}else{
		printf("conta invalida\n");
	}
}
int setFechamento(){
	printf("fechamento realizado com sucesso!\n");
 	return 0;
}

void getExtrato(Conta c[], int x){
	int n[4], k;
	char aux[4];
	printf("numero da conta:\n");
	scanf(" %[^\n]s",aux);
	for(int i=0;i<4;i++){
		n[i]=aux[i]-'0';
	}
	if(contaExiste(n, x, c, &k)==1){
		printf("nome: %s\n",c[k].nome);
		printf("c/d \t descrição \t valor\n");
		for(int i=0;i<c[k].cont;i++){
			printf("%c \t %s \t %.2f\n",c[k].m[i].tipo, c[k].m[i].descri, c[k].m[i].valor);
		}
		if(c[k].saldo >= 0){
			printf("c \t juros Mensal %.2f",(c[k].saldo*1)/100);
		}
		else{
			printf("d \t juros Mensal %.2f",(c[k].saldo*2)/100);
		}
		printf("\n\nsaldo da conta: \t  %.2f\n",c[k].saldo);


	}else{
		printf("conta inexistente\n");
	}

}

int main()
{
	srand(time(NULL));
	Conta c[50];
	for(int i=0;i<50;i++){
		c[i].cont = 0;
		c[i].saldo = 0;
		
	}
	
	int cc=0,aberta=1;
	while(1){
		printf("================BSI Bank===========\n");
		printf("1 – Cadastrar Conta Bancária\n2 – Cadastrar Movimentação Financeira\n3 – Realizar Fechamento Mensal\n4 – Obter Extrato de Conta\n5 - Sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			if(aberta == 1){
				setConta(c,cc);
				cc ++;

			}else{
				printf("operações fechada\n");
			}
			break;
			case 2:
			if(aberta == 1){
				setMovi(cc, c);
				cc ++;

			}else{
				printf("operações fechada\n");
			}
			break;
			case 3:
			aberta = setFechamento();
			break;
			case 4:
			getExtrato(c, cc);
			break;
			case 5:
			return 0;
			break;

		}
	}
}
