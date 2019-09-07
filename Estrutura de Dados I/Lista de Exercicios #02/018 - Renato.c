#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*Faça um programa que leia, em formato de string, um valor numérico representado na base binária. O programa
deve validar se o valor informado pelo usuário realmente é um número binário. Em caso positivo, o programa deve
informar o valor correspondente na base decimal.*/
int main()
{
	char bin[99];
	int c,i,cont,tamanho;
	while(1){
		cont=0;

		printf("digite um numero em binario: \n");
		scanf(" %s", bin);
		
		
		
		tamanho=strlen(bin);
		for(c=0;c<tamanho;c++){
			if((bin[c]!='1')&&(bin[c]!='0')){
				cont++;
			}
		}
		
		if(cont==0){
			break;
		}
		else{
			printf("numero invalido\n");
		}
	}
	tamanho=strlen(bin);
	int dec=0;
	
	
	for(i=tamanho-1;i>=0;i--){
		if(bin[i]=='1'){
			dec+=pow(2,tamanho-i-1);
		

		}
		
	}
	printf("o numero na base dez: %i \n",dec);

}
