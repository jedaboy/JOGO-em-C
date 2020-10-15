#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "header.h"


//DECLARAÇÃO DE VARIAVEIS GLOBAIS

void movimentacao(char* resultado)
{
    // primeiro grupo de variaveis
    //coordendads do protagonista,direcao do protagonista, e um contador i
    int cx = 4, cy = 3, d = 7,i,j,k,x=1,flag = 0,vida = 1;

    //segundo grupo de variaveis
    //probabilidade de direcao, de quantidade de passos se sera 2 ou 4, e de qual inimgo se movera,mov guarda a quantidade de passos
    int prob1,prob2, prob3,prob_anterior,mov;

    float timer = 80;
    //terceiro grupo de variaveis
    //inicia os guardas e depois atualiza as posicoes deles na atual localizacao

    int posicaoatualx_00 = 4,  posicaoatualy_00  = 19,  lanterna_atualx_00 = 0,lanterna_atualy_00 = 0,  dir_00 = 0;
    int posicaoatualx_01 = 58, posicaoatualy_01 = 1,    lanterna_atualx_01 = 0,lanterna_atualy_01 = 0,  dir_01 = 0;
    int posicaoatualx_02 = 38, posicaoatualy_02 = 2,    lanterna_atualx_02 = 0,lanterna_atualy_02 = 0,  dir_02 = 0;
    int posicaoatualx_03 = 43, posicaoatualy_03 = 16,   lanterna_atualx_03 = 0,lanterna_atualy_03 = 0,  dir_03 = 0;
    int posicaoatualx_04 = 19,  posicaoatualy_04  =  2,  lanterna_atualx_04 = 0,lanterna_atualy_04 = 0,  dir_04 = 0;
    int posicaoatualx_05 = 67, posicaoatualy_05 = 16,   lanterna_atualx_05 = 0,lanterna_atualy_05 = 0,  dir_05 = 0;
    int posicaoatualx_06 = 33, posicaoatualy_06 = 19,   lanterna_atualx_06 = 0,lanterna_atualy_06 = 0,  dir_06 = 0;
    int posicaoatualx_07 = 6,  posicaoatualy_07  = 14,  lanterna_atualx_07 = 0,lanterna_atualy_07 = 0,  dir_07 = 0;


    // pega a entrada do usuario
    unsigned char tecla1 = 'u',tecla_anterior,tecla_velocidade;

    LANT lanterna[8];
    INIMIGO guarda;
    HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
    CHAVE key;

    key.cx = 71, key.cy = 19;
   // srand(time(NULL));

// inicializa o protagonita nessas coordenadas
    cx = 2, cy = 2;

    while(tecla1!= 'y'  ) //esse primeiro laço possui la no fim a funcao pra printar desenho do protagonista
    {
        while(tecla1!='y' && _kbhit()) //esse segundo laço move o protagonista real, se ele se move, sai desse laco cai no primeiro e atualiza o desenho e a posicao do protagonista
        {
            if(tecla1!='y') //pega a tecla que o usuario digitou
            {
                tecla1 =_getch();
            }

            i = 0,j=0;
            //cria e move os inimigos
            while(!_kbhit())
            {


                prob1 = rand()%4;//define a probabilidade de cada direca0

                    /*if(prob1==0)
                 {
                     prob1 = 3;
                 } */


                prob2 = rand()%2;//define a probabilidade do modulo de movimento
                if(prob2==0)
                    mov = 4;
                if(prob2==1)
                    mov = 4;

                prob3 =  rand()%8;//define a probabilidade cada possivel lugar onde sera inicializado o guarda

                mgotoxy(1,27);
                printf("%d",prob3);


                //condicoes que definem qual guarda vai se mover no momento atual da funcao

                mgotoxy(3,24);
                printf("%d",i);

                if(prob3 == 0)
                {
                    guarda.cx = posicaoatualx_00, guarda.cy = posicaoatualy_00;
                    prob_anterior = dir_00;

                    if(j!=0)
                        lanterna[0].cx = lanterna_atualx_00, lanterna[0].cy = lanterna_atualy_00;
                }

                if(prob3 == 1 )
                {
                    guarda.cx = posicaoatualx_01, guarda.cy = posicaoatualy_01;
                    prob_anterior = dir_01 ;
                    if(j!=0)
                        lanterna[1].cx = lanterna_atualx_01, lanterna[1].cy = lanterna_atualy_01;
                }
                if(prob3 == 2 )
                {
                    guarda.cx = posicaoatualx_02, guarda.cy = posicaoatualy_02;
                    prob_anterior = dir_02;
                    if(j!=0)
                        lanterna[2].cx = lanterna_atualx_02, lanterna[2].cy = lanterna_atualy_02;
                }
                if(prob3 == 3 )
                {
                    guarda.cx = posicaoatualx_03, guarda.cy = posicaoatualy_03;
                    prob_anterior = dir_03;

                    if(j!=0)
                        lanterna[3].cx = lanterna_atualx_03, lanterna[3].cy = lanterna_atualy_03;
                }
                if(prob3 == 4 )
                {
                    guarda.cx = posicaoatualx_04, guarda.cy = posicaoatualy_04;
                    prob_anterior = dir_04;
                    if(j!=0)
                        lanterna[4].cx = lanterna_atualx_04, lanterna[4].cy = lanterna_atualy_04;
                }
                if(prob3 == 5 )
                {
                    guarda.cx = posicaoatualx_05, guarda.cy = posicaoatualy_05;
                    prob_anterior = dir_05;
                    if(j!=0)
                        lanterna[5].cx = lanterna_atualx_05, lanterna[5].cy = lanterna_atualy_05;
                }
                if(prob3 == 6 )
                {
                    guarda.cx = posicaoatualx_06, guarda.cy = posicaoatualy_06;
                    prob_anterior = dir_06;
                    if(j!=0)
                        lanterna[6].cx = lanterna_atualx_06, lanterna[6].cy = lanterna_atualy_06;
                }
                if(prob3 == 7 )
                {
                    guarda.cx = posicaoatualx_07, guarda.cy = posicaoatualy_07;
                    prob_anterior = dir_07; // salva direção anterior de cada guarda
                    if(j!=0)
                        lanterna[7].cx = lanterna_atualx_07, lanterna[7].cy = lanterna_atualy_07;
                }


                k = 0;
                i = 0;
                //faz o guarda atual que foi selecionado pela prob3 andar uma quantidade de passos definido pela prob2 numa direcao definada pela pro1
                while(mov > i && !_kbhit())
                {
                    // atualiza o guarda na direcao selecionada e apaga os rastros dele e da lanterna (incompleto)
                    //tambem sera aqui que o protagonista vai ser detectado


                    switch(prob1)
                    {

                        case 0:
                        {
                            //apaga rastro nas outras direções
                            if(prob_anterior != prob1)
                            {
                                //pega a tecla anterior para saber qual direção apagar
                                switch(prob_anterior)
                                {

                                case 1:
                                {


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-2);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-3);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy-3);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-3);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-4);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-4);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy-4);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy-4);
                                         printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy-4);
                                         printf(" ");
                                    }

                               /*    for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;

                                }
                                case 3:
                                {

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy+2);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+3]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy+3);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+3]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy+3);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy+3);
                                         printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy+4);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy+4);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy+4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy+4);
                                         printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy+4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy+4);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+4]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy+4);
                                         printf(" ");
                                    }


                                  /*  for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;
                                }
                                case 2:
                                {
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy-1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy+1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy+1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy-1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy-2);
                                        printf(" ");
                                    }

                               /*   for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;
                                }

                                }
                            }


                            //movimenta o guarda para a direita
                            if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                guarda.cx--;

                            if(mapa[guarda.cx+1][guarda.cy]!= '#')
                            {
                                mgotoxy(guarda.cx+1,guarda.cy);
                                printf(" ");
                            }



                            SetConsoleTextAttribute(tela,14);

                            //primeiro feixe unico

                            if(mapa[guarda.cx-2][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx-1][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    mgotoxy(guarda.cx-2,guarda.cy);
                                    printf("%c",178);
                                }
                            }

                            //apaga rastro do primeiro feixe unico
                            if(mapa[guarda.cx-1][guarda.cy]!= '#')
                            {

                                mgotoxy(guarda.cx-1, guarda.cy);
                                    printf(" ");
                            }



                            //segundo feixe (triplo)

                            //feixe central
                            if(mapa[guarda.cx-3][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx-2][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx-1][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx-3,guarda.cy);
                                        printf("%c",177);
                                    }
                                }
                            }

                            //feixe inferior
                            if(mapa[guarda.cx-3][guarda.cy+1]!= '#')
                            {
                                if(mapa[guarda.cx-2][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx-1][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx-3,guarda.cy+1);
                                        printf("%c",177);
                                    }
                                }
                            }
                            //apaga rastro  feixe inferior
                            if(mapa[guarda.cx-2][guarda.cy+1]!= '#')
                            {

                                mgotoxy(guarda.cx-2, guarda.cy+1);
                                    printf(" ");
                            }
                            //feixe superior
                            if(mapa[guarda.cx-3][guarda.cy-1]!= '#')
                            {
                                if(mapa[guarda.cx-2][guarda.cy+1]!= '#')
                                {
                                    if(mapa[guarda.cx-2][guarda.cy-1]!= '#')
                                    {
                                        if(mapa[guarda.cx-1][guarda.cy-1]!= '#')
                                        {
                                            if(mapa[guarda.cx-1][guarda.cy+1]!= '#')
                                            {
                                                mgotoxy(guarda.cx-3,guarda.cy-1);
                                                printf("%c",177);
                                            }
                                        }
                                    }
                                }
                            }
                            //apaga rastro feixe superio
                            if(mapa[guarda.cx-2][guarda.cy-1]!= '#')
                            {

                                 mgotoxy(guarda.cx-2, guarda.cy-1);
                                    printf(" ");
                            }



                            //terceiro feixe quintuplo

                            //detecção no ultimo feixe central
                            if(guarda.cx-4 == cx && guarda.cy == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe inferior intermediario
                            if(guarda.cx-4 == cx && guarda.cy-1 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }
                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe inferior
                            if(guarda.cx-4 == cx && guarda.cy-2 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe superior intermediario
                            if(guarda.cx-4 == cx && guarda.cy+1 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe superior
                            if( guarda.cx-4 == cx && guarda.cy+2 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }



                            //sistema de luzes do ultimo feixe

                            // apaga ultimo feixe superior
                            if(mapa[guarda.cx-3][guarda.cy+2]!= '#')
                            {

                                mgotoxy(guarda.cx-3, guarda.cy+2);
                                    printf(" ");
                            }

                            // apaga ultimo feixe inferior
                            if(mapa[guarda.cx-3][guarda.cy-2]!= '#')
                            {

                                mgotoxy(guarda.cx-3, guarda.cy-2);
                                    printf(" ");
                                }


                            //luz do ultimo feixe cetral
                            if(mapa[guarda.cx-4][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                        {
                                            mgotoxy(guarda.cx-4,guarda.cy);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe inferior intermediario
                            if(mapa[guarda.cx-4][guarda.cy+1]!= '#')
                            {
                                if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                        {
                                            if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                            {
                                                if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                                {
                                                    if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                                    {
                                                        mgotoxy(guarda.cx-4,guarda.cy+1);
                                                        printf("%c",176);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe inferior
                            if(mapa[guarda.cx-4][guarda.cy+2]!= '#')
                            {
                                if(mapa[guarda.cx-3][guarda.cy+1]!= '#')
                                {
                                    if(mapa[guarda.cx-2][guarda.cy+1]!= '#')
                                    {
                                        if(mapa[guarda.cx-1][guarda.cy+1]!= '#')
                                        {
                                            mgotoxy(guarda.cx-4,guarda.cy+2);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }
                            // luz do ultimo feixe superior intermediario
                            if(mapa[guarda.cx-4][guarda.cy-1]!= '#')
                            {
                                if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                        {
                                            if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                            {
                                                if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                                {
                                                    if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                                    {
                                                        mgotoxy(guarda.cx-4,guarda.cy-1);
                                                        printf("%c",176);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            // luz do ultimo feixe superior
                            if(mapa[guarda.cx-4][guarda.cy-2]!= '#')
                            {
                                if(mapa[guarda.cx-3][guarda.cy-1]!= '#')
                                {
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                        {
                                            if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                            {
                                                if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                                {
                                                    if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                                    {
                                                        if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                                        {
                                                            mgotoxy(guarda.cx-4,guarda.cy-2);
                                                            printf("%c",176);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }

                            }


                    ///
                          /*  for(i=0; i<5; i++)

                            {
                                if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                {

                                    mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                    printf(" ");
                                }
                            } */
                           ///

                            if(j == 0)
                                j++;


                            break;
                        }
                        case 1:
                        {
                            if( prob_anterior != prob1)
                            {
                                switch(prob_anterior)
                                {

                                case 3:
                                {


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+2);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx-1, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx+1, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+4);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx+1, guarda.cy+4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx-1, guarda.cy+4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx-2, guarda.cy+4);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx+2, guarda.cy+4);
                                        printf(" ");
                                    }

                                    /* for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;

                                }
                                case 0:
                                {

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                    {

                                        mgotoxy(guarda.cx-2, guarda.cy);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico%c
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {

                                        mgotoxy(guarda.cx-3, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy-1]!= '#')
                                    {

                                        mgotoxy(guarda.cx-3, guarda.cy-1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy+1]!= '#')
                                    {

                                        mgotoxy(guarda.cx-3, guarda.cy+1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy]!= '#')
                                    {

                                        mgotoxy(guarda.cx-4, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+1]!= '#')
                                    {

                                        mgotoxy(guarda.cx-4, guarda.cy+1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-1]!= '#')
                                    {

                                        mgotoxy(guarda.cx-4, guarda.cy-1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx-4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx-4, guarda.cy-2);
                                        printf(" ");
                                    }

                                  /*  for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    }*/
                                    break;
                                }
                                case 2:
                                {
                                     //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy-1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy+1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy+1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy-1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy-2);
                                        printf(" ");
                                    }
                                    break;
                                }

                                }
                            }


                            // movimenta o guarda para baixo
                            if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                guarda.cy--;

                            if(mapa[guarda.cx][guarda.cy+1]!= '#')
                            {
                                mgotoxy(guarda.cx,guarda.cy+1);
                                printf(" ");
                            }



                            SetConsoleTextAttribute(tela,14);

                            //primeiro feixe unico

                            if(mapa[guarda.cx][guarda.cy-2]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy-1]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    mgotoxy(guarda.cx,guarda.cy-2);
                                    printf("%c",178);
                                }
                            }

                            //apaga rastro do primeiro feixe unico
                            if(mapa[guarda.cx][guarda.cy-1]!= '#')
                            {
                                lanterna[prob3].rastro[0].cx = guarda.cx, lanterna[prob3].rastro[0].cy = guarda.cy-1;
                                 mgotoxy(guarda.cx, guarda.cy-1);
                                    printf(" ");
                            }



                            //segundo feixe (triplo)

                            //feixe central
                            if(mapa[guarda.cx][guarda.cy-3]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy-2]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx][guarda.cy-1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx,guarda.cy-3);
                                        printf("%c",177);
                                    }
                                }
                            }


                            //apaga rastro feixee esquerdo
                            if(mapa[guarda.cx-1][guarda.cy-2]!= '#')
                            {

                                mgotoxy(guarda.cx-1, guarda.cy-2);
                                    printf(" ");
                            }
                            //feixe esquerdo
                            if(mapa[guarda.cx-1][guarda.cy-3]!= '#')
                            {
                                if(mapa[guarda.cx-1][guarda.cy-2]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx-1][guarda.cy-1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx-1,guarda.cy-3);
                                        printf("%c",177);
                                    }
                                }
                            }


                            //apaga rastro  feixe direito
                            if(mapa[guarda.cx+1][guarda.cy-2]!= '#')
                            {


                                 mgotoxy(guarda.cx+1, guarda.cy-2);
                                    printf(" ");
                            }
                            //feixe direito
                            if(mapa[guarda.cx+1][guarda.cy-3]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                {

                                    if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                    {
                                        mgotoxy(guarda.cx+1,guarda.cy-3);
                                        printf("%c",177);
                                    }


                                }
                            }



                            //terceiro feixe quintuplo

                            //detecção no ultimo feixe central
                            if(guarda.cx == cx && guarda.cy-4 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe inferior intermediario
                            if(guarda.cx+1 == cx && guarda.cy+4== cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }
                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe inferior
                            if(guarda.cx-4 == cx && guarda.cy+2 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe superior intermediario
                            if(guarda.cx-1 == cx && guarda.cy-4 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe superior
                            if( guarda.cx== -4 && guarda.cy == cy-2)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }



                            //sistema de luzes do ultimo feixe

                            // apaga ultimo feixe superior
                            if(mapa[guarda.cx+2][guarda.cy-3]!= '#')
                            {

                                 mgotoxy(guarda.cx+2, guarda.cy-3);
                                    printf(" ");
                            }

                            // apaga ultimo feixe inferior
                            if(mapa[guarda.cx-2][guarda.cy-3]!= '#')
                            {

                                 mgotoxy(guarda.cx-2, guarda.cy-3);
                                    printf(" ");
                            }

                            //luz do ultimo feixe cetral
                            if(mapa[guarda.cx][guarda.cy-4]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                {
                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {
                                        if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                        {
                                            mgotoxy(guarda.cx,guarda.cy-4);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe inferior intermediario
                            if(mapa[guarda.cx-1][guarda.cy-4]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                {

                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {

                                        if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                        {

                                            mgotoxy(guarda.cx-1,guarda.cy-4);
                                            printf("%c",176);

                                        }

                                    }

                                }
                            }


                            // luz do ultimo feixe inferior
                            if(mapa[guarda.cx-2][guarda.cy-4]!= '#')
                            {
                                if(mapa[guarda.cx-1][guarda.cy-3]!= '#')
                                {


                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {
                                        if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                        {
                                            mgotoxy(guarda.cx-2,guarda.cy-4);
                                            printf("%c",176);
                                        }
                                    }

                                }
                            }
                            // luz do ultimo feixe superior intermediario
                            if(mapa[guarda.cx+1][guarda.cy-4]!= '#')
                            {
                                if(mapa[guarda.cx+1][guarda.cy-3]!= '#')
                                {

                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {

                                        if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                        {
                                            mgotoxy(guarda.cx+1,guarda.cy-4);
                                            printf("%c",176);
                                        }

                                    }


                                }
                            }
                            // luz do ultimo feixe superior
                            if(mapa[guarda.cx+2][guarda.cy-4]!= '#')
                            {
                                if(mapa[guarda.cx+1][guarda.cy-4]!= '#')
                                {

                                    if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                    {

                                        if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                        {

                                            if(mapa[guarda.cx][guarda.cy-1]!= '#')
                                            {
                                                mgotoxy(guarda.cx+2,guarda.cy-4);
                                                printf("%c",176);
                                            }

                                        }

                                    }


                                }
                            }




                          /*    for(i=0; i<5; i++)

                            {

                                if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                {

                                    mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                    printf(" ");
                                }

                            } */


                            if(j == 0)
                                j++;
                            break;

                        }
                        case 2:
                        {
                            if(prob_anterior != prob1)
                            {

                                switch(prob_anterior)
                                {

                                case 1:
                                {


                                    //apaga rastro do primeiro feixe unico  'w'
                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy-2);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-4);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy-4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy-4);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy-4);
                                        printf(" ");
                                    }

                                /*  for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;

                                }
                                case 3:
                                {

                                    //apaga rastro do primeiro feixe unico  'S'
                                    if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+2);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx-1, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                                    {

                                        mgotoxy(guarda.cx+1, guarda.cy+3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy+4);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx+1, guarda.cy+4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx-1, guarda.cy+4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx-2, guarda.cy+4);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy+4]!= '#')
                                    {

                                        mgotoxy(guarda.cx+2, guarda.cy+4);
                                        printf(" ");
                                    }

                                /*  for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;
                                }
                                case 0:
                                {
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy-1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy+1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy+1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy-1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+2]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-2]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy-2);
                                        printf(" ");
                                    }


                               /*     for(i=0; i<9; i++)
                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {


                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    } */
                                    break;
                                }

                                }

                            }


                            //    if(tecla_anterior != tecla1)
                            //  cria_mapa();

                            // movimenta o guarda para a direita
                            if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                guarda.cx++;

                            if(mapa[guarda.cx-1][guarda.cy]!= '#')
                            {
                                mgotoxy(guarda.cx-1,guarda.cy);
                                printf(" ");
                            }



                            SetConsoleTextAttribute(tela,14);

                            //primeiro feixe unico

                            if(mapa[guarda.cx+2][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx+1][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    mgotoxy(guarda.cx+2,guarda.cy);
                                    printf("%c",178);
                                }
                            }

                            //apaga rastro do primeiro feixe unico
                            if(mapa[guarda.cx+1][guarda.cy]!= '#')
                            {

                                 mgotoxy(guarda.cx+1, guarda.cy);
                                    printf(" ");
                            }



                            //segundo feixe (triplo)

                            //feixe central
                            if(mapa[guarda.cx+3][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx+2][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx+1][guarda.cy]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx+3,guarda.cy);
                                        printf("%c",177);
                                    }
                                }
                            }

                            //feixe inferior
                            if(mapa[guarda.cx+3][guarda.cy+1]!= '#')
                            {
                                if(mapa[guarda.cx+2][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx+1][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx+3,guarda.cy+1);
                                        printf("%c",177);
                                    }
                                }
                            }
                            //apaga rastro  feixe inferior
                            if(mapa[guarda.cx+2][guarda.cy+1]!= '#')
                            {
                                lanterna[prob3].rastro[1].cx = guarda.cx+2, lanterna[prob3].rastro[1].cy = guarda.cy+1;

                                 mgotoxy(guarda.cx+2, guarda.cy+1);
                                    printf(" ");
                            }
                            //feixe superior
                            if(mapa[guarda.cx+3][guarda.cy-1]!= '#')
                            {
                                if(mapa[guarda.cx+2][guarda.cy+1]!= '#')
                                {
                                    if(mapa[guarda.cx+2][guarda.cy-1]!= '#')
                                    {
                                        if(mapa[guarda.cx+1][guarda.cy-1]!= '#')
                                        {
                                            if(mapa[guarda.cx+1][guarda.cy+1]!= '#')
                                            {
                                                mgotoxy(guarda.cx+3,guarda.cy-1);
                                                printf("%c",177);
                                            }
                                        }
                                    }
                                }
                            }
                            //apaga rastro feixe superio
                            if(mapa[guarda.cx+2][guarda.cy-1]!= '#')
                            {


                                 mgotoxy(guarda.cx+2, guarda.cy-1);
                                    printf(" ");
                            }



                            //terceiro feixe quintuplo

                            //detecção no ultimo feixe central
                            if(guarda.cx+4 == cx && guarda.cy == cy)
                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe inferior intermediario
                            if(guarda.cx+4 == cx && guarda.cy-1 == cy)
                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }
                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe inferior
                            if(guarda.cx+4 == cx && guarda.cy-2 == cy)
                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe superior intermediario
                            if(guarda.cx-4 == cx && guarda.cy+1 == cy)
                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe superior
                            if( guarda.cx+4 == cx && guarda.cy+2 == cy)
                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }



                            //sistema de luzes do ultimo feixe
                            // apaga ultimo feixe inferior
                            if(mapa[guarda.cx+3][guarda.cy+2]!= '#')
                            {

                                 mgotoxy(guarda.cx+3, guarda.cy+2);
                                    printf(" ");
                            }

                            // apaga ultimo feixe inferior
                            if(mapa[guarda.cx+3][guarda.cy-2]!= '#')
                            {

                                 mgotoxy(guarda.cx+3, guarda.cy-2);
                                    printf(" ");
                            }

                            //luz do ultimo feixe cetral
                            if(mapa[guarda.cx+4][guarda.cy]!= '#')
                            {
                                if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                        {
                                            mgotoxy(guarda.cx+4,guarda.cy);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe inferior intermediario
                            if(mapa[guarda.cx+4][guarda.cy+1]!= '#')
                            {
                                if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                        {
                                            mgotoxy(guarda.cx+4,guarda.cy+1);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }

                            // luz do ultimo feixe inferior
                            if(mapa[guarda.cx+4][guarda.cy+2]!= '#')
                            {
                                if(mapa[guarda.cx+3][guarda.cy+1]!= '#')
                                {
                                    if(mapa[guarda.cx+2][guarda.cy+1]!= '#')
                                    {
                                        if(mapa[guarda.cx+1][guarda.cy+1]!= '#')
                                        {
                                            mgotoxy(guarda.cx+4,guarda.cy+2);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe superior intermediario
                            if(mapa[guarda.cx+4][guarda.cy-1]!= '#')
                            {
                                if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                {
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                        {
                                            if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                            {
                                                if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                                {
                                                    if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                                    {
                                                        mgotoxy(guarda.cx+4,guarda.cy-1);
                                                        printf("%c",176);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe superior
                            if(mapa[guarda.cx+4][guarda.cy-2]!= '#')
                            {
                                if(mapa[guarda.cx+4][guarda.cy-1]!= '#')
                                {
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {
                                        if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                        {
                                            if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                            {
                                                if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                                {
                                                    if(mapa[guarda.cx-1][guarda.cy]!= '#')
                                                    {
                                                        if(mapa[guarda.cx+1][guarda.cy]!= '#')
                                                        {
                                                            mgotoxy(guarda.cx+4,guarda.cy-2);
                                                            printf("%c",176);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }




                          /*     for(i=0; i<5; i++)
                            {


                                if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                {

                                    mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                    printf(" ");
                                }

                            } */


                            if(j == 0)
                                j++;

                            break;

                        }
                        case 3:
                        {
                            if(prob_anterior != prob1)
                            {
                                switch(prob_anterior)
                                {

                                case 1:
                                {


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx, guarda.cy-2);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-3]!= '#')
                                    {

                                        mgotoxy(guarda.cx-1, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-3]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-3);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx, guarda.cy-4);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+1, guarda.cy-4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-1][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-1, guarda.cy-4);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy-4);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy-4]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy-4);
                                        printf(" ");
                                    }

                              /*   for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    }*/
                                    break;
                                }
                                case 0:
                                {

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-2][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-2, guarda.cy);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy-1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-3][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-3, guarda.cy+1);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy);
                                        printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy+1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy-1);
                                        printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy+2]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx-4][guarda.cy-2]!= '#')
                                    {

                                         mgotoxy(guarda.cx-4, guarda.cy-2);
                                        printf(" ");
                                    }

                                  /*  for(i=0; i<9; i++)

                                    {
                                        if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                        {

                                            mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                            printf(" ");
                                        }
                                    }*/
                                    break;
                                }
                                case 2:
                                {
                                     //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+2][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+2, guarda.cy);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy-1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+3][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+3, guarda.cy+1);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy);
                                         printf(" ");
                                    }
                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy+1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-1]!= '#')
                                    {

                                         mgotoxy(guarda.cx+4, guarda.cy-1);
                                         printf(" ");
                                    }

                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy+2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy+2);
                                        printf(" ");
                                    }


                                    //apaga rastro do primeiro feixe unico
                                    if(mapa[guarda.cx+4][guarda.cy-2]!= '#')
                                    {

                                        mgotoxy(guarda.cx+4, guarda.cy-2);
                                        printf(" ");
                                    }
                                    break;
                                }

                                }
                            }


                            // movimenta o guarda para baixo
                            if(mapa[guarda.cx][guarda.cy+1]!= '#')
                                guarda.cy++;

                            if(mapa[guarda.cx][guarda.cy-1]!= '#')
                            {
                                mgotoxy(guarda.cx,guarda.cy-1);
                                printf(" ");
                            }



                            SetConsoleTextAttribute(tela,14);

                            //primeiro feixe unico

                            if(mapa[guarda.cx][guarda.cy+2]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    mgotoxy(guarda.cx,guarda.cy+2);
                                    printf("%c",178);
                                }
                            }

                            //apaga rastro do primeiro feixe unico
                            if(mapa[guarda.cx][guarda.cy+1]!= '#')
                            {

                                 mgotoxy(guarda.cx, guarda.cy+1);
                                    printf(" ");
                            }



                            //segundo feixe (triplo)

                            //feixe central
                            if(mapa[guarda.cx][guarda.cy+3]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy+2]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx,guarda.cy+3);
                                        printf("%c",177);
                                    }
                                }
                            }

                            //feixe inferior
                            if(mapa[guarda.cx-1][guarda.cy+3]!= '#')
                            {
                                if(mapa[guarda.cx-1][guarda.cy+2]!= '#')//detecção das paredes para coibir o efeito da luz
                                {
                                    if(mapa[guarda.cx-1][guarda.cy+1]!= '#')//detecção das paredes para coibir o efeito da luz
                                    {
                                        mgotoxy(guarda.cx-1,guarda.cy+3);
                                        printf("%c",177);
                                    }
                                }
                            }
                            //apaga rastro  feixe inferior
                            if(mapa[guarda.cx+1][guarda.cy+2]!= '#')
                            {

                                 mgotoxy(guarda.cx+1, guarda.cy+2);
                                    printf(" ");
                            }
                            //feixe superior
                            if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                            {
                                if(mapa[guarda.cx+1][guarda.cy+2]!= '#')
                                {
                                    if(mapa[guarda.cx+1][guarda.cy+1]!= '#')
                                    {
                                        mgotoxy(guarda.cx+1,guarda.cy+3);
                                        printf("%c",177);
                                    }


                                }
                            }
                            //apaga rastro feixe superio
                            if(mapa[guarda.cx-1][guarda.cy+2]!= '#')
                            {

                                 mgotoxy(guarda.cx-1, guarda.cy+2);
                                    printf(" ");
                            }



                            //terceiro feixe quintuplo

                            //detecção no ultimo feixe central
                            if(cx == guarda.cx && guarda.cy+4 == guarda.cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe inferior intermediario
                            if(guarda.cx+1 == cx && guarda.cy-4== cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }
                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe inferior
                            if(guarda.cx-4 == cx && guarda.cy-2 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }
                            //detecção no ultimo feixe superior intermediario
                            if(guarda.cx-1 == cx && guarda.cy-4 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }

                            //detecção no ultimo feixe superior
                            if( guarda.cx-4 == cx && guarda.cy-2 == cy)

                            {
                                mgotoxy(7,7);
                                vida -= 1;
                                tecla1 = 'y';
                                *resultado = 'l';
                            }

                            else
                            {
                                mgotoxy(7,7);
                                printf("%d",vida);
                            }



                            //sistema de luzes do ultimo feixe

                            // apaga ultimo feixe superior
                            if(mapa[guarda.cx+2][guarda.cy+3]!= '#')
                            {

                                mgotoxy(guarda.cx+2, guarda.cy+3);
                                    printf(" ");
                            }

                            // apaga ultimo feixe inferior
                            if(mapa[guarda.cx-2][guarda.cy+3]!= '#')
                            {

                                mgotoxy(guarda.cx-2, guarda.cy+3);
                                    printf(" ");
                            }

                            //luz do ultimo feixe cetral
                            if(mapa[guarda.cx][guarda.cy+4]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy+3]!= '#')
                                {
                                    if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                    {
                                        if(mapa[guarda.cx][guarda.cy+1]!= '#')
                                        {
                                            mgotoxy(guarda.cx,guarda.cy+4);
                                            printf("%c",176);
                                        }
                                    }
                                }
                            }


                            // luz do ultimo feixe inferior intermediario
                            if(mapa[guarda.cx-1][guarda.cy+4]!= '#')
                            {
                                if(mapa[guarda.cx][guarda.cy+3]!= '#')
                                {

                                    if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                    {

                                        if(mapa[guarda.cx][guarda.cy+1]!= '#')
                                        {

                                            mgotoxy(guarda.cx-1,guarda.cy+4);
                                            printf("%c",176);

                                        }

                                    }

                                }
                            }


                            // luz do ultimo feixe inferior
                            if(mapa[guarda.cx-2][guarda.cy+4]!= '#')
                            {

                                if(mapa[guarda.cx-1][guarda.cy+4]!= '#')
                                {
                                    if(mapa[guarda.cx-1][guarda.cy+3]!= '#')
                                    {
                                        if(mapa[guarda.cx][guarda.cy+2]!= '#')
                                        {
                                            if(mapa[guarda.cx][guarda.cy+1]!= '#')
                                            {
                                                mgotoxy(guarda.cx-2,guarda.cy+4);
                                                printf("%c",176);
                                            }
                                        }
                                    }
                                }
                            }
                            // luz do ultimo feixe superior intermediario
                            if(mapa[guarda.cx+1][guarda.cy+4]!= '#')
                            {
                                if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                                {


                                    if(mapa[guarda.cx+1][guarda.cy+2]!= '#')
                                    {

                                        if(mapa[guarda.cx+1][guarda.cy+1]!= '#')
                                        {
                                            mgotoxy(guarda.cx+1,guarda.cy+4);
                                            printf("%c",176);
                                        }

                                    }


                                }
                            }

                            // luz do ultimo feixe superior
                            if(mapa[guarda.cx+2][guarda.cy+4]!= '#')
                            {

                                if(mapa[guarda.cx+1][guarda.cy+4]!= '#')
                                {
                                    if(mapa[guarda.cx+1][guarda.cy+3]!= '#')
                                    {
                                        if(mapa[guarda.cx+2][guarda.cy+2]!= '#')
                                        {
                                            if(mapa[guarda.cx+1][guarda.cy+1]!= '#')
                                            {
                                                mgotoxy(guarda.cx+2,guarda.cy+4);
                                                printf("%c",176);
                                            }
                                        }
                                    }
                                }
                            }

                         /*   for(i=0; i<5; i++)

                            {

                                if(mapa[lanterna[prob3].rastro[i].cx][lanterna[prob3].rastro[i].cy] != '#')
                                {

                                    mgotoxy(lanterna[prob3].rastro[i].cx, lanterna[prob3].rastro[i].cy);
                                    printf(" ");
                                }
                            }  */

                            if(j == 0)
                                j++;


                            break;
                        }

                   }

                    prob_anterior =  prob1;
                    SetConsoleTextAttribute(tela,12);
                    {
                        mgotoxy(guarda.cx,guarda.cy);
                        printf("%c",219);
                    }

                    i++;
                    x=1;
                    Sleep(60); //fica realmente emocionante com o sleep em 10

                    timer = timer - 1;

                    mgotoxy(2,23);
                    {
                        printf("%f",timer);
                        mgotoxy(2,24);
                        printf("%d",x);
                    }



                 if(timer == 0)
                    {
                       // cria_mapa();
                        timer=80;
                        x=1;
                        Sleep(x); //fica realmente emocionante com o sleep em 10
                        mgotoxy(2,24);
                        printf("%d",x);
                    }
                }

                // salva a posicao de cada guarda pra criar a ilusao de movimento

                if(prob3 == 0 )
                {
                    posicaoatualx_00 = guarda.cx, posicaoatualy_00 = guarda.cy ;
                    lanterna_atualx_00 = lanterna[0].cx, lanterna_atualy_00 = lanterna[0].cy;
                    dir_00 = prob_anterior;

                }
                if(prob3 == 1 )
                {
                    posicaoatualx_01 = guarda.cx, posicaoatualy_01 = guarda.cy ;
                    lanterna_atualx_01 = lanterna[1].cx, lanterna_atualy_01 = lanterna[1].cy;
                    dir_01 = prob_anterior;
                }
                if(prob3 == 2 )
                {
                    posicaoatualx_02 = guarda.cx,  posicaoatualy_02 = guarda.cy;
                    lanterna_atualx_02 = lanterna[2].cx, lanterna_atualy_02 = lanterna[2].cy;
                    dir_02 = prob_anterior;
                }
                if(prob3 == 3 )
                {
                    posicaoatualx_03 = guarda.cx,  posicaoatualy_03 = guarda.cy;
                    lanterna_atualx_03 = lanterna[3].cx,  lanterna_atualy_03 = lanterna[3].cy;
                    dir_03 = prob_anterior;
                }
                if(prob3 == 4 )
                {
                    posicaoatualx_04 = guarda.cx,  posicaoatualy_04 = guarda.cy;
                    lanterna_atualx_04 = lanterna[4].cx, lanterna_atualy_04 = lanterna[4].cy;
                    dir_04 = prob_anterior;

                }
                if(prob3 == 5 )
                {
                    posicaoatualx_05 = guarda.cx,  posicaoatualy_05 = guarda.cy;
                    lanterna_atualx_05 = lanterna[5].cx, lanterna_atualy_05 = lanterna[5].cy ;
                    dir_05 = prob_anterior;


                }
                if(prob3 == 6 )
                {
                    posicaoatualx_06 = guarda.cx,  posicaoatualy_06 = guarda.cy;
                    lanterna_atualx_06 = lanterna[6].cx, lanterna_atualy_06 = lanterna[6].cy;
                    dir_06 = prob_anterior;


                }
                if(prob3 == 7 )
                {
                    posicaoatualx_07 = guarda.cx, posicaoatualy_07 = guarda.cy;
                    lanterna_atualx_07 = lanterna[7].cx,  lanterna_atualy_07 = lanterna[7].cy ;
                    dir_07 = prob_anterior;


                }



                // associa cada tecla a uma direcao



            }
            // faz o protagonista real andar naquela direcao se nao houver parede

            switch(tecla1)
            {

            case 'a':
            {
                if(mapa[cx-1][cy]!= '#')
                    cx--;
                // apaga o rastro do protagonista

                if( key.cx == cx, key.cy == cy)
                {
                    mapa[0][5] = 'x';
                    mgotoxy(key.cx,key.cy);
                }
                // sai do jogo, com vitoria
                if(cx == 0 && cy == 5)
                {

                    tecla1 = 'y';
                    *resultado = 'g';

                }

                mgotoxy(cx+1,cy);
                printf(" ");
                // faz ele ficar parado (usar nos inimigos pra fazer eles dormirem com o dardo)
                  break;
            }

            case 'w':
            {

                if(mapa[cx][cy-1]!= '#')
                    cy--;

                if( key.cx == cx, key.cy == cy)
                {
                    mapa[0][5] = 'x';
                    mgotoxy(key.cx,key.cy);
                }

                // sai do jogo, com vitoria
                if(cx == 0 && cy == 5)
                {

                    tecla1 = 'y';
                    *resultado = 'g';

                }


                mgotoxy(cx,cy+1);
                printf(" ");


                break;

            }
            case 'd':
            {
                if(mapa[cx+1][cy]!= '#')
                    cx++;

                if( key.cx == cx, key.cy == cy)
                {
                    mapa[0][5] = 'x';
                    mgotoxy(key.cx,key.cy);
                }
                // sai do jogo, com vitoria
                if(cx == 0 && cy == 5)
                {

                    tecla1 = 'y';
                    *resultado = 'g';

                }


                mgotoxy(cx-1,cy);
                printf(" ");

                break;

            }
            case 's':
            {
                if(mapa[cx][cy+1]!= '#')
                    cy++;

                if( key.cx == cx, key.cy == cy)
                {
                    mapa[0][5] = 'x';
                    mgotoxy(key.cx,key.cy);
                }

                // sai do jogo, com vitoria
                if(cx == 0 && cy == 5)
                {

                    tecla1 = 'y';
                    *resultado = 'g';

                }


                mgotoxy(cx,cy-1);
                printf(" ");


                break;
            }

            }



            // pinta o protagonista de branco e atualiza sua represntacao grafica no seu atual local
            SetConsoleTextAttribute(tela,15);
            mgotoxy(cx,cy);


            printf("%c",219);
            Sleep(80);

        }


    }
}
