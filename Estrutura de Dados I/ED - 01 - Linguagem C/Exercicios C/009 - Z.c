#include <stdio.h>

int main(){
	int tempo, hora, min, seg;

	printf("Insira o tempo de evento em segundos: ");
	scanf(" %i",&tempo);

	hora = tempo / 3600;
	
	min = (tempo - hora * 3600) / 60; 

	seg = tempo - (min * 60 + hora * 3600);

	printf("%ih:%im:%is\n",hora, min, seg );

}