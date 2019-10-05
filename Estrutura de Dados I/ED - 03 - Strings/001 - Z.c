#include <string.h>
#include <stdio.h>

// aaaaaaaaaaaaaaaaa

int main(){
	char frase[99], letra[1];
	int cont=0, tamanho;

	printf("Insira uma frase: ");
	scanf(" %[^\n]s", frase);

	printf("Insira um letra: ");
	scanf(" %[^\n]s", letra);

	tamanho = strlen(frase);

	for(int x=0; x<tamanho; x++){
		if(frase[x] == letra[0])
			cont++;
	}

	printf("%i\n", cont);
}