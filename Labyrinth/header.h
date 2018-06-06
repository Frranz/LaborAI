#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLS  256
#define MAXROWS  256

typedef struct labyrinth
{
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


void printLab(LabCell lab);
void solveLab(Lab_p lab);
void myNaive(Lab_p lab);
void moveRight(int* row,int* col);
void moveLeft(int* row,int* col);
void moveDown(int* row,int* col);
void moveUp(int* row,int* col);
