#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

void moveRacket(int x)
{
    racket.x = x;
    if (racket.x < 1)
        racket.x = 1;
    if (racket.x + racket.w >= width)
        racket.x = width - 1 - racket.w;
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
        if (i < height - 1)
            printf("\n");
}

int main()
{
    char c;
    initRacket();

    do {
        init();
        putRacket();
        show();
        c = getch();

        if (c == 'a') moveRacket(racket.x - 1);
        if (c == 'd') moveRacket(racket.x + 1);
    }
    while (c != 'q');

    return 0;
}



