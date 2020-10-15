#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define LARGURA 77
#define ALTURA 22

char mapa[LARGURA][ALTURA];

char cria_loopgame();
void movimentacao(char* resultado);
void cria_mapa();
int mgotoxy(int x,int y);
char menu(char *n);



//struct que possui as coordenadas e a direcao do inimigo
typedef struct luz
{

    int cx,cy;


} LUZ;
typedef struct lanterna
{
    int cx,cy;

    LUZ rastro[9];

} LANT;
typedef struct chave
{

    int cx,cy;


} CHAVE;
typedef struct ini
{
    int cx,cy,dir;
} INIMIGO;
