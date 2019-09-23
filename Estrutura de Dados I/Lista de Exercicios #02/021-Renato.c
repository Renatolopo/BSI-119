#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Faça um programa que leia a data de nascimento do usuário no seguinte formato string DD/MM/AAAA. O seu
programa deve validar a entrada, tanto no formato indicado, quanto na real existência da data informada. Após isto,
obtenha a data atual, e calcule a idade completa do usuário (anos, meses e dias).*/
int main()
{
	time_t horario=time(NULL);
	//printf("%s\n",asctime(localtime(&horario)));
	int tamanho = strlen(asctime(localtime(&horario)));
	//printf("%i\n",tamanho);
	char t[25];
	strftime(t,25, "%d%m%Y", localtime(&horario));
    //printf("%s\n",t);
	tamanho = strlen(t);
	//printf("%i\n",tamanho);
	char data[20];
	int d[8],i,cont=0,c=0,t2;

	while(1){
		printf("data de nascimento: \n");
		scanf(" %s", data);
		t2 =strlen(data);
		cont = 0;
		for(i=0;i<t2;i++){
			if((data[i]>='0')&&(data[i]<='9')){
				d[c]=data[i]-'0';
				c++;
				cont++;
			}

		}
		if(cont==8)
			break;
	}
	cont=0;
	c=0;
	int atu[8];
	while(1){
		
		for(i=0;i<tamanho;i++){
			atu[i]=t[i]-'0';

			
		}
		break;
		
	}

	/*for(i=0;i<8;i++){
		printf("%i",d[i]);
	}
	printf("\n");
	
	for(i=0;i<8;i++){
		printf("%i",atu[i]);
	}*/

	int anos=(atu[4]*1000 + atu[5]*100 + atu[6]*10+atu[7]) - (d[4]*1000 + d[5]*100 + d[6]*10+d[7]);
	printf("\n%i anos, ",anos);

	int meses= (anos * 12)+ atu[2]*10 + atu[3];
	meses = meses+(12 - d[2]*10+d[3]);
	printf("%i meses, ",meses);

	int dia = anos * 365 + (atu[2]*10 + atu[3])*30 + atu[0]*10 +atu[1];
	printf(" %i dias\n",dia);
	

	


	
}
