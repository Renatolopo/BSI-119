#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Faça um programa que leia, em formato de string, dois números inteiros excepcionalmente grandes e imprima a
soma destes números. P.ex.: “25996478547851225” e “1452565475541” = 25997931113326766*/
int main()
{
	char n1[99],n2[99];
	printf("informe o primeiro numero: ");
	scanf("%s",n1);
	printf("informe o segundo numero: ");
	scanf("%s",n2);
	int soma,num1,num2;
	num1 = atoi(n1);
	num2 = atoi(n2);
	soma = num1+num2;
	printf("%i",soma);
	
}