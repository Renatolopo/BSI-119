#include <stdio.h>

typedef struct{
	
	float emprestimo, juros;
	int prazo;

}Proposta;

int main(){
	
	Proposta p[100];

	int x=0;
	float parcela, parcela_nova, juros;

	while(1){
		printf("===== Novo Empréstimo =====\n");
		printf("\nInsira o valor do emprestimo: ");
		scanf(" %f",&p[x].emprestimo);

		if(p[x].emprestimo < 0)
			break;

		printf("Insira o prazo: ");
		scanf(" %i",& p[x].prazo);

		printf("Insira o juros mensal: ");
		scanf(" %f",&p[x].juros);

		parcela = parcela_nova = p[x].emprestimo / p[x].prazo;

		printf("===== Preço Mensal =====\n");
		for(int y=0; y < p[x].prazo; y++){
			printf("\n%iº parcela: %.2f", y+1, parcela_nova);
			
			parcela_nova = parcela * p[x].juros;
			parcela = parcela_nova;
		}

		x++;

		printf("\n\n");
	}
}