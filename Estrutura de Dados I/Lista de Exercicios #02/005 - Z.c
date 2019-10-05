#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// aaaaaaaaaaaa tnc desse karaio

int main(){
	int x, y;

	printf("Insira o tamanho do vetor X: ");
	scanf(" %i",& x);

	printf("Insira o tamanho do vetor Y: ");
	scanf(" %i",& y);

	int vx[x], vy[y], aux;

	srand(time(NULL));

	for(int i=0; i < x; i++){
		vx[i] = rand() % (x+y+1);

		for(int j=0; j < i; j++){
			if(vx[j] == vx[i]){
				vx[j] = rand() % (x+y+1);
				j=0;
			}
		}
	}

	for (int i = 0; i < x; ++i){
		printf("%i\n", vx[i]);
	}
}