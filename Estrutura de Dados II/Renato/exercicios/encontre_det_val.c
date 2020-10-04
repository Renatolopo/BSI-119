#include <stdio.h>
#include <time.h>
int getProcura(int vet[10], int n){
	
	for(int i=0;i<10;i++){
		printf("interação  %i\n", i);
		if(vet[i] == n)// função de complexidade
			return vet[i];
	}
	printf("Não encontrado\n");
	return 0;
}
int main(){
	
	int vet[10]= {3, 6, 2, 34, 55, 9, 34, 32, 67, 54};
	int maior = 0;
	int n;
	printf("Informe o Valor: ");
	scanf(" %i",&n);
	int val = getProcura(vet, n);

	printf("Valor encontrado: %i\n",val);
}
/* onde f(n) e a comparação do valor do vetor com o numero que esta sendo
procurado.*/ 


//f(n) <= n 
