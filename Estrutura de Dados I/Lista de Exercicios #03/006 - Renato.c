#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

typedef struct{
	int xa,xb,ya,yb;
	float ca;
} Ponto;
int main()
{
	Ponto p[2];
	int i;
	printf("-----------------------------------------------\n");
	for(i=0;i<2;i++){
		printf("Reta %i\n",1+i);
		printf("informe as cordenadas do ponto A:\n X: ");
		scanf(" %i",&p[i].xa);
		printf("Y: ");
		scanf(" %i",&p[i].ya);
		printf("\ninforme as cordenadas do ponto B:\n X: ");
		scanf(" %i",&p[i].xb);
		printf("Y: ");
		scanf(" %i",&p[i].yb);
		printf("-----------------------------------------------\n");
	}

	for(i=0;i<2;i++){
		p[i].ca = (p[i].yb - p[i].ya)/(p[i].xb - p[i].xa);
	}
	printf("ca 1: %.2f\nca 2: %.2f\n",p[0].ca,p[1].ca);
	if(p[0].ca == p[1].ca){
		printf("Retas paralelas\n");
	}
	else if((p[0].ca  == -(1/p[1].ca)) || (p[1].ca  == -(1/p[0].ca))){
		printf("São penperdiculares\n");

	}
	else
	{
		printf("Nenhuma, essas retas só são uma reta \n");
	}
}
