#include <stdio.h>

int main(){
	int x, y;

	printf("Insira a quantidade de caixas disponiveis: ");
	scanf(" %i",&x);

	printf("Insira a quantidade de clientes na fila: ");
	scanf(" %i",&y);

	int caixas[x], clientes[y], caixa_aux[x], caixa_min[x], contagem[x];

	// Recebe os valores de caixas
	printf("Informe o tempo que cada caixa leva para registrar cada autenticação\n");
	for(int a=0; a < x; a++){
		printf("[%i]: ", a);
		scanf(" %i",&caixas[a]);
	}

	// Recebe os valores de clientes
	printf("Informe a quantidade de documentos que cada cliente tem para autenticação\n");
	for(int a=0; a < y; a++){
		printf("[%i]: ", a);
		scanf(" %i",&clientes[a]);
	}

	// Zera caixa_aux, caixa_min e contagem
	for(int a=0; a < x; a++){
		caixa_aux[a] = 0;
		caixa_min[a] = 0;
		contagem[a] = 0;
	}

	for(int a=0; a < y; a++){
		for(int b=0; b < x; b++){
			if (caixa_aux[b] > 0){
				caixa_aux[b]--;
			}

			if(caixa_aux[b] == 0){
				caixa_aux[b] = caixas[b] * clientes[a];
				caixa_min[b] += caixas[b] * clientes[a];
				contagem[b]++;
				break;
			}

			if(b == x-1)
				a--;
		}
	}

	printf("---------------------- Resultado ----------------------\n");

	for (int i = 0; i < x; i++){
		printf("O caixa %i atendeu %i clientes,", i, contagem[i]);
		printf("e gastou %i minutos no total\n", caixa_min[i]);
	}
}
