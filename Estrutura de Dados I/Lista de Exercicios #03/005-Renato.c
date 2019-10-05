#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>
typedef struct{
	int x,y,n;
} Posicao;



int main()
{
	Posicao p[10];
	srand(time(NULL));
	
    int i;
    for(i=0;i<10;i++){
	
		
		p[i].x = 1+rand()%80;
		p[i].y = 1+rand()%20;

	}
	int c,aux,cont;
	for(i=0;i<80;i++){
		gotoxy(i,0);
		printf("-");
		gotoxy(i,25);
		printf("-");
	}
	for(i=0;i<25;i++){
		gotoxy(0,i);
		printf("|");
		gotoxy(80,i);
		printf("|");
	}
	for(i=0;i<10;i++){
		while(1){
			cont=0;
			aux = rand()%10;
			for(c=0;c<10;c++){
				if(aux==p[c].n){
					cont++;
				}
			}
			if(cont==0){
				p[i].n=aux;
				break;
			}
		}
	}
			
		
		
			
	for(i=0;i<10;i++){

    	gotoxy(p[i].x,p[i].y);
    	printf("%i",p[i].n);
	} 
	int xu,yu;
	gotoxy(2,22);
	printf("informe a cordenada X: ");  
	scanf("%i",&xu);
	gotoxy(2,23);
	printf("informe a cordenada Y: ");
	scanf(" %i",&yu);
	gotoxy(xu,yu);
	printf("X\n"); 
	int dis,menor=99,gi;
	for(i=0;i<10;i++){
		if(p[i].x > xu){
			dis = p[i].x - xu;
		}
		else if(p[i].x < xu){
			dis = xu - p[i].x;
		}
		if(p[i].y > yu){
			dis += p[i].y - yu;
		}
		else if(p[i].y < yu){
			dis += yu - p[i].y;
		}
		if(dis<menor){
			menor = dis;
			gi = i;
		}

	}
	gotoxy(2,24);
	printf("O ponto sorteado mais proximo do alvo é o: %i\n",p[gi].n);	
    
}
