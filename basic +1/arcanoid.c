#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define width 65
#define heigth 25

typedef struct {
    int x, y;
    int w;
} TRacket;

char mas[heigth][width+1];
TRacket racket;

void initRacket()
{
    racket.w = 7;
    racket.x = (width + racket.w) / 2;
    racket.y = heigth - 1;
}

void putRacket()
{
    for (int i = racket.x; i<racket.x + racket.w; i++)
        mas[racket.y][i] = '@';
}

void init() 
{
    for (int i = 0; i < width+1; i++)
        mas[0][i] = '#';
        mas[0][width] = '\0';

    strncpy(mas[1], mas[0], width+1);
    for(int i = 1; i < width-1; i++)
        mas[1][i] = ' ';


    for (int i = 2; i < heigth; i++)
        strncpy(mas[i], mas[1], width+1);
}

void show() 
{
    for (int i=0; i<heigth; i++)
        printf("%s\n", mas[i]);
}

int main()
{
    initRacket();

    init();

    show();

    return 0;
}



