#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int aluno[10][100], gabarito[10],i,j;
	srand(time(NULL));
	for(i=0;i<10;i++){
		for(j=0;j<100;j++){
			aluno[i][j]=1+rand()%4;
			printf("%i ",aluno[i][j]);
		}
		printf("\n");
	}
	printf("prencha o gabarito correto: \n");
	for(i=0;i<10;i++){
		while(1){
			scanf(" %i",&gabarito[i]);
			if((gabarito[i]>0)&&(gabarito[i]<=4)){
				break;
			}
		}
	}
	printf("\n gabarito: ");
	for(i=0;i<10;i++){
		printf("%i ",gabarito[i]);
	}
	int nota[100];
	for(i=0;i<100;i++){
		nota[i]=0;
	}
	int acm=0;
	for(i=0;i<10;i++){
		for(j=0;j<100;j++){
			if(aluno[i][j]==gabarito[i]){
				nota[j]++;
				acm++;
			}
		}
	}




	printf("\n-------------------------------\n");


	printf("\n notas:\n");
	for(i=0;i<100;i++){
		printf("aluno %i nota: %i\n",i+1,nota[i]);
	}
	printf("\n media das notas %i\n",acm/100);

	int aux;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(nota[i]<nota[j]){
				aux=nota[i];
				nota[i]=nota[j];
				nota[j]=aux;
			}
		}
	}

	printf("maior nota %i e menor nota %i\n",nota[99],nota[0]);
	int me=0,ma=0;
	for(i=0;i<100;i++){
		if(nota[i]==nota[0]){
			me++;
		}
		if(nota[i]==nota[99]){
			ma++;
		}
	}
	printf("%i alunos atigiram a maior nota e %i atigiram a menor nota.\n",ma,me);
}
