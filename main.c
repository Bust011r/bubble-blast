#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Bubble_Blast.h"


void clear_stream(FILE *in)
{
    int ch;
    clearerr(in);
    do
        ch = getc(in);
    while (ch != '\n' && ch != EOF);
    clearerr(in);
}

int scanNumber()
{
    int value;
    fflush(stdout);
    while (scanf("%d", &value) != 1) {
        clear_stream(stdin);
        printf("Invalid integer. Please try again: ");
        fflush(stdout);
    }
    return value;
}

int randomBubbleState(){
    return rand()% 4;

}
void addSingleLine(){
    printf("\n");

}
void addDoubleLine(){
    printf("\n\n");
}

char getCharForBubbleState(int bubbleState) {
    switch (bubbleState) {
        case normal: return 'O';
        case halfToExplode: return '0';
        case toExplode: return 'X';
        case exploded: return ' ';
    }
}


void generateFieldGame(int gameField[ROW][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL ; ++j) {
            gameField[i][j] = randomBubbleState();
        }
    }
}
void printFieldGame(int  gameField[ROW][COL]) {
    for (int i = 0; i < ROW; ++i) {
        addSingleLine();
        for (int j = 0; j < COL ; ++j) {
            printf("%c  ", getCharForBubbleState(gameField[i][j]));
        }
    }
    addDoubleLine();
}


int selectRow(int  * moveX)
{
    int tempX = *moveX;

    printf("Select a row \n");
    tempX = scanNumber();
    if (tempX < 1 || tempX > ROW) {
        printf("Error!! Row not correct, choose a correct row");
        addSingleLine();
        selectRow(moveX);
    }
    else {
        tempX --;
}
    *moveX = tempX;
}

int selectColumn(int *  moveY){
    int tempY = *moveY;
    printf("Select a Column \n");
    tempY = scanNumber();
    if (tempY < 1 || tempY> COL) {
        printf("Error!! Column not correct, choose a correct column");
        addSingleLine();
        selectColumn(moveY);
    }
    else{
        tempY --;
    }
    *moveY = tempY;
}

int selectXY(int  moveX, int  moveY, int gameField[ROW][COL]){
    selectRow(&moveX);
    selectColumn(&moveY);
    changeState(moveX,moveY,gameField);

};
int changeState(int moveX, int moveY, int  gameField[ROW][COL]) {
    if (gameField[moveX][moveY] == exploded) {
        printf("Not possible choose just exploded Bubble, try again\n");
        selectXY(moveX,moveY,gameField);

    } else {
        if (gameField[moveX][moveY] == normal || gameField[moveX][moveY] == halfToExplode) {
            gameField[moveX][moveY]++;
        } else if (gameField[moveX][moveY] == toExplode) {
            gameField[moveX][moveY] = 0;
            explosion(moveX,moveY,gameField);
        }
    }
}

int endGame(int gameField[ROW][COL])
{
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (gameField[r][c] != exploded)
            {
                return playing;
            }
        }
    }

    return win;
}

void shiftRight(int moveX, int moveY, int gameField[ROW][COL]) {
    bool end = false;
    if (moveY < COL) {
        moveY++;
        do {
            if(gameField[moveX][moveY] != 0){
                end=true;
              if (gameField[moveX][moveY] == normal || gameField[moveX][moveY] == halfToExplode) {
                gameField[moveX][moveY]++;
            } else if (gameField[moveX][moveY] == toExplode) {
                  gameField[moveX][moveY] = 0;
                  explosion(moveX,moveY,gameField);

              }}
            else{
            moveY ++;
            if(moveY == COL){
                end=true;
            }
            }
        }
    while (end != true);
    }
}
void shiftLeft(int moveX, int moveY, int gameField[ROW][COL]) {
    bool end = false;
    if (moveY > 0) {
        moveY--;
        do {
            if(gameField[moveX][moveY] != 0){
                end=true;
                if (gameField[moveX][moveY] == normal || gameField[moveX][moveY] == halfToExplode) {
                    gameField[moveX][moveY]++;
                } else if (gameField[moveX][moveY] == toExplode) {
                    gameField[moveX][moveY] = 0;
                    explosion(moveX,moveY,gameField);

                }}
            else{
                moveY --;
                if(moveY == 0){
                    end=true;
                }
            }
        }
        while (end != true);
    }
}

void shiftUp(int moveX, int moveY, int gameField[ROW][COL]) {
    bool end = false;
    if (moveX > 0 ) {
        moveX--;
        do {
            if(gameField[moveX][moveY] != 0){
                end=true;
                if (gameField[moveX][moveY] == normal || gameField[moveX][moveY] == halfToExplode) {
                    gameField[moveX][moveY]++;
                } else if (gameField[moveX][moveY] == toExplode) {
                    gameField[moveX][moveY] = 0;
                    explosion(moveX,moveY,gameField);

                }}
            else{
                moveX --;
                if(moveX == 1){
                    end=true;
                }
            }
        }
        while (end != true);
    }
}

void shiftDown(int moveX, int moveY, int gameField[ROW][COL]) {
    bool end = false;
    if (moveX < ROW ) {
        moveX++;
        do {
            if(gameField[moveX][moveY] != 0){
                end=true;
                if (gameField[moveX][moveY] == normal || gameField[moveX][moveY] == halfToExplode) {
                    gameField[moveX][moveY]++;
                } else if (gameField[moveX][moveY] == toExplode) {
                    gameField[moveX][moveY] = 0;
                    explosion(moveX,moveY,gameField);
                }}
            else{
                moveX ++;
                if(moveX == ROW){
                    end=true;
                }
            }
        }
        while (end != true);
    }
}

void explosion(int moveX, int moveY, int gameField [ROW][COL]){
    shiftLeft(moveX,moveY,gameField);
    shiftRight(moveX,moveY,gameField);
    shiftDown(moveX,moveY,gameField);
    shiftUp(moveX,moveY,gameField);

}

void copyMatrix(int computerGameField[ROW][COL], int gameField [ROW][COL]) {
    memcpy(computerGameField, gameField, ROW * COL * sizeof(int));
}


int calculateComputerMove(int computerGameField [ROW][COL]) {

    int countMoveMachine = 0;
    bool conditionToContinue;
    do {
        conditionToContinue = true;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; ++j) {
                if (computerGameField[i][j] == normal || computerGameField[i][j] == halfToExplode) {
                    computerGameField[i][j]++;
                    conditionToContinue = false;
                    countMoveMachine++;
                } else if (computerGameField[i][j] == toExplode) {
                    computerGameField[i][j] = 0;
                    explosion(i,j, computerGameField);
                    conditionToContinue = false;
                    countMoveMachine++;
                }
            }
        }
    } while (conditionToContinue == false);
    return countMoveMachine;
}




int main() {
    srand(time(0));
    int gameField[ROW][COL];
    int computerGameField[ROW][COL];
    int moveX;
    int moveY;
    int status = 0;
    int numMoves = 0;
    generateFieldGame(gameField);
    copyMatrix(computerGameField,gameField);
    int minMoves =  calculateComputerMove(computerGameField);

    while (status == 0) {
        printf("You have %d moves", minMoves - numMoves);
        printFieldGame(gameField);
        selectXY(moveX, moveY, gameField);
        numMoves++;
        status = endGame(gameField);
        if (status == 0 && numMoves >= minMoves)
        {
            status = lost;
        }
    }
    printf("\n%s\n", (status == 1 ? "You Win!" : "You Lose"));
    printf("Number of moves: %d", numMoves);

    return 0;

            }





