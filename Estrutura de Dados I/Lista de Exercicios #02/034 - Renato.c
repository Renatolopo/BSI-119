#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("quantidade de alunos: ");
	scanf(" %i",&n);
	char nome[n][99];
	int i,j;
	for(i=0;i<n;i++){
		printf("aluno %i\n",i+1);
		scanf(" %[^\n]s",nome[i]);

	}
	int nota[n][4];
	for(i=0;i<n;i++){
		printf("\n----------------------------\n");
		printf("%s:\n",nome[i]);
		for(j=0;j<3;j++){
			printf("nota %i: ",j+1);
			scanf(" %i",&nota[i][j]);
			printf("\n");
		}
	}
	int acm, media;
	printf("\n==================================\n");
	for(i=0;i<n;i++){
		printf("\n");
		acm=0;
		printf("%s, ",nome[i]);
		for(j=0;j<3;j++){
			printf("nota %i = %i, ",j+1,nota[i][j]);
			acm+=nota[i][j];
		}
		media=acm/3;
		printf("media = %i  ",media);
		if(media>=6){
			printf("APROVADO");
		}
		else
		printf("REPROVADOO");
	}


}
