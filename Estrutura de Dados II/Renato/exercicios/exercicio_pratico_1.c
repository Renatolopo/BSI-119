#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int idade;
	char nome[99];
} Pessoa;
void setPesoa(Pessoa p[], int c){
	printf("Nome: ");
	scanf(" %[^\n]s", p[c].nome);
	printf("Idade: ");
	scanf(" %i", &p[c].idade);
	
}
void getPesoa(Pessoa p[], int c){
	printf("---------------------------\n");
	printf("Nome \t idade\n");
	for(int i=0;i<c;i++){
		printf("%s \t %i\n",p[i].nome, p[i].idade);
	}
}
/*void
insercao (int n, int v[])
{
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}*/

void selecao(Pessoa p[], int c){
	for(int j=1; j<c; j++){
		int x = p[j].idade;
		char name[99];
		strcpy(name,p[j].nome);
		int i;
		for(i = j-1;p[i].idade >= x; i--){
			p[i+1].idade = p[i].idade;
			strcpy(p[i+1].nome,p[i].nome);
		}
		p[i+1].idade = x;
		strcpy(p[i+1].nome,name);
	}
	for(int i=0;i<c;i++){
		printf("%i\t %s\n",p[i].idade,p[i].nome);
	}
}

/*FUNÇÃO INSERTION_SORT (A[], tamanho)
        VARIÁVEIS
                i, j, eleito
        PARA i <- 1 ATÉ (tamanho-1) FAÇA
                eleito <- A[i];
                j <- i-1;
                ENQUANTO ((j>=0) E (eleito < A[j])) FAÇA
                          A[j+1]:= A[j];
# Elemento de lista numerada
                          j:=j-1;
                FIM_ENQUANTO
                A[j+1] <- eleito;
        FIM_PARA
FIM*/

void insercao(Pessoa p[], int c){
	int i, j, x;
	char ax[99];
	for(i=0;i<c;i++){
		x = p[i].idade;
		strcpy(ax,p[i].nome);
		j = i-1;
		while((j>=0)&&(x < p[j].idade)){
			p[j+1].idade = p[j].idade;
			strcpy(p[j+1].nome,p[j].nome);
			j--;
		}
		p[j+1].idade = x;
		strcpy(p[j+1].nome, ax);
	}
	for(i=0;i<c;i++){
		printf("%i\t %s\n",p[i].idade, p[i].nome);
	}
}

int main(){
	Pessoa p[50];
	int c = 0;
	while(1){
		printf("***** Main ********\n");
		printf("1-Cadastrar\t 2-Mostrar dados\t 3-sair\t 4-ordenar por seleção\t 5-ordna por inserção\n");
		int r;
		scanf(" %i",&r);
		switch(r){
			case 1:
				setPesoa(p, c);
				c ++;
				break;
			case 2:
				getPesoa(p, c);
				break;
			case 3:
				return 0;
				break;
			case 4:
				selecao(p, c);
				break;
			case 5:
				insercao(p, c);
				break;
		}
		
	}

}