#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "cursor.h"

/*
 * Defines keys int codes
*/
#define UP_ARROW        72
#define DOWN_ARROW      80
#define LEFT_ARROW      75
#define RIGHT_ARROW     77
#define ENTER           13
#define ESC             27
#define SPACE           32

#define WIDTH_STR "60"
#define HEIGTH_STR "33"

#define WIDTH 60
#define HEIGTH 30

void gameMenu();
void init();
void start();
void run();
void update();
void render();

int isRunning = 1;
int tailX[(WIDTH-2)], tailY[(HEIGTH-2)];
int score = 0;
int snakeX = 10, snakeY = 10;
int fruitX, fruitY;

int timeSleep;

enum direction {
    STOP = 0,
    UP_DIR, 
    DOWN_DIR, 
    LEFT_DIR, 
    RIGHT_DIR
};
enum direction dir = RIGHT_DIR;


int main(int argc, char const *argv[]) {
    start();

    return 0;
}

void update(){
    srand(time(NULL));

    //Keys pressed
        //Direction define
    if(_kbhit()){
        int getChar = _getch();
        if(getChar == UP_ARROW){
            dir = UP_DIR;
            timeSleep = 64;
        } else if (getChar == DOWN_ARROW) {
            dir = DOWN_DIR;
            timeSleep = 64;
        }
        if(getChar == LEFT_ARROW){
            dir = LEFT_DIR;
            timeSleep = 48;
        } else if(getChar == RIGHT_ARROW){
            dir = RIGHT_DIR;
            timeSleep = 48;
        }
    }
    
    //Fruit position
    if(snakeX == fruitX && snakeY == fruitY){
        score++;
        fruitX = rand()%WIDTH-2 + 1;
        fruitY = rand()%HEIGTH-2 + 1;
    }

    //Snake position
    switch (dir) {
    case UP_DIR:
        snakeY--;
        break;
    case DOWN_DIR:
        snakeY++;
        break;
    case LEFT_DIR:
        snakeX--;
        break;
    case RIGHT_DIR:
        snakeX++;
        break;
    }

    //Tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int tempX, tempY;
    tailX[0] = snakeX; 
    tailY[0] = snakeY;
    for (int i = 1; i < score; i++) {
        tempX = tailX[i];
        tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

}

void render(){
    CLEAR;
    printf(INVISIBLE_CURSOR);
    //Walls

    //Snake
    POSC(snakeX, snakeY);
    printf("@");
    //Tails
    for(int t = 1; t < score; t++){
        POSC(tailX[t], tailY[t]);
        printf("O");
    }
    //
    POSC(fruitX, fruitY);
    printf("&");

    //Score
    POSC(2, HEIGTH-1);
    printf("Score: %d", score);
}



void init(){
    system("mode "WIDTH_STR" "HEIGTH_STR);
    system("title Snake Game");
    printf(INVISIBLE_CURSOR);
    CLEAR;
    fruitX = rand()%WIDTH-2 + 1;
    fruitY = rand()%HEIGTH-2 + 1;
}

void start(){
    init();
    run();
}

void run(){
    while(isRunning) {
        update();
        render();
        
        Sleep(timeSleep);
    }
}


















    