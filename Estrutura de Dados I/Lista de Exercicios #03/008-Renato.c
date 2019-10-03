#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	char titulo[99],autor[99],ac[99];
	int ano,local;	
} Livro;

int main()
{

	int n;
	printf("informe a quantidade de livro:\n");
	scanf(" %i",&n);
	Livro l1[n];
	int i,c;
	for(i=0;i<n;i++){
		printf("-----------livro %i----------\n",i+1);
		printf("titulo do livro:\n");
		scanf(" %[^\n]s",l1[i].titulo);
		printf("autor do livro:\n");
		scanf(" %[^\n]s",l1[i].autor);
		printf("área de conhecimento: \n");
		scanf(" %[^\n]s",l1[i].ac);
		printf("ano:\n");
		scanf(" %i",&l1[i].ano);

		
	}
	char aux[99],auxt[99],auxa[99];
	int auxy;
	
	for(i=0;i<n;i++){
		for(c=0;c<n;c++){
			
			if(strcmp(l1[i].ac,l1[c].ac) < 0 ){
				strcpy(aux,l1[i].ac);
				strcpy(l1[i].ac,l1[c].ac);
				strcpy(l1[c].ac,aux);

				strcpy(auxt,l1[i].titulo);
				strcpy(l1[i].titulo,l1[c].titulo);
				strcpy(l1[c].titulo,auxt);

				strcpy(auxa,l1[i].autor);
				strcpy(l1[i].autor,l1[c].autor);
				strcpy(l1[c].autor,auxa);

				auxy = l1[i].ano;
				l1[i].ano = l1[c].ano;
				l1[c].ano = auxy;
			}

		}
	}
	int cont2=0;
	
	for(i=0;i<n;i++){
		
		
	}
	for(i=0;i<n;i++){
		for(c=0;c<n;c++){
			if((strcmp(l1[i].titulo,l1[c].titulo) < 0)&&(strcmp(l1[i].ac,l1[c].ac) == 0)){
					strcpy(aux,l1[i].ac);
					strcpy(l1[i].ac,l1[c].ac);
					strcpy(l1[c].ac,aux);

					strcpy(auxt,l1[i].titulo);
					strcpy(l1[i].titulo,l1[c].titulo);
					strcpy(l1[c].titulo,auxt);

					strcpy(auxa,l1[i].autor);
					strcpy(l1[i].autor,l1[c].autor);
					strcpy(l1[c].autor,auxa);

					auxy = l1[i].ano;
					l1[i].ano = l1[c].ano;
					l1[c].ano = auxy;
					
			}
		}
	}

	int x=0,cont=0;
	for(i=0;i<n;i++){
		if((cont==3)||(strcmp(l1[i].ac,l1[i-1].ac)!=0)){
			x++;
			cont=0;
		}
		cont++;
		l1[i].local = x;

	}
			
	cont2=0;
	for(i=0;i<n;i++){
		if(cont2==0){
			printf("\n");
			printf("---------------------------\n");
			printf("Área de conhecimento: %s\n",l1[i].ac);
			
		
		}
		if(strcmp(l1[i].ac,l1[i+1].ac) == 0){
			cont2 = 1;
			
		}
		
		else{	
			cont2 = 0;
		
		}
		
		printf(" titulo: %s\n autor: %s\n ano:%i\nlocalização: %i\n\n",l1[i].titulo,l1[i].autor,l1[i].ano,l1[i].local);
		

	}


}
