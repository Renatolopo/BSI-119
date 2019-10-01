#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

typedef struct{
	int hora[2];
	int min[2];
	int seg[2];	
}Horario;

int main()
{
	Horario h1;
	time_t horario = time(NULL);
	//printf("%s\n",asctime(localtime(&horario)));
	int i;
	//printf("%c\n",asctime(localtime(&horario))[17]);
	int t;
	t = strlen(asctime(localtime(&horario)));
	char v[t];
	for(i=0;i<t;i++){
		v[i]=asctime(localtime(&horario))[i];
	}
	//printf("%s\n",v);
	for(i=0;i<2;i++){
		h1.hora[i]=v[11+i]-'0';
		h1.min[i]=v[14+i]-'0';
		h1.seg[i]=v[17+i]-'0';
	}
	for(i=0;i<2;i++){
		printf("%i",h1.hora[i]);
		
	}
	printf(":");
	for(i=0;i<2;i++){
		printf("%i",h1.min[i]);
		
	}
	printf(":");
	for(i=0;i<2;i++){
		printf("%i",h1.seg[i]);
		
	}
	printf("\n");
}
