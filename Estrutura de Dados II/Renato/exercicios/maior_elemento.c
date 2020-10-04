#include <stdio.h>
#include <time.h>
int main(){
	
	int vet[10]= {3, 6, 2, 34, 55, 9, 34, 32, 67, 54};
	int maior = 0;
	for(int i=0;i<10;i++){
		if(vet[i] > maior){
			maior = vet[i];
		}
	}

	printf("Maior: %i\n",maior);
}

