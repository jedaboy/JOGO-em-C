#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "header.h"

//DECLARAÇÃO DE VARIAVEIS GLOBAIS



//DECLARAÇÃO DE PROTOTIPOS DE FUNÇÕES


char cria_loopgame()
{
    int vida = 3;
    //int fim = 0,
    char continuar;//tecla = 'b';
    char resultado;

    do
    {
        //cria e printa o mapa

        cria_mapa();
        //move os inimigos e o protagonista
        movimentacao(&resultado);

        vida--;

        mgotoxy( 1,23);
        printf("vidas %d\n",vida);

    }
    while(vida > 0 );
    if(resultado == 'g')
        printf("voce ganhou\n");
    else
        printf("\ngame over\n");

    printf("deseja jogar novamente ?");
    scanf("%c",&continuar);

    return continuar;
}

char menu(char *n)
{

  //  int menu_set;
    char  continua,tecla = ' ';
    printf("Novo jogo (n)\n");
    printf("\n");
    printf("Top 10 (t)\n");
    printf("\n");
    printf("Sair (r)\n");
    while((tecla != 'r') || (tecla != 't') || (tecla != 'n'))//enquanto a tecla for diferente de p entra no while
    {
        kbhit();
        tecla = getch();
        switch(tecla)
        {
        case 'n':

            do
            {
                continua = cria_loopgame();
            }
            while(continua != 'n');
            break;

        case 't':
            printf("top10:\n");
            break;
        case 'r':
            return 0;
            break;
        default:
            printf("essa opcao eh invalida\n");
        }

    }
}



//funcao de mov
int mgotoxy(int x,int y)
{
    COORD p = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
    HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(tela, p);
    return 0;
}


