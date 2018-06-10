#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLS  256
#define MAXROWS  256

typedef struct labyrinth{
   char lab[MAXCOLS+2][MAXROWS];
   long costs[MAXCOLS][MAXROWS];
   long bestx[MAXCOLS][MAXROWS];
   long besty[MAXCOLS][MAXROWS];
   int maxrow;
   int startx;
   int starty;
   int endx;
   int endy;
}LabCell, *Lab_p;


void solveLab(Lab_p lab);
void myNaive(Lab_p lab);
void myNaive2(Lab_p lab);
void turnRight(int dir[]);
void turnLeft(int dir[]);
char checkRight(char lab[][MAXROWS],int row,int col,int dirX,int dirY);
void printLab(char lab[][MAXROWS],int maxRow);
void moveRight(int* row,int* col);
void moveLeft(int* row,int* col);
void moveDown(int* row,int* col);
void moveUp(int* row,int* col);
int twoOrMoreAround(char lab[][MAXROWS],int row,int col, char findTwoOfMe);
int canBlock(char lab[][MAXROWS],int row,int col);

