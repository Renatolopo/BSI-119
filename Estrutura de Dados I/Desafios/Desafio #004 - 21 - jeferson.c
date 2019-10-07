#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>


typedef struct{
	int num;
	char naipe;
	}Carta;


void gera_carta(Carta *baralho, int i){
	
	while(1)
	{
		int valor, q = 0; 
		int co = 0, or = 0, es = 0, pa = 0;
		char tipo;
		
		valor = 1 + rand() %13;
		
		for(int c=0; c < i; c++)
		{
			tipo = baralho[c].naipe;
			if(valor == baralho[c].num)
			{
				q += 1;
				if(q==4)
					break;
				if(tipo == 'E')
					es = 1;
				else if(tipo == 'C')
					co = 1;
				else if(tipo == 'O')
					or = 1;
				else if(tipo == 'P')
					pa = 1;		
			}
		}
		//variável para embaralha os naipes
		int em;
		em = rand() %4;
		if(q<4)
		{	
			baralho[i-1].num = valor;
			if(es == 0 && em == 0)
				baralho[i-1].naipe = 'E';
			else if (co == 0 && em == 1)
				baralho[i-1].naipe = 'C';
			else if (or == 0 && em == 2)
				baralho[i-1].naipe = 'O';
			else
				baralho[i-1].naipe = 'P';
			
			break;
		}
			
	}

}


int soma_cartas(Carta *jogador, int c)
{
	int soma=0;
	for(int i=0; i < c; i++)
	{
		soma += jogador[i].num;
	}

	return soma;
}


void mao_jogador(Carta* jogador, int r)
{
	gotoxy(20,3);
	printf("MÂO DO JOGADOR!\n");
	gotoxy(3,4);
	printf("--------------------------------------------------------\n");
	for(int i=5; i<14; i++)
	{
		gotoxy(3, i);
		printf("|");
		gotoxy(59, i);
		printf("|");
	}
	gotoxy(3, 14);
	printf("--------------------------------------------------------\n");
	
	//Cartas do jogador
	int x = 5, y=5, z=6, t=6;
	for(int c=0; c < r ; c++)
	{
		gotoxy(x,y);
		printf("----------\n");
		for(int i=y+1; i<11; i++)
		{
			gotoxy(x, i);
			printf("|");
			gotoxy(x+9, i);
			printf("|");
		}
		gotoxy(x, 11);
		printf("----------\n");
		x += 11;
		
		gotoxy(z, t);
		printf("%i", jogador[c].num);
		gotoxy(z+3,t+2);
		printf("%c", jogador[c].naipe);
		gotoxy(z+6,t+4);
		printf("%i", jogador[c].num);
		z += 11;
	}
	gotoxy(5, 13);
	printf("Pontos: %i\n\n", soma_cartas(jogador, r));
}

int main()
{
	while(1)
	{
		printf("------> JOGO DO 21 <------\n\n");
		printf("Precione qualquer tecla para continuar");
		getch();
		
		printf("\nComeçando...\n");
		sleep(1);
		int c=1;
		
		srand(time(NULL));
		clrscr();
		
		//começa o jogo
		while(1)
		{
			gotoxy(18,1);
			printf("------> JOGO DO 21 <------\n\n");
			//vetor do tipo carta, onde vai armazenar as cartas do jogador
			Carta jogador[0];
			
			char op;
			//condição pra sempre iniciar com uma carta
			if(c == 1){
				//função para gera as cartas
				gera_carta(jogador, c);
				c++;
				//função pra mostra as cartas e os pontos
				mao_jogador(jogador, c-1);
			}
			else
			{
				//estrutura para validar a resposta do jogador 
				while(1)
				{
					mao_jogador(jogador, c-1);
					printf("Tirar mais uma carta: ");
					scanf(" %c", &op);
					op = toupper(op);
								
					if (op == 'S' || op == 'N')
						break;
					else
						printf("INVÁLIDO! somente [S/N]\n");
				}

				if(op == 'S'){
					gera_carta(jogador, c);
					 c++;
				}
			}
					
			mao_jogador(jogador, c-1);
			
			//função pra somar as cartas do jogador soma_cartas(x, x)
			if(soma_cartas(jogador, c-1) == 21)
			{
				gotoxy(17,17);
				printf("PARABÉNS VOCÊ VENCEU!\n\n");
				break;
			}
			else if(soma_cartas(jogador, c-1) > 21)
			{
				gotoxy(17,17);
				printf("VOCÊ PERDEU!\n\n");
				break;
			}
		}
		
		char res;
		printf("Jogar novamente: ");
		scanf(" %s", &res);
		
		if (res == 'n')
			break;
			
		clrscr();
	}
	
	clrscr();
	//imprime todas as cartas
	Carta cartas[0];
	for(int i=0; i < 52; i++)
	{
		gera_carta(cartas, i+1);
		printf("carta = %i naipe = %c\n", cartas[i].num, cartas[i].naipe);
		
	}
	
		
	return 0;
}

