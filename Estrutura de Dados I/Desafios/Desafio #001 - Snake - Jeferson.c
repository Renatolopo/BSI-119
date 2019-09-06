#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include <time.h>

int main()
{
	int x=0, y=0;
	int a=0, b=0;
	int acertos=-1, move=0;
	int tecla; 
	int alvos;
	int largura, largura2, altura, altura2;
	
	while(1)
	{	
		int tam=0;
		int cobrinha[0][2];
		printf("Informe a quantidade de alvos: ");
		scanf(" %d", &alvos);
		int de = alvos;
		alvos += 1;
		move = 0;
		acertos = -1;
		x = a = (get_screen_columns())/2;
		y = b = (get_screen_rows())/2;
		srand(time(NULL));
		//laço por jogada
		while(alvos > 0)
		{
            //atribui o tamanho do terminal em tenpo real                                                            
			largura = largura2 =  get_screen_columns(); 
			altura = altura2 = get_screen_rows();
			altura2 -= 4;
			largura2 -= 4;
			//printa a barreira horizontal
			while(altura2 > 4)
			{
				gotoxy(4, altura2);
				printf("|");
				gotoxy(largura-4, altura2);
				printf("|");
				altura2--;
			}
			//printa a barreira vertical
			while(largura2 > 3)
			{
				gotoxy(largura2, 4);
				printf("-");
				gotoxy(largura2, altura-4);
				printf("-");
				largura2--;
			}
			//define a posição da fruta
			if (x == a && y == b)
			{
				a = 5 + (rand() %(largura - 10));
				b = 5 + (rand() %(altura - 10));
				alvos--;
				acertos++;
				tam++;
				cobrinha[tam][2];
			}
			//printa a posição da fruta
			gotoxy(a, b);
			printf("@");
			//printa o placar do jogo.
			gotoxy(largura-16, altura-(altura-2));
			printf("Movimentos: %d\n", move);
			gotoxy(largura-16, altura-(altura-3));
			printf("Acertos: %d/%d", acertos, de);
			//pega o comando do jogador
			tecla = getch();
			//verifica qual o comando precionado
			if (tecla == 'w')
				y--;
			else if (tecla == 'd')
				x++;
			else if (tecla == 's')
				y++;
			else if (tecla == 'a')
				x--;
			//printa a posição da cobrinha
			clrscr();
			for(int i=tam-1; i >= 0 ; i--)
			{
				cobrinha[i][0] = cobrinha[i-1][0];
				cobrinha[i][1] = cobrinha[i-1][1];
				/*cobrinha[2][0] = cobrinha[1][0];
				cobrinha[2][1] = cobrinha[1][1];
				cobrinha[1][0] = cobrinha[0][0];
				cobrinha[1][1] = cobrinha[0][1]*/
				if(i == 0)
				{
					cobrinha[0][0] = x;
					cobrinha[0][1] = y;
				}
			}
			for(int i=0; i < tam; i++)
			{
				gotoxy(cobrinha[i][0],cobrinha[i][1]);
					//printf("*");
				if (cobrinha[i][0] == cobrinha[0][0] && cobrinha[i][1] == cobrinha[0][1])
					printf("❂");
				else
					printf("✺");
			}
			//gotoxy(x, y);
			//printf("*");
			move++;
			//verificação de colisão com as paredes.
			if (x == 4)
				break;
			else if (x == (largura-4))
				break;
			else if (y == 4)
				break;
			else if (y == (altura -4))
				break;
			
		}
		clrscr();
		gotoxy(largura/2, altura/2);
		if (alvos == 0)
			printf("PARABÊNS!\n");
		else{
			printf("PERDEU!\n");}
		printf("Precione qualquer tecla para continuar!");
		getch();
		system(sleep(2));
		clrscr();		
	}
}
