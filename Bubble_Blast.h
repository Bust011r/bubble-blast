#ifndef BUBBLE_BLAST_BUBBLE_BLAST_H
#define BUBBLE_BLAST_BUBBLE_BLAST_H

#define ROW 5
#define COL 6

enum GameStates{
        lost = -1,
        playing,
        win
};

enum BubbleStates {
        exploded,
        normal,
        halfToExplode,
        toExplode
};

void copyMatrix(int computerGameField[ROW][COL], int gameField [ROW][COL]);
int changeState(int moveX, int moveY, int  gameField[ROW][COL]);

int randomBubbleState();

void addSingleLine();

void addDoubleLine();

char getCharForBubbleState(int bubbleState);

void generateFieldGame(int gameField[ROW][COL]);

void printFieldGame(int  gameField[ROW][COL]);

int selectRow(int  * moveX);

int selectColumn(int *  moveY);

void explosion(int moveX, int moveY, int gameField [ROW][COL]);

int selectXY(int  moveX, int  moveY, int gameField[ROW][COL]);
void shiftRight(int moveX, int moveY, int gameField[ROW][COL]);
void shiftLeft(int moveX, int moveY, int gameField[ROW][COL]);
void shiftUp(int moveX, int moveY, int gameField[ROW][COL]);
void shiftDown(int moveX, int moveY, int gameField[ROW][COL]);

#endif //BUBBLE_BLAST_BUBBLE_BLAST_H
