#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Faça um programa que leia uma string S, e criptografe-a com o seguinte algoritmo: sorteie um vetor de strlen(S)
números, com valores aleatórios e não-repetitivos entre 0 e strlen(s)-1 (inclusive). Após o sorteio, embaralhe
as letras da mensagem original, de acordo com as posições sorteadas no vetor. Atenção, todos os caracteres tem
que ter sua posição inicial alterada!
Exemplo de Execução:
String:
AULA DE PE
Vetor Sorteado: 1369847502
Texto Cifrado: PAEUD LE A*/
int main()
{
	char st[99];
	printf("digite uma frase: ");
	scanf("%[^\n]s",st);
	printf("%s", st);
	int aux = strlen(st);
	int n[aux],i,c,cont,num;
	srand(time(NULL));
	printf("\n");
	for(i=0;i<aux;i++){
		while(1){
			cont=0;
			num = 0+rand()%aux;
			for(c=0;c<aux;c++){
				if(num == n[c]){
					cont ++;
				}

			}
			if(cont ==0){
				n[i]=num;
				printf("%i ",n[i]);
				break;
			}
		}
	}
	printf("\n");
	for(i=0;i<aux;i++){
		printf("%c",st[n[i]]);
	}
}
