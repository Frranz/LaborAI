#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	char stdFileName[35+1];
	strcpy(stdFileName,"testlab.txt");
	
	int colCount;
	int rowCount = 0;
	FILE* in = stdin;
	LabCell lab;
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
//		printf("%s",readBuffer);
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
	myNaive(&lab);
	printf("nach naive\n");
	getch();
	
	return 0;
}

void solveLab(Lab_p lab){
	printf("test");
	myNaive(lab);
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
		}else if(lab->lab[row][col] == ' '){//no spaces to explore --> return;
			printf("no spaces around, lets go back\n");
			lab->lab[row][col] = '.';
		}else if(lab->lab[row][col+1] == '.'){ 	//check right
			if(!twoOrMoreAround(lab->lab,row,col,'.')){
				lab->lab[row][col] = '!';
			}
			col++;
		}else if(lab->lab[row+1][col] == '.'){ 	//check down
			if(!twoOrMoreAround(lab->lab,row,col,'.')){
				lab->lab[row][col] = '!';
			}
			row++;
		}else if(lab->lab[row][col-1] == '.'){ 	//check left
			if(!twoOrMoreAround(lab->lab,row,col,'.')){
				lab->lab[row][col] = '!';
			}
			col--;
		}else if(lab->lab[row-1][col] == '.'){ 	//check up
			if(!twoOrMoreAround(lab->lab,row,col,'.')){
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
	if(lab[row+1][col]==findTwoOfMe){
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
	return 0;
}

int canBlock(char lab[][MAXROWS],int row,int col){
	if(lab[row][col+1]=='.' && lab[row+1][col]=='.' && lab[row+1][col+1]){ //bottom right corner avail;
		
	}
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
