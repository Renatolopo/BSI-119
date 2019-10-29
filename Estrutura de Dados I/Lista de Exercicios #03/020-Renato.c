#include <stdio.h>
#include <string.h>

typedef struct{
	int codigo,leite,racao,peso,nasci[2];
	char abate;
} Gados;
int veriCodigo(int cod, Gados g[], int x){
	for(int i=0;i<x;i++){
		if(cod == g[i].codigo){
			return i;
		}
	}
	return -1;
}
char getAbate(Gados g[], int x){
	if(((2019-g[x].nasci[1])>=5)||(g[x].leite < 40)||((g[x].leite < 70)&&(g[x].racao > 50))||(g[x].peso > 18)){
		return 's';
	}else{
		return 'n';
	}
}

void setGado(Gados g[], int x){
	while(1){
		printf("codigo:\n");
		scanf(" %i",&g[x].codigo);
		if(veriCodigo(g[x].codigo, g, x)==-1)
			break;
	}
	printf("número de litros de leite por semana:\n");
	scanf(" %i",&g[x].leite);
	printf("qualtidades de ração consumida na semana kg:\n");
	scanf(" %i",&g[x].racao);
	printf("peso:\n");
	scanf(" %i",&g[x].peso);
	printf("nascimento mes/ano\n");
	char nas1[10];
	scanf(" %[^\n]s",nas1);
	int nas[10];
	for(int i=0;i<10;i++){
		nas[i] = nas1[i]-'0';
	}
	
	
	g[x].nasci[0] = nas[0]*10+nas[1];
	g[x].nasci[1] = nas[3]*1000+nas[4]*100+nas[5]*10+nas[6];	
	printf("nascimento: %i/%i \n", g[x].nasci[0], g[x].nasci[1]);
	g[x].abate = getAbate(g,x);
	printf("abate : %c\n",g[x].abate);

}
void getAltera(Gados g[], int x){
	int cod;
	while(1){
		printf("codigo do animal:\n");
		scanf(" %i",&cod);
		if(veriCodigo(cod,g,x)!=-1)
			break;

	}
	setGado(g, veriCodigo(cod,g,x));

}
void getRelatorio(Gados g[], int fim, int in){
	
	for(int i=in;i<fim;i++){
		printf("%i\t %iL\t %iKg\t %i arroba\t %i/%i\t %c\n",g[i].codigo, g[i].leite, g[i].racao, g[i].peso, g[i].nasci[0], g[i].nasci[1], g[i].abate);
	}
}
void getReAbate(Gados g[], int x){
	printf("codigo\tleite\tração\tpeso\tnascimento\t abate\n");
	for(int i=0;i<x;i++){
		
		if(g[i].abate == 's'){
			getRelatorio(g,i+1,i);
			g[i].abate = 'a';
		}
	}
}
void getLeite(Gados g[], int x){
	int acm=0;
	for(int i=0; i<x;i++){
		acm += g[i].leite;
	}
	printf("são produzidos %iL de leite por semana\n",acm);
}
void getAbatidos(Gados g[], int x){
	int acm=0;
	for(int i=0;i<x;i++){
		if(g[i].abate=='a'){
			acm += g[i].peso;
		}	
	}
	printf("total de %i arrobas de animais abatidos\n", acm);
}
void getRacao(Gados g[], int x){
	int acm=0;
	for(int i=0;i<x;i++){
		acm += g[i].racao;
	}
	printf("são nescessario %iKg de ração por semana\n",acm);
}
int main(){
	Gados g[50];
	int r,x=0;
	while(1){
		printf("1-Cadastro de animais \n2-Alteração dos dados de animais \n3-Relatório de animais para abate \n4-Relatório da quantidade total de leite produzida por semana \n5-Relatório do peso total de animais abatidos \n6-Relatório da quantidade total de ração necessária por semana\n7-sair\n");
		scanf(" %i",&r);
		switch(r){
			case 1:
			setGado(g, x);
			x++;
			break;
			case 2:
			getAltera(g,x);
			break;
			case 3:
			getReAbate(g,x);
			break;
			case 4:
			getLeite(g,x);
			break;
			case 5:
			getAbatidos(g,x);
			break;
			case 6:
			getRacao(g,x);
			break;
			case 7:
			return 0;
			break;
		}
 	}
}
