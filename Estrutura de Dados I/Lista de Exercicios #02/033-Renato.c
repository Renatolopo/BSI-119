#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>
/*Gere uma cartela de bingo 5 x 5, com números aleatórios entre 1 e 75. (Em uma cartela de bingo, não há números
repetidos e os números são apresentados em ordem crescente). Imprima a cartela e faça com que o programa
sorteie as bolas, uma a uma, e realize a “marcação” da cartela em tempo real.*/

int main()
{
	int cartela[5][5],i,j, num,cont,i2,j2;
	srand(time(NULL));
	for(i=0;i<5;i++){
		//printf("\n");
		for(j=0;j<5;j++){
			while(1){
				num = 1+rand()%75;
				cont=0;
				for(i2=0;i2<5;i2++){
					for(j2=0;j2<5;j2++){
						if(num == cartela[i2][j2]){
							cont++;
						}
					}
				}
				if((cont == 0)&&(num >=1)&&(num<=75)){
					cartela[i][j]=num;
					//printf("%i \t",cartela[i][j]);
					break;


				}
			}

		}
	}
	int aux;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			for(i2=0;i2<5;i2++){
				for(j2=0;j2<5;j2++){
					if(cartela[i][j] < cartela[i2][j2]){
						aux = cartela[i][j];
						cartela[i][j] = cartela[i2][j2];
						cartela[i2][j2] = aux;
					}
				}
			}
		}
	}
	printf("\n");
	for(i=0;i<5;i++){
		printf("\n");
		for(j=0;j<5;j++){
			printf("%i\t",cartela[i][j]);
		}
	}
	int c;
	for(c=0;c<25;c++){
		 clrscr();
		sleep(1);
		
		while(1){
			
			cont=0;
			 num = 1+rand()%75;
			 for(i=0;i<5;i++){
				for(j=0;j<5;j++){
					if(num == cartela[i][j]){
						cartela[i][j]= 0;
						cont++;

					}

					
					
				}
			}
			if(cont==1){
				break;
			}
	 	}



		printf("\n");
		printf("\n");
		for(i=0;i<5;i++){
			printf("\n");
			for(j=0;j<5;j++){
				printf("%i\t",cartela[i][j]);
			}
		}
	}
}
