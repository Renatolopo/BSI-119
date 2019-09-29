#include <stdio.h>

// define o registro de cadastro
typedef struct{
	
	int codigo, estoque;
	char descricao[99];
	float valor;

}Cadastro;


int main(){
	Cadastro produto[30];
	
	int cont=0;

	// Cadastra os produtos 
	while(1){
		printf("\n===== Cadastro de Produto =====\n");
		
		printf("Código de barras: ");
		scanf(" %i",&produto[cont].codigo);
		
		if(produto[cont].codigo < 0)
			break;

		printf("Estoque: ");
		scanf(" %i",&produto[cont].estoque);
		printf("Preço unitario: ");
		scanf(" %f",&produto[cont].valor);
		printf("Descrição do produto: ");
		scanf(" %[^\n]s", produto[cont].descricao);
		
		cont++;
	}

	// Laço para a venda dos produtos
	int codigo_venda, existe, x, qtd_venda, total_produtos_comprados=0;
	float total_venda=0;
	
	while(1){
		printf("\n\n===== Venda Produto =====\n");

		printf("Insira o código de barras do produto: ");
		scanf(" %i",&codigo_venda);

		if(codigo_venda < 0)
			break;

		// laço para verificar se o produto existe
		for(x=0; x<30; x++){
			if(codigo_venda == produto[x].codigo){
				existe = 1;
				break;
			} else {
				existe = 0;
			}
		}

		// caso o produto exista 
		if(existe == 1){
			printf("\n===== Informações do produto =====");

			printf("\nCódigo de barras: %i", produto[x].codigo);
			printf("\nEstoque Disponível: %i", produto[x].estoque);
			printf("\npreço unitário: %.2f", produto[x].valor);
			printf("\nDescrição: %s", produto[x].descricao);

			printf("\n\nInsira a quantidade de produtos que deseja comprar: ");
			scanf(" %i",&qtd_venda);

			// caso o estoque seja sufucuente para a venda
			if(qtd_venda <= produto[x].estoque){
				printf("O estoque atende a venda!");
				total_venda += qtd_venda * produto[x].valor;
				total_produtos_comprados += qtd_venda;
				produto[x].estoque -= qtd_venda;

			// caso o estoque não seja suficiente
			} else {
				printf("O estoque não atende a venda!\n");
				continue;
			}

		// caso o produto não exista
		} else if(existe == 0){
			printf("Não existe um produto com esse código de barras\n");
		}
	}

	// mostra as informações finais
	printf("\n\n\nVenda Finalizada com sucesso!\n");
	printf("Foram comprados %i produtos\n", total_produtos_comprados );
	printf("Valor total da venda: %.2f\n", total_venda);
}
