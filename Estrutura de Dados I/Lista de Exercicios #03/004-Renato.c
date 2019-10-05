#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float emprestado,taxa;
	int prazo;
} Proposta;

int main()
{
	while(1){
		Proposta p;
		printf("\n valor emprestado:\n");
		scanf(" %f",&p.emprestado);
		if(p.emprestado < 0)
			break;
		printf("prazo: \n");
		scanf(" %i",&p.prazo);
		printf("taxa %%: \n");
		scanf(" %f",&p.taxa);
		int i;
		float total=0,pa,aux=p.emprestado;
		for(i=0;i<p.prazo;i++){
			
			pa = aux/p.prazo;
			printf("%iº parcela: %.2f \n",i+1, pa);
			aux = aux+(p.taxa*100/aux);
			
			total +=pa;
		}
		printf("total: %.2f", total);
	}
	printf("fim");
}
