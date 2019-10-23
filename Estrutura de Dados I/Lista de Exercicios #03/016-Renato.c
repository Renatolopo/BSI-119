#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[99];
	int tel,dia,mes,ano;
} Pessoa;

void converti(char aux2[99], Pessoa p[], int c){
	int aux[8],cont=0;
	for(int i=0;i<strlen(aux2);i++){
		if((aux2[i] >= '0')&&(aux2[i] <= '9')){
			aux[cont] = aux2[i] - '0';
			cont ++;
		}
	}
	p[c].dia = aux[0]*10+aux[1];
	p[c].mes = aux[2]*10+aux[3];
	p[c].ano = aux[4]*1000+aux[5]*100 + aux[6]*10 + aux[7];

}

int verifica(char aux2[99], Pessoa p[], int c){
	
	if(p[c].mes==2){
		if(p[c].dia<=28)
			return 1;
		else
			return 0;
	}
	else if((p[c].mes%2 != 0)&&(p[c].mes <= 7)){
		if(p[c].dia<=31)
			return 1;
		else
			return 0;

	}
	else if((p[c].mes%2 == 0)&&(p[c].mes <= 6)){
		if(p[c].dia<=30)
			return 1;
		else
			return 0;

	}
	else if((p[c].mes%2 != 0)&&(p[c].mes > 7)){
		if(p[c].dia<=30)
			return 1;
		else
			return 0;

	}
	else if((p[c].mes%2 == 0)&&(p[c].mes > 6)){
		if(p[c].dia<=31)
			return 1;
		else
			return 0;

	}
	return 0;

}
void setPessoa(Pessoa p[], int c){
	printf("nome:\n");
	scanf(" %[^\n]s",p[c].nome);
	printf("telefone:\n");
	scanf(" %i",&p[c].tel);
	while(1){
		printf("data de nascimento:\n");
		char aux[99];
		scanf(" %[^\n]s",aux);
		converti(aux, p, c);
		if(verifica(aux, p, c) == 1)
			break;
	}
	//printf("%i/%i/%i\n",p[c].dia, p[c].mes, p[c].ano);
}
void  ordena(int m, Pessoa p[], int c ){
	int aux;
	char aux2[99];
	for(int i=0; i<c; i++){
		for(int j=0;j<c; j++)
		if((p[i].mes == m)&&(p[j].mes == m)){
			if(p[i].dia < p[j].dia){
				strcpy(aux2,p[i].nome);
				strcpy(p[i].nome,p[j].nome);
				strcpy(p[j].nome,aux2);

				aux = p[i].tel;
				p[i].tel = p[j].tel;
				p[j].tel = aux;

				aux = p[i].dia;
				p[i].dia = p[j].dia;
				p[j].dia = aux;

				aux = p[i].mes;
				p[i].mes = p[j].mes;
				p[j].mes = aux;

				aux = p[i].ano;
				p[i].ano = p[j].ano;
				p[j].ano = aux;
				
			}

		}


	}
		
}

void aniMes(Pessoa p[], int c){
	printf("informe o mes:\n");
	int aux;
	scanf(" %i",&aux);
	ordena(aux, p, c);
	for(int i=0;i<c;i++){
		if(aux == p[i].mes){
			printf("dia %i\t nome:%s idade:%ianos\n",p[i].dia, p[i].nome, 2019-p[i].ano);
		}
	}

}
int existe(int m, int c, Pessoa p[]){
	for(int i=0;i<c;i++){
		if(m == p[i].mes)
			return 1;
	}
	return 0;
}
void getPessoa(Pessoa p[], int c){
	printf("====================================================\n");
	for(int i=0;i<12;i++){
		
		if(existe(i+1,c,p)==1){
			printf("Pessoas do mes %i \n",i+1);
			ordena(i+1,p,c);
			for(int j=0;j<c;j++){
				if(p[j].mes == i+1){
					printf("nome:%s\t telefone:%i\t data de nascimento:%i/%i/%i\n",p[j].nome, p[j].tel, p[j].dia, p[j].mes, p[j].ano);
				}
			}

		}
	}
	printf("====================================================\n");
}

int main()
{
	Pessoa p[50];
	int c=0;
	while(1){
		printf("1-cadastrar pessoa\n2-consultar aniversariante de um determinado mes\n3-mostrar todos os dados\n4-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			setPessoa(p,c);
			c++;
			break;

			case 2:
			aniMes(p,c);

			case 3:
			getPessoa(p,c);
			break;

			case 4:
			return 0;
			break;
		}
	}
}
