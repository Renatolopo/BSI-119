#include <stdio.h>

typedef struct{

	float kmh, ms, mph, knot;

}Velocidade;

int main(){
	
	Velocidade vel;
	int escolha;

	printf("[ 1 ] - Kilometro por hora\n");
	printf("[ 2 ] - Metros por segundo\n");
	printf("[ 3 ] - Milhas por hora\n");
	printf("[ 4 ] - Velocidade náutica\n");

	printf("Escolha uma das das medidas a cima: ");
	scanf(" %i",&escolha);

	switch(escolha){
		case 1:
			printf("\nInsira uma medida em KM\\H: ");
			scanf(" %i",&vel.kmh);
			break;
		case 2:
			printf("\nInsira uma medida em M\\S: ");
			scanf(" %i",&vel.ms);
			break;
		case 3:
			printf("\nInsira uma medida em MP\\H: ");
			scanf(" %i",&vel.mph);
			break;
		case 4:
			printf("\nInsira uma medida em NÓs: ");
			scanf(" %i",&vel.knot);
			break;
		default:
			printf("\nOpção escolhida inválida!\n");

	}
}