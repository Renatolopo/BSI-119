#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[99];
	int dia,mes,ano,idade;
} Pessoa;

int main()
{
	srand(time(NULL));
	int n;
	printf("informe o numero de pessoas\n");
	scanf(" %i",&n);
	Pessoa p1[n];
	int i;

	time_t horario = time(NULL);
	char t[25];
	strftime(t,25,"%d%m%Y", localtime(&horario));
	//printf("%s\n",t);
	int t2[8];
	for(i=0;i<8;i++){
		t2[i]=t[i]-'0';
		//printf("%i ",t2[i]);
	}
		
	for(i=0;i<n;i++){
		printf("informe o nome da %iª pessoa:\n",i+1);
		scanf(" %[^\n]s",p1[i].nome);
		p1[i].dia = 1 + rand()%(30+1-1);
		p1[i].mes = 1 + rand()%(12+1-1);
		p1[i].ano = 1990 + rand()%(2018-1990+1);
		p1[i].idade = (t2[4]*1000+t2[5]*100+t2[6]*10+t2[7])-p1[i].ano;

	}
	int c,aux,ax,ax2,ax3;
	char aux2[99];
	for(i=0;i<n;i++){
		for(c=0;c<n;c++){
			if(p1[i].idade > p1[c].idade){
				aux = p1[i].idade;
				p1[i].idade = p1[c].idade;
				p1[c].idade = aux;

				strcpy(aux2,p1[i].nome);
				strcpy(p1[i].nome,p1[c].nome);
				strcpy(p1[c].nome,aux2);

				ax = p1[i].dia;
				p1[i].dia = p1[c].dia;
				p1[c].dia = ax;

				ax2 = p1[i].mes;
				p1[i].mes = p1[c].mes;
				p1[c].mes = ax2;

				ax3 = p1[i].ano;
				p1[i].ano = p1[c].ano;
				p1[c].ano = ax3;

			}
		}
	}




	printf("nome\t\tdata de nascimento\t idade\n");

	for(i=0;i<n;i++){
		printf("\n%s\t%i/%i/%i\t%i\n",p1[i].nome,p1[i].dia,p1[i].mes,p1[i].ano,p1[i].idade);
	}

}
