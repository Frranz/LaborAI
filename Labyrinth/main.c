#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	LabCell lab;
	char stdFileName[35+1];
	strcpy(stdFileName,"labhuge1.txt");
	
	int colCount;
	int rowCount = 0;
	FILE* in = stdin;
	char readBuffer[MAXCOLS];
	if(argc >= 2){
		in = fopen(argv[1],"r");
		if(!in){
			printf("file error\n");
			getch();
			perror(argv[0]);
			return 0;
		}
	}else{
		in = fopen(stdFileName,"r");
	}
	
	
	fgets(readBuffer,MAXCOLS,in);
	while(!feof(in)){
		rowCount++;
		printf("%s",readBuffer);
		colCount = 0;
		while(readBuffer[colCount]!=0 && readBuffer[colCount]!='\n'){
			lab.lab[rowCount][colCount] = readBuffer[colCount];
			if(readBuffer[colCount]=='S'){
				lab.startx = colCount;
				lab.starty = rowCount;
			}
			if(readBuffer[colCount]=='X'){
				lab.endx = colCount;
				lab.endy = rowCount;
			}
			colCount++;
		}
		fgets(readBuffer,MAXCOLS,in);
	}
	
	lab.maxrow = rowCount-1;
	printLab(lab.lab,lab.maxrow);
	printf("nach print - addr=%p\n",&lab);
	myNaive2(&lab);
	printf("nach naive\n");
	getch();
	return 0;
}

void solveLab(Lab_p lab){
	printf("test");
	myNaive2(lab);
}

void myNaive2(Lab_p lab){
	int steps = 0;
	int loopRuns = 0;
	int turns = 0;
	int row = lab->starty;
	int col = lab->startx;
	int dir[] = {1,0};
	while(lab->lab[row][col]!='X'){
		lab->lab[row][col] = '.';
		if(checkRight(lab->lab,row,col,dir[0],dir[1])==' ' || checkRight(lab->lab,row,col,dir[0],dir[1])=='X'|| checkRight(lab->lab,row,col,dir[0],dir[1])=='.'){   //check right
			turnRight(&dir);
			row = row + dir[1];
			col = col + dir[0];
			turns++;
			steps++;
		}else if(lab->lab[row+dir[1]][col+dir[0]] == ' ' || lab->lab[row+dir[1]][col+dir[0]] == 'X' || lab->lab[row+dir[1]][col+dir[0]] == '.'){ 		//check front
			row = row + dir[1];
			col = col + dir[0];
			steps++;
		}else{
			turnLeft(&dir);
		}
		printLab(lab->lab,lab->maxrow);
		printf("row: %d, col: %d\n",row,col);
		printf("direction: [%d,%d]\n",dir[0],dir[1]);
		printf("end of loop\n");
		loopRuns++;
	}
	printf("steps: %d\n",steps);
	printf("loopRuns: %d\n",loopRuns);
	printf("turns: %d\n",turns);
	
}

void turnLeft(int dir[]){
//	printf("turnRoight: before: %d,%d\n",dir[0],dir[1]);
	int buff;
	buff = dir[0];
	dir[0] = dir[1];
	dir[1] = buff * (-1);
//	printf("turnRoight: after: %d,%d\n",dir[0],dir[1]);
}
void turnRight(int dir[]){
//	printf("turnLeft: before: %d,%d\n",dir[0],dir[1]);
	int buff;
	buff = dir[1];
	dir[1] = dir[0];
	dir[0] = buff * (-1);
//	printf("turnLeft: after: %d,%d\n",dir[0],dir[1]);
}

char checkRight(char lab[][MAXROWS],int row,int col,int dirX,int dirY){
	int dir[] ={dirX,dirY};
	turnRight(&dir);
	return lab[row+dir[1]][col+dir[0]];
}
void myNaive(Lab_p lab){
	printf("hi addr=%p\n",lab);
	int row = lab->starty;
	int col = lab->startx;
	while(lab->lab[row][col]!='X'){
		printf("hi test");
//		printLab(*lab);
		if(lab->lab[row][col+1] == ' ' || lab->lab[row][col+1] == 'X' ){ //check right
			lab->lab[row][col] = '.';
			col++;
		}else if(lab->lab[row+1][col] == ' ' || lab->lab[row+1][col] == 'X' ){ //check down
			lab->lab[row][col] = '.';
			row++;
		}else if(lab->lab[row][col-1] == ' ' || lab->lab[row][col-1] == 'X' ){ //check left
			lab->lab[row][col] = '.';
			col--;
		}else if(lab->lab[row-1][col] == ' ' || lab->lab[row-1][col] == 'X' ){ //check up
			lab->lab[row][col] = '.';
			row--;
		}else if(lab->lab[row][col] == ' '){	//no spaces to explore --> return;
			printf("no spaces around, lets go back\n");
			lab->lab[row][col] = '.';
		}else if(lab->lab[row][col+1] == '.'){ 	//check right
			if(canBlock(lab->lab,row,col)){
				lab->lab[row][col] = '!';
			}
			col++;
		}else if(lab->lab[row+1][col] == '.'){ 	//check down
			if(canBlock(lab->lab,row,col)){
				lab->lab[row][col] = '!';
			}
			row++;
		}else if(lab->lab[row][col-1] == '.'){ 	//check left
			if(canBlock(lab->lab,row,col)){
				lab->lab[row][col] = '!';
			}
			col--;
		}else if(lab->lab[row-1][col] == '.'){ 	//check up
			if(canBlock(lab->lab,row,col)){
				lab->lab[row][col] = '!';
			}
			row--;
		}
		printLab(lab->lab,lab->maxrow);
		printf("row: %d, col: %d\n",row,col);
		printf("end of loop\n");
	}
}

int twoOrMoreAround(char lab[][MAXROWS],int row,int col, char findTwoOfMe){
	int counter = 0;
	if(lab[row+1][col]==findTwoOfMe){ 		//check if full sackgasse
		counter++;
	}
	if(lab[row-1][col]==findTwoOfMe){
		counter++;
	}
	if(lab[row][col+1]==findTwoOfMe){
		counter++;
	}
	if(lab[row][col-1]==findTwoOfMe){
		counter++;
	}
	
	if(counter>1){
		return 1;
	}
	return 0;   							//end
}

int canBlock(char lab[][MAXROWS],int row,int col){
	int counter = 0;
	if(lab[row][col+1]=='.'){
		counter++;
	}
	if(lab[row][col-1]=='.'){
		counter++;
	}
	if(lab[row+1][col]=='.'){
		counter++;
	}
	if(lab[row-1][col]=='.'){
		counter++;
	}
	
	if(counter<2){
		return 1;
	}
	
	//check if go around possible	
	if(lab[row][col+1]=='.' && lab[row+1][col]=='.' && lab[row+1][col+1] == '.'){ //bottom to up right avail go around
		return 1;
	}else if(lab[row][col+1]=='.' && lab[row-1][col]=='.' && lab[row-1][col+1] == '.'){ //up right corner avail go around
		return 1;
	}else if(lab[row][col-1]=='.' && lab[row-1][col]=='.' && lab[row-1][col-1] == '.'){ //up left corner avail go around
		return 1;
	}else if(lab[row][col-1]=='.' && lab[row+1][col]=='.' && lab[row+1][col-1] == '.'){ //bottom left corner avail go around
		return 1;
	}
	return 0;
}

void printLab(char lab[][MAXROWS],int maxRow){
	int i = 0;
	int j = 0;
	
	while(i<maxRow+1){
		printf("%s\n",lab[i]);
		i++;
	}
}

void moveRight(int* row,int* col){
	col++;
}

void moveLeft(int* row,int* col){
	col--;
}

void moveUp(int* row,int* col){
	row--;
}

void moveDown(int* row,int* col){
	row++;
}
