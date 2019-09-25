#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, x, y;
	printf("informe N: ");
	scanf(" %i", &n);
	printf("informe X: ");
	scanf(" %i", &x);
	printf("informe Y: ");
	scanf(" %i", &y);

	int i,c,vet[n],num,cont;
	srand(time(NULL));
	for(i=0;i<n;i++){
		while(1){
			num=x+rand()%y;
			cont=0;
			for(c=0;c<i;c++){
				if(num == vet[c])
					cont++;
			}
			if(cont == 0){
				vet[i]=num;
				printf("%i ",vet[i]);
				break;
			}
		}
	}
	int v[n],aux;
	printf("\n");
	for(i=0;i<n;i++){
		v[i] = vet[i];
	}
	for(i=0;i<n;i++){
		for(c=0;c<i;c++){
			if(v[i]<v[c]){
				aux = v[i];
				v[i] = v[c];
				v[c] = aux;
			}
		}
		
	}
	int v2[n];
	printf("\n");
	for(i=0;i<n;i++){
		v2[i] = vet[i];
	}
	for(i=0;i<n;i++){
		for(c=0;c<i;c++){
			if(v2[i]>v2[c]){
				aux = v2[i];
				v2[i] = v2[c];
				v2[c] = aux;
			}
		}
		
	}
	for
		(i=0;i<n;i++){
		printf("%i ",v[i]);
	}
	printf("\n");
	for
		(i=0;i<n;i++){
		printf("%i ",v2[i]);
	}
	printf("\n");
	int i2,c2;
	for(i=0;i<n/2;i++){
		printf("\n");
		for(c=0;c<n;c++){
			if(v[i]==vet[c]){
					
				vet[c] = v2[i];
				for(c2=0;c2<n;c2++){
					if((v2[i]==vet[c2])&&(c2!=c)){
							vet[c2] = v[i];
							//printf("ola ");
							break;
							
							
					}

				}

			}
			
		}
		for(i2=0;i2<n;i2++){
			
			printf("%i \t",vet[i2]);
		}
	}
}
		
