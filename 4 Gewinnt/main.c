#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {	
	int runLoop = 1;
	int input;
	
				BoardCell board;
	
	while(runLoop){
		printf("Welcome at CONNECTED 4\n");
		printf("=========================\n");
		printf("please select one of the following options:\n");
		printf("[1] play vs another player\n");
		printf("[2] play vs bot\n");
		printf("[3] exit game\n");
		printf("[4] Test\n");
		scanf("%1d",&input);
		fflush(stdin);
		
		switch(input){
			case 1:
				playerVsPlayer();
				break;
			case 2:
				break;
			case 3:
				runLoop = 0;
				printf("exiting program\n");
				break;
			case 4:
				initBoard(&board);
				printBoard(board);
				break;
			default:
				printf("invalid input\n");
		}
		
		
	}
	
	getch();
	
	return 0;
}

void playerVsPlayer(){
	int runLoop = 1;
	while(runLoop){
	}
}

void initBoard(Board_p board){
	int i = 0;
	int j = 0;
	
	while(i<ROWS){
		j = 0;
		while(j<COLS){
			board->board[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void printBoard(BoardCell board){
	printf("Heres the board\n");
	int i = 0;
	int j = 0;
	
	while(i<ROWS){
		j = 0;
		while(j<COLS){
			printf("|%c",board.board[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
}

int colIsPlayable(char* board, int col){
	if(board[0][col]==' '){
		return 1;
	}
	return 0;
}

int getDropPosition(char *board,int col){
	int i = 0;
	
	if(colIsPlayable(board,col)){
		while(board[i][col]!=' '){
			i++;
		}
		return i;
	}
	return -1;
}
