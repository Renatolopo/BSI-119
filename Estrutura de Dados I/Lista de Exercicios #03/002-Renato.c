#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
	int hora;
	int min;
	int seg;
	int dh,dm,ds;

} Horario;

int main()
{
	Horario h1;
	time_t horario = time(NULL);
	int t,i,vet[6];
	t=strlen(asctime(localtime(&horario)));
	char v[t];
	for(i=0;i<t;i++){
		v[i]=asctime(localtime(&horario))[i];
	}
	for(i=0;i<2;i++){
		vet[i]=v[11+i]-'0';
		vet[2+i]=v[14+i]-'0';
		vet[4+i]=v[17+i]-'0';
	}
	h1.hora = vet[0]*10+vet[1];
	h1.min = vet[2]*10+vet[3];
	h1.seg = vet[4]*10+vet[5];

	printf("hora atual %i:%i:%i\n",h1.hora,h1.min,h1.seg);

	
	int ho[6],t2,c=0,retorno;
	while(1){
		char hu[99];
		printf("digite um horario:\n ");
		scanf("%[^\n]s",hu);
		//scanf("%i",&t);
		t2=strlen(hu);

		retorno=0;
		for(i=0;i<t2;i++){
			if((hu[i]>='0')&&(hu[i]<='9')){
				ho[c]=hu[i]-'0';
				c++;
				retorno++;
			}
		}
		if(retorno==6)
			break;
	}
	int h,m,s;
	h = ho[0]*10+ho[1];
	m = ho[2]*10+ho[3];
	s = ho[4]*10+ho[5];
	printf("hora do ususario %i:%i:%i\n",h,m,s);
	h1.dh = (h1.hora-h);
	h1.dm = (h1.min-m);
	h1.ds = (h1.seg-s);
	printf("diferença da hora do usuario para hora atual: %i:%i:%i \n",h1.dh,h1.dm,h1.ds);



}
