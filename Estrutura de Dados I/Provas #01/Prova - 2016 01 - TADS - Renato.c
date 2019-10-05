#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int cartas[9],i,c,retorno,num,x=9,y=0,nt[y];
	for(i=0;i<9;i++){
		while(1){
			retorno=0;
			num = 1+rand()%13;
			for(c=0;c<i;c++){
				if(num==cartas[c]){
					retorno++;
				}

			}
			if(retorno<=4){
				cartas[i]=num;
				printf("%i ",cartas[i]);
				break;
			}

		}
	}
	while(1){
		int aux;
		for(i=0;i<x;i++){
			for(c=0;c<9;c++){
				if(cartas[i]<cartas[c]){
					aux = cartas[i];
					cartas[i]=cartas[c];
					cartas[c]=aux;
				}
			}

		}
		printf("\n");
		for(i=0;i<y;i++){
			printf("%i ",nt[i]);
		}
		for(i=0;i<x;i++){
			printf("%i ",cartas[i]);
		}

		printf("\n");
		int aux2[x],cont=0,trinca=0,c2,j;
		
		aux=0;
		for(i=i;i<x;i++){
			aux2[i]=cartas[i];
		}

		for(i=0;i<9;i++){
			//printf("%i %i %i \n",cartas[i],cartas[i+1],cartas[i+1]+1);
			if(((cartas[i]==cartas[i+1])&&(cartas[i-1]==cartas[i])) || ((cartas[i]+1==cartas[i+1])&&(cartas[i-1]==cartas[i]-1))){
				cont++;
				
			}
			else{
				cont=0;
			}
			
			
				
			c2=0;
			if(cont==1){
				trinca++;
				cont=0;
				x=x-3;
				y+=3;

				nt[y];
				j=i-1;
				for(c=0;c<y;c++){
					nt[(y-3)+c]=cartas[j+c];
				}

				cartas[x];
				for(c=0;c<x;c++){
					cartas[c]= aux[c2];
					
					
					if(c-1==i-1){
						c2 +=3;
					}
					else
						c2++;
				}



			}
			

		}
		printf("\n");
		printf("%i trinca\n",trinca);
		if(trinca==3){
			printf("\n parabéns você ganhou\n");
			break;
		}
		int n;
		while(1){
			printf("qual numero você deseja trocar? \n");
			scanf(" %i",&n);
			cont=0;
			for(i=0;i<x;i++){
				if(n==cartas[i]){
					cont++;
				}
			}
			if((cont!=0)&&(n>=1)&&(n<=13)){
				break;

			}
		}
		for(i=0;i<x;i++){
			if(n==cartas[i]){
				while(1){
					retorno=0;
					n =1+rand()%13;
					for(c=0;c<x;c++){
						if(n==cartas[c]){
							retorno++;
						}
					}
					if(retorno<=4){
						cartas[i]=n;
						break;

					}
				}
				break;
			}
		}
	}
}
