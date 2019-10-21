#include <stdio.h>
#include <string.h>

typedef struct{
	int hora, min, seg;
} Tempo;
typedef struct{
	char nome[99];
	int num, categoria;
	Tempo t;
}Maratona;
void setTempo(char aux[99], Maratona m[], int c){
	int x[6],cont=0;
	for(int i=0;i<6;i++){
		x[i]=1;
	}
	for(int i=0;i<strlen(aux);i++){

		if((aux[i] >= '0')&&(aux[i] <= '9')){
			x[cont] = aux[i]-'0';
			
			cont++;
		}
		if(cont >= 6)
			break;
	}
	m[c].t.hora = x[0]*10+x[1];
	m[c].t.min = x[2]*10+x[3];
	m[c].t.seg = x[4]*10+x[5];
	printf("%i:%i:%i\n",m[c].t.hora, m[c].t.min, m[c].t.seg);
}
void setMaratona(Maratona m[], int c){
	printf("nome:\n");
	scanf(" %[^\n]s",m[c].nome);
	printf("numero de inscrição:\n");
	scanf(" %i",&m[c].num);
	printf("selecione a categoria\n1-amador masculino\n2-amador feminino\n3-profissional masculino\n4-profissional feminino\n");
	scanf(" %i",&m[c].categoria);
	printf("tempo:\n");
	char aux[99];
	scanf(" %[^\n]s",aux);
	setTempo(aux, m, c);

}
int cat(Maratona m[], int c,int x){
	for(int i=0;i<c;i++){
		if(m[i].categoria == x){
			return 1;
		}
	}
	return 0;
}
void getOrdena(Maratona m[], int c, int x){
	int aux;
	char aux2[99];
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if((m[i].categoria == x)&&(m[i].categoria == x)){//verifica se pertence a mesma categoria
				if(m[i].t.hora < m[j].t.hora){//compara as horas
					//troca nome
					strcpy(aux2,m[i].nome);
					strcpy(m[i].nome,m[j].nome);
					strcpy(m[j].nome,aux2);

					//troca numero de inscrição
					aux = m[i].num;
					m[i].num = m[j].num;
					m[j].num = aux;

					//trocar hora
					aux = m[i].t.hora;
					m[i].t.hora = m[j].t.hora;
					m[j].t.hora = aux;

					//trocar minutos
					aux = m[i].t.min;
					m[i].t.min = m[j].t.min;
					m[j].t.min = aux;

					//trocar segundos
					aux = m[i].t.seg;
					m[i].t.seg = m[j].t.seg;
					m[j].t.seg = aux;

					//troca categoria
					aux = m[i].categoria;
					m[i].categoria = m[j].categoria;
					m[j].categoria = aux;
				}
				else if(m[i].t.hora == m[j].t.hora){//se as horas forem iguais compara os minutos
					if(m[i].t.min < m[j].t.min){
						//troca nome
						strcpy(aux2,m[i].nome);
						strcpy(m[i].nome,m[j].nome);
						strcpy(m[j].nome,aux2);

						//troca numero de inscrição
						aux = m[i].num;
						m[i].num = m[j].num;
						m[j].num = aux;

						//trocar hora
						aux = m[i].t.hora;
						m[i].t.hora = m[j].t.hora;
						m[j].t.hora = aux;

						//trocar minutos
						aux = m[i].t.min;
						m[i].t.min = m[j].t.min;
						m[j].t.min = aux;

						//trocar segundos
						aux = m[i].t.seg;
						m[i].t.seg = m[j].t.seg;
						m[j].t.seg = aux;

						//troca categoria
						aux = m[i].categoria;
						m[i].categoria = m[j].categoria;
						m[j].categoria = aux;
				}
					else if(m[i].t.min == m[j].t.min){// se os minutos forem iguais compara os segundos
						if(m[i].t.seg < m[j].t.seg){
							//troca nome
							strcpy(aux2,m[i].nome);
							strcpy(m[i].nome,m[j].nome);
							strcpy(m[j].nome,aux2);

							//troca numero de inscrição
							aux = m[i].num;
							m[i].num = m[j].num;
							m[j].num = aux;

							//trocar hora
							aux = m[i].t.hora;
							m[i].t.hora = m[j].t.hora;
							m[j].t.hora = aux;

							//trocar minutos
							aux = m[i].t.min;
							m[i].t.min = m[j].t.min;
							m[j].t.min = aux;

							//trocar segundos
							aux = m[i].t.seg;
							m[i].t.seg = m[j].t.seg;
							m[j].t.seg = aux;

							//troca categoria
							aux = m[i].categoria;
							m[i].categoria = m[j].categoria;
							m[j].categoria = aux;
						}	
					}
				}
			}

		}
	}
	for(int i=0;i<c;i++){
		if(m[i].categoria == x){
			printf("%s \t%i \t %ih %im %is\n",m[i].nome, m[i].num, m[i].t.hora, m[i].t.min, m[i].t.seg);
		}
	}
}
void getMaratona(Maratona m[], int c){
	printf("=====================================================\n");
	
	if(cat(m,c,1) == 1){

		printf("Resultado: amador masculino\n");
		getOrdena(m,c,1);
		printf("\n\n");
			
	}
	if(cat(m,c,2) == 1){
		printf("Resultado: amador feminino\n");
		getOrdena(m,c,2);
		printf("\n\n");
			
	}
	if(cat(m,c,3) == 1){
		printf("Resultado: proficional masculino\n");
		getOrdena(m,c,3);
		printf("\n\n");
			
	}
	if(cat(m,c,4) == 1){
		printf("Resultado: proficional feminino\n");
		getOrdena(m,c,4);
		printf("\n\n");
			
	}
	printf("=====================================================\n");
	

}

int main(){
	Maratona m[50];
	int c=0;
	while(1){
		printf("1-Cadastrar maratonista\n2-Resultado final\n3-sair\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
			setMaratona(m,c);
			c++;
			break;
			case 2:
			getMaratona(m,c);
			break;
			case 3:
			return 0;
			break;
		}

	}
}
