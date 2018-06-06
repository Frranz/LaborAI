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
   int treasurex;
   int treasurey;
}LabCell, *Lab_p;