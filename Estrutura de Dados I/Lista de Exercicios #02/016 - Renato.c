#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Escreva um programa em C para ler uma frase. A seguir, imprima a 
frase com: (a) todas as letras maiúsculas, (b)
todas as letras minúsculas, (c) início de cada palavra em maiúsculo.*/
int main()
{
	char frase[300];
	printf("digite uma frase: ");
	scanf(" %[^\n]s", frase);
	
	//printf("%s \n",frase);
	//printf("mudando para maiusculo:\n %s \n", toupper(frase));
	int t= strlen(frase);	
	int i;
	for(i=0;i<300;i++){
		frase[i]= toupper(frase[i]);
	}
	printf("%s \n",frase);
	for(i=0;i<300;i++){
		frase[i]= tolower(frase[i]);
	}
	printf("%s \n",frase);
	for(i=0;i<300;i++){
		if((i==0)||(frase[i-1]==' ')){
			frase[i]=toupper(frase[i]);
			//printf("ola");
		}
	}
	printf("%s \n",frase);

}
