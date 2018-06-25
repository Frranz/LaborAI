#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

typedef struct m_game{
	char board[ROWS][COLS];
	char whosTurn;
}BoardCell,*Board_p;

void playerVsPlayer();
void printBoard(BoardCell board);
void initBoard(Board_p board);
int colIsPlayable(char* board, int col);
int getDropPosition(char *board,int col);
