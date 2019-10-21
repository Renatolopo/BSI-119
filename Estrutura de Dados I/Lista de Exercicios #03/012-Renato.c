#include <stdio.h>
#include <string.h>

typedef struct{
	char origem[99],destino[99];
	int distancia,tempo;

} Rotas;
int getVerifica(Rotas r[], int c){

	for(int i=0;i<c;i++){
		if(strcmp(r[i].origem,r[c].origem)==0){
			
			return 0;
		}

	}
	return 1;

}
int getVerifica2(Rotas r[], int c){

	for(int i=0;i<c;i++){
		if(strcmp(r[i].destino,r[c].destino)==0){
			
			return 0;
		}

	}
	return 1;

}

void setRota(Rotas r1[],int c){
	while(1){
		printf("\n==================================\n");
		printf("cidade de origem:\n");
		scanf(" %[^\n]s",r1[c].origem);
		if(getVerifica(r1,c)==1)
			break;
		printf("origem invalida\n");
	}
	printf("cidade de destino:\n");
	scanf(" %[^\n]s",r1[c].destino);
	printf("distancia:\n");
	scanf(" %i",&r1[c].distancia);
	printf("tempo:\n");
	scanf(" %i",&r1[c].tempo);
	printf("\n==================================\n");
}
int getConsulta(int *d, int *t, int* q,Rotas r[],int c){
	int cont = 0;
	while(1){
		cont ++;
		for(int i=0;i<c;i++){
			if(strcmp(r[i].origem,r[c].origem)==0){
				
				*d +=r[i].distancia;
				*t +=r[i].tempo;
				*q += 1;
				strcpy(r[c].origem,r[i].destino);
				break;
			}

		}
		if(strcmp(r[c].origem,r[c].destino)==0)
			break;
			
		if(cont > 2*c)
		{
			
			return 1;
		}


	}
	return 0;
}


void getRota(Rotas r1[],int c){
	
	while(1){

		printf("cidade de origem:\n");
		scanf(" %[^\n]s",r1[c].origem);
		if(getVerifica(r1,c)==0){
			break;
		}else{
			printf("origem não existe\n");
		}


	}
	while(1){
		printf("\n==================================\n");
		printf("cidade de destino:\n");
		scanf(" %[^\n]s",r1[c].destino);
		if(getVerifica2(r1,c)==0){
			break;
		}else{
			printf("destino não existe não existe\n");
		}


	}
	int dis=0,temp=0,quant=0;
	printf("de %s a %s \n",r1[c].origem, r1[c].destino);
	if(getConsulta(&dis,&temp,&quant,r1,c)==1){
		printf("não existe rota entre essas cidades\n");

	}else{
		printf("distancia %ikm, tempo %i horas e %i viagens\n",dis,temp,quant);
	}
	printf("\n==================================\n");

	for(int i=0;i<99;i++){
		r1[c].origem[i]='i';
		r1[c].destino[i]='i';
	}

	
		

}


int main()
{
	Rotas r[50];
	int c=0;
	while(1){
		printf("1-cadastrar rotas\n2-consultar\n3-sair\n");
		int x;
		scanf(" %i",&x);
		switch(x){
			case 1:
			setRota(r,c);
			break;
			case 2:
			getRota(r,c);
			break;
			case 3:
			return 0;
			break;
		}
		c++;
	}
}
