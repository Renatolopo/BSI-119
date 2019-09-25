#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa que calcule quantos segundos já se passaram no dia de hoje.
Obs.: Para obter a data/horário atual utilize as expressões abaixo...
time_t horario = time(NULL);
printf("%s",asctime(localtime(&horario)));*/
int main()
{

	time_t horario = time(NULL);
	printf("%s ",asctime(localtime(&horario)));
	int t;
	t=strlen(asctime(localtime(&horario)));
	//printf("%i\n",t);
	int i;
	char vet[99];
	for(i=0;i<t;i++){
		vet[i]=asctime(localtime(&horario))[i];
	}
	//printf("%c",vet[17]);
	int c=11,x=12, n[6],cont=0;
	for(i=0;i<3;i++){
		n[cont]=asctime(localtime(&horario))[c]-'0';
		printf("%i ",n[cont]);
		cont++;
		n[cont]=asctime(localtime(&horario))[x]-'0';
		printf("%i ",n[cont]);
		cont++;
		c+=3;
		x+=3;
	}
	int hora, min, seg;
	hora = n[0]*10+n[1];
	//printf("\n%i\n",hora);
	min = n[2]*10+n[3];
	seg = n[4]*10+n[5];
	//printf("\n%i : %i : %i\n",hora,min,seg);
	seg += (hora*3600)+(min*60);
	printf("\n O dia teve %i segundos.\n", seg);
	
			
	
		
		
		
	

}
