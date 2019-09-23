#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int main()
{
	int k, x;
	while(1){
		printf("informe K (maior que 0): \n");
		scanf(" %i",&k);
		printf("informe X (maior que k): \n");
		scanf(" %i", &x);

		if((k > 0)&&(x > k))
			break;
		else{
			system("clear");
			printf("informação invalida digite novamente. \n");
		}
	}
	int v1[k],v2[k];
	srand(time(NULL));
	int i,c,cont=0,n,n2;
	for(i=0; i<k; i++){
		while(1){
			n = rand()%x;
			cont=0;
			for(c=0; c<i; c++){
				if(n == v1[c])
					cont ++;
				}
				if(cont == 0)
				{
					v1[i] = n;
					break;
				}
				
			}
		}
	
		while(1){
			n2 = rand()%x;
			cont=0;
			for(c=0; c<i; c++){
				if(n2 == v2[c])
					cont ++;
				}
				if((cont == 0)&&(v1[i] != v2[i]))
				{
					v2[i] = n2;
					break;
				}
				
			}
			
		
	
	printf("**********************************\n");
	printf("vetor 1: \n");
	for(i=0; i<k; i++){
		printf("%i\t",v1[i]);
	}
	
	printf("\n");
	printf("**********************************\n");
	printf("vetor 2: \n");
	for(i=0; i<k; i++){
		printf("%i\t",v2[i]);
	}
	
}
