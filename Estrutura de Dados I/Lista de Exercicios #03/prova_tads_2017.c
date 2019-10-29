#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct{
	char nome[99];
	int codp;
} Pessoa;
typedef struct{
	char descri[99];
	int codg;
} Grupo;
typedef struct{
	int coda, codb, codg;
} Relacionamento;

int verifCod(int cod, Pessoa p[], int x, Grupo g[], int y, int r){
	if(r == 1){ // Pessoa
		for(int i=0;i<x;i++){
			if(cod == p[i].codp){
				return i;
			}
		}
	}else if(r == 2){ //Grupo
		for(int i=0;i<y;i++){
			if(cod == g[i].codg){
				return i;
			}
		}
	}
	return -1;
}
int valiStrings(char str[99], Pessoa p[], int x, Grupo g[], int y, int r){
	if(r == 1){ // Pessoa
		for(int i=0;i<x;i++){
			if(strcmp(str,p[i].nome)==0){
				return i;
			}
		}
	}else if(r == 2){ //Grupo
		for(int i=0;i<y;i++){
			if(strcmp(str,g[i].descri)==0){
				return i;
			}
		}
	}
	return -1;
}
void setPessoa(Pessoa p[], int x, Grupo g[], int y){
	while(1){
		printf("nome:\n");
		scanf(" %[^\n]s",p[x].nome);
		if(valiStrings(p[x].nome, p,x, g, y, 1)==-1)
			break;
	}
	while(1){
		p[x].codp = rand()%100;
		if(verifCod(p[x].codp, p, x, g, y, 1)==-1){
			break;
		}
	}
	printf("codigo: %i\n",p[x].codp);
}
void setGrupo(Pessoa p[], int x, Grupo g[], int y, char grupo[99]){
	strcpy(g[y].descri,grupo);
	while(1){
		g[y].codg = rand()%100;
		if(verifCod(g[y].codg, p, x, g, y, 2)==-1)
			break;
	}
}
int setRelacionamento(Relacionamento r[], int z, Pessoa p[], int x, Grupo g[], int y){
	char nome[99],nome2[99];
	int ax;
	while(1){
		printf("nome do amigo A:\n");
		scanf(" %[^\n]s",nome);
		if(valiStrings(nome, p, x, g, y, 1)!=-1){
			r[z].coda = p[valiStrings(nome, p, x, g, y, 1)].codp;
			break;
		}
		printf("nome não existe\n");
	}
	printf("codigo de A: %i\n",r[z].coda);
	while(1){
		printf("nome do amigo B:\n");
		scanf(" %[^\n]s",nome2);
		if((valiStrings(nome2, p, x, g, y, 1)!=-1)&&(strcmp(nome,nome2)!=0)){
			r[z].codb = p[valiStrings(nome2, p, x, g, y, 1)].codp;
			break;
		}
		printf("nome não invalido\n");
	}
	printf("codigo de B: %i\n",r[z].codb);
	printf("descrição do grupo:\n");
	char grupo[99];
	scanf(" %[^\n]s",grupo);
	if(valiStrings(grupo, p, x, g, y, 2)==-1){
		setGrupo(p,x,g,y, grupo);
		ax=1;
		printf("grupo criado posi %i\n",y);
		
	}
	if(ax==1){
		r[z].codg = g[valiStrings(grupo, p, x, g, y+1, 2)].codg;
		printf("codigo: %i\n",r[z].codg);
		return 1;
	}
	r[z].codg = g[valiStrings(grupo, p, x, g, y, 2)].codg;
	printf("codigo: %i\n",r[z].codg);
	
	return 0;

}
void getRelatorio(Pessoa p[], Grupo g[], Relacionamento r[], int x,int y, int z, int ax){
	if(ax == 1){
		printf("nome  \t  \t codigo\n");
		for(int i=0;i<x;i++){
			printf("%s \t %i\n",p[i].nome, p[i].codp);
		}
	}else if(ax == 2){
		printf("nome  \t  \t codigo\n");
		for(int i=0;i<x;i++){
			printf("%s \t %i\n",g[i].descri, g[i].codg);
		}
	}else if(ax==3){
		printf("amigo A  \t amigo B \t descrição\n");
		for(int i=0;i<x;i++){
			printf("%s \t %s \t %s\n",p[verifCod(r[i].coda, p, x, g, y, 1)].nome, p[verifCod(r[i].codb, p, x, g, y, 1)].nome, g[verifCod(r[i].codg, p, x, g, y, 2)].descri);
		}
	}
}
void getPopular(Pessoa p[], int x, Relacionamento r[], int y){
	char mais[99];
	int maior=0,cont=0;
	for(int i=0;i<x;i++){
		cont=0;
		for(int j=0;j<y;j++){
			if((p[i].codp==r[j].coda)||(p[i].codp==r[j].codb)){
				cont++;
			}
		}
		if(cont > maior){
			strcpy(mais,p[i].nome);
			maior = cont;
		}
	}
	printf("%s e a pessoa mais popular\n",mais);
}
void getInfluencia(Pessoa p[], int x, Grupo g[], int y, Relacionamento r[], int z){
	char mais[99];
	int maior=0,cont,grp[y],c,c2=0;
	for(int i=0;i<x;i++){
		cont=0;
		for(int j=0;j<z;j++){
			if((p[i].codp==r[j].coda)||(p[i].codp==r[j].codb)){
				c=0;
				for(int k=0;k<y;k++){
					grp[k]=-1;
				}
				for(int k=0;k<y;k++){
					if(g[j].codg == grp[k]){
						c++;
					}
				}
				if(c==0){
					cont++;
					grp[c2]=g[j].codg;
					c2 ++;
				}
			}
		}
		if(cont > maior){
			strcpy(mais,p[i].nome);
			maior = cont;
		}
	}
		printf("%s e a pessoa mais influente\n",mais);

}
int main(){
	srand(time(NULL));
	Pessoa p[50];
	Grupo g[50];
	Relacionamento r[50];
	int c1=0, c2=0, c3=0;
	while(1){
		printf("==================================\n");
		printf("1) Cadastro de Pessoa \n2) Cadastro de Relacionamento \n3) Relatório: Pessoas \n4) Relatório: Grupos Sociais \n5) Relatório: Relacionamentos \n6) Pessoa Mais Popular \n7) Pessoa Mais Influente \n8) Sair\n");
		int re;
		scanf(" %i",&re);
		switch(re){
			case 1:
			setPessoa(p,c1,g,c2);
			c1++;
			break;
			case 2:
			if(setRelacionamento(r, c3, p, c1, g, c2)==1)
				c2++;
			c3++;
			break;
			case 3:
			getRelatorio(p,g,r,c1,c2,c3,1);
			break;
			case 4:
			getRelatorio(p,g,r,c1,c2,c3,2);
			break;
			case 5:
			getRelatorio(p,g,r,c1,c2,c3,3);
			break;
			case 6:
			getPopular(p,c1,r,c3);
			break;
			case 7:
			getInfluencia(p,c1,g,c2,r,c3);
			break;
			case 8:
			return 0;
			break;


		}
	}
}
