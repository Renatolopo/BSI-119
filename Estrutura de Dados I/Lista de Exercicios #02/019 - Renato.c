#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Faça um programa que leia em formato de string, o número de uma conta-corrente que possui 5 dígitos numéricos.
(Não devem ser aceitos letras e/ou símbolos que não sejam numéricos). O quinto dígito é um DV (Dígito Verificador),
que serve para verificar se a sequencia de dígitos informados atendem a uma regra específica que valida o número
da conta. A regra para cálculo do DV é a seguinte: 1o dígito multiplicado por 3; 2o dígito por 5; 3o dígito por 7 e o 4o
dígito por 9. O quinto dígito (DV) deverá ser o resto da divisão inteira da soma destes produtos por 10.
O programa deverá informar se a seqüência informada corresponde ou não a um número de conta válido.*/
int main()
{
	char conta[99];
	int i, num[99];
	int tamanho,cont=0,c=0;
	while(1){
		printf("digite o numero da conta(5 digitos): \n");
		scanf(" %s", conta);

		tamanho = strlen(conta);
		
	
	
	
	for(i=0;i<tamanho;i++){
		if((conta[i]>='0')&&(conta[i]<='9')){
			num[c]=conta[i]-'0';
			c++;
			cont++;
		}
		
	

	}
	if(cont==5)
		break;
	}	
	int acum=0,aux=3;
	for(i=0;i<4;i++){
		acum += num[i]*aux;
		aux += 2;

	}
	int mod = acum%10;
	if(mod == num[4]){
		printf("conta valida\n");
	}
	else{
		printf("conta invalida\n");
	}

}
