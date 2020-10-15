#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "header.h"


//abre o arquivo texto  referente ao mapa


void cria_mapa()
{

    //tentar passar os parametros das nossas funcoes por referencia

    //coordenadas cx e cy que vao ser usadas como indice, para guardar as posicoes de cada elemento do mapa,(usado na fisica do game)
    int cx=0, cy=0;

    char nome[] = "C:\\Users\\jedaboy\\Desktop\\JOGO\\mapa.txt";//tera que adaptar para o local do arquivo mapa em seu computador
    char c;
    //   char  tecla1='u';

    FILE *arq;

    arq = fopen(nome, "r");

    //declaro tela
    HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);

    mgotoxy(0,0);
    {
        if (arq == NULL)
        {
            printf("\n erro\n");
            system("pause");
        }

        else
            while( ( c = fgetc ( arq ) ) != EOF )

            {
                //separo cada caractere, chamo a funccao s.c.t.a(tela , cada numero é referente a uma cor) assim ele pinta os ' ' de preto
                if(c != '#' )
                {

                    SetConsoleTextAttribute(tela,1);
                    putchar(c);
                }
                // e pinta os espacos # de verde
                if(c == '#')
                {
                    SetConsoleTextAttribute(tela,170);
                    putchar(c);
                }




                mapa[cx][cy] = c;      //coloca todos os caracteres na matriz do mapa

                if(cx < LARGURA )
                {
                    cx++;



                }
                else
                {
                    cy++;
                    cx = 0;
                }

            }
        fclose(arq);
    }
}

