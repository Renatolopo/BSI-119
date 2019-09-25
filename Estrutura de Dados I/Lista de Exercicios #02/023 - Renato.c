#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Considerando o problema anterior, faça um programa que leia uma String S criptografada, e um vetor de
strlen(s) números inteiros. Valide a consistência do vetor (não deve ter números repetidos e devem estar no
intervalo adequado). Se tudo estiver em conformidade, informe a mensagem decifrada...
Exemplo de Execução:
String:
PAEUD LE A
Vetor:
1369847502
Texto Decifrado: AULA DE PE*/
int main()
{
	char st[99];
	printf("digite a string criptografada: \n");
	scanf("%[^\n]s",st);
	int aux = strlen(st), t,i;
	char n[aux];
	int n1[aux],cont,c;
	while(1){
		
		printf("digite a sequencia de %i numeros: \n",aux);
		scanf("%s",n);
		t= strlen(n);
		if(t == aux){
			for(i=0;i<aux;i++){
				n1[i]=n[i]-'0';
			}
			cont=0;
			for(i=0;i<aux;i++){
				for(c=0;c<aux;c++){
					if(n1[i]==n1[c])
						cont++;
				}

			} 
			//printf("\ncontador %i\n",cont);
			if(cont<=aux){
				break;
			}

		}


	}
	for(i=0;i<aux;i++){
		printf("%i",n1[i]);
	}

}
