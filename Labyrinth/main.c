#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	char stdFileName[35+1];
	strcpy(stdFileName,"testlab.txt");
	
	int colCount;
	int rowCount = 0;
	FILE* in = stdin;
	Lab_p lab;
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
		while(readBuffer[colCount]!=0 && readBuffer[colCount]!="\n"){
			lab.lab[rowCount][colCount] = readBuffer[colCount];
			if(readBuffer[colCount]=="S"){
				lab.startx = colCount;
				lab.starty = rowCount;
			}
			if(readBuffer[colCount]=="X"){
				lab.endx = colCount;
				lab.endy = rowCount;
			}
			colCount++;
		}
		fgets(readBuffer,MAXCOLS,in);
	}
	
	lab.maxrow = rowCount-1;
	printLab(*lab);
	solveLab(lab);
	getch();
	
	return 0;
}

void solveLab(Lab_p lab){
	printf("peter fox 1.1.");
	myNaive(lab);
}

void myNaive(Lab_p lab){
	printf("hi");
	int row = lab->starty;
	int col = lab->startx;
	while(lab->lab[row][col]!="X"){
		system("@cls||clear");
		printLab(*lab);
		if(lab->lab[row][col] == "."){
			
		}else if(lab->lab[row][col]=="!"){
			
		}else if(lab->lab[row][col] =="S" || lab->lab[row][col]== " "){
			if(lab->lab[row][col+1] == " " || lab->lab[row][col+1] == "X" ){ //check right
				moveRight(&row,&col);
			}else if(lab->lab[row+1][col] == " " || lab->lab[row+1][col] == "X" ){ //check down
				moveDown(&row,&col);
			}else if(lab->lab[row][col-1] == " " || lab->lab[row][col-1] == "X" ){ //check left
				moveLeft(&row,&col);
			}else if(lab->lab[row-1][col] == " " || lab->lab[row-1][col] == "X" ){ //check up
				moveUp(&row,&col);
			}
			lab->lab[row][col] = ".";
		}
		getch();
	}
}

void printLab(LabCell lab){
	int i = 0;
	int j = 0;
	
	while(i<lab.maxrow+1){
		printf("%s",lab.lab[i]);
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
