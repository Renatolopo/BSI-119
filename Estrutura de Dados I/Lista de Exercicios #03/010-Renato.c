#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gconio.h>
#define TIME
#define DATE

typedef struct{
	
	char data[99],hora[99],compromisso[99],dif[99];
} Compromisso;

	

void setCompromisso(Compromisso c[]){
	printf("compromisso: ");
	scanf(" %[^\n]s",&c->compromisso);
	printf("\ndata: ");
	scanf(" %[^\n]s",&c->data);
	printf("\nhorariro: ");
	scanf(" %[^\n]s",&c->hora);
	
	
}
void getCompromisso(char c[99]){
	printf("%s\t",c);
}

void gethoraAtual(Compromisso ho[]){
	

	time_t hora = time(NULL);	
	strftime(ho, 99, "%H:%M:%S", localtime(&hora));
	
}
void  getDataAtual(Compromisso da[]){
	
	time_t data = time(NULL);
	
	strftime(da, 99, "%d-%m-%y", localtime(&data));
	
}
int getComparaData(char d1[99], char d2[99]){
	int cont=0;
	for(int i=0;i<8;i++){
		if(d1[i]==d2[i]){
			cont ++;
		}
	}
	
	if(cont==6){
		printf("\niguais\n");
		return 1;

	}else{
		return 0;
	}

}
void getDiferenca(char h1[99],char h2[99]){
	int h3[99],h4[99];
	for(int i=0;i<6;i++){
		h3[i] = 0;
	}
	for(int i=0;i<99;i++){
		h3[i] = h1[i]-'0';
		h4[i] = h2[i] - '0';
	}
	int hr,min,seg;
	if(((h3[0]*10+h3[1])-(h4[0]*10+h4[1]))>0){
		hr = ((h3[0]*10+h3[1])-(h4[0]*10+h4[1]));
	}else{
		hr = 0;
	}
	if(((h3[3]*10+h3[4])-(h4[3]*10+h4[4]))>0){
		min = ((h3[3]*10+h3[4])-(h4[3]*10+h4[4]));
	}else{
		min = 0;
	}
	if(((h3[6]*10+h3[7])-(h4[6]*10+h4[7]))>0){
		seg = ((h3[6]*10+h3[7])-(h4[6]*10+h4[7]));
	}else{
		seg = 0;
	}


	printf("%i horas %i minutos e %i segundos\n",hr,min,seg);
	
}
int main()
{   
	char ho[99],da[99];
	gethoraAtual(ho);
	getDataAtual(da);
	int x=0;
	while(1){
		

		Compromisso c[50];
		printf("\n===================================================\n");
			
		printf("1-cadastrar compromisso\n2-compromissos do dia\n3-sair\n");
		int n;
		scanf(" %i", &n);
		if(n==1){
			setCompromisso(&c);
			x++;
		}
		else if(n==2){
			printf("compromissos de hoje\n");
			for(int i=0;i<x;i++){
				if(getComparaData(da,c[i].data)==1){
					
					getCompromisso(c[i].compromisso);
					printf("em ");
					getDiferenca(c[i].hora,ho);

				}

			}

		}
		else if(n==3){
			return 0;
		}
		
		
		
 	}	


}
