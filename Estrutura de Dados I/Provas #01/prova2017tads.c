#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int jogador[5],pc[5];
	int i,p=5,j=5,r1=99,vi;
	for(i=0;i<j;i++){
		jogador[i]=1+rand()%13;
		pc[i]=1+rand()%13;
	}
	while(1){

		int c,aux;

		if(r1==1){
			
			jogador[vi]=1+rand()%13;
		}
		else if(r1==0){
		
			pc[0]=1+rand()%13;
		}


		for(i=0;i<j;i++){
			for(c=0;c<j;c++){
				if(jogador[i]<jogador[c]){
					aux=jogador[i];
					jogador[i]=jogador[c];
					jogador[c]=aux;
				}
				
			}
		}
		for(i=0;i<p;i++){
			for(c=0;c<p;c++){
				
				if(pc[i]<pc[c]){
					aux=pc[i];
					pc[i]=pc[c];
					pc[c]=aux;
				}
			}
		}
		if(r1==1){
			p--;
			
		}
		else if(r1==0){
			j--;
			
		}
		printf("--------------------------------\n");
		printf("cartas do jogador:\n");
		for(i=0;i<j;i++){
			printf("%i\t ",jogador[i]);
		}
		printf("\ncartas do computador:\n");
		for(i=0;i<p;i++){
			printf("%i \t",pc[i]);
		}
		
		int n,retorno;
		while(1){
			printf("\n escolha uma carta: ");
		
			scanf(" %i",&n);
			retorno=0;
			for(i=0;i<j;i++){
				if(n == jogador[i]){
					retorno++;
					vi=i;
				}
			}
			if(retorno!=0)
				break;
		}
		printf("\n");
		printf("carta jogada pelo computador: ");
		int x=0;
		for(i=0;i<p;i++){
			if(pc[i]>n){
				x=pc[i];
				pc[i]=99;
				r1=1;
				break;
			}
			else{
				x=pc[0];
				
			}
		}
		if(x==pc[0]){
			jogador[vi]=99;
			r1=0;
		}
		printf("%i\n",x);


		printf("\n--------------------------------\n");
		if(jogador[0]==99){
			printf("\n parabens você venceu\n");
			break;
		}
		else if(pc[0]==99){
			printf("\no computador venceu\n");
			break;
		}
	}


}
