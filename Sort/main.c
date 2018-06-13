#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int* num;
	int size;
	
	char fileName[20+1];
	strcpy(fileName,"listn_001000.txt");
	
	FILE* file = fopen(fileName,"r");
	size = getFileLength(file);
	printf("size: %d",size);	
	num = initArrayFromFile(fileName);
	printArray(num,size);
	insertSort(num,size);
	getch();
	return 0;
}

int* initArrayFromFile(char fileName[]){
	FILE* file = fopen(fileName,"r");
	char readBuffer[30+1];
	int counter = 0;
	int elemAmount = getFileLength(file);
	int* numArr = malloc(sizeof(int)*elemAmount);
	
	while(counter<elemAmount){
		fgets(readBuffer,30,file);
		sscanf(readBuffer,"%d",&numArr[counter]);
		counter++;
	}
	return numArr;
}

int getFileLength(FILE* file){
	char buffer[30+1];
	int size = 0;
	while(!feof(file)){
		fgets(buffer,30,file);
		size++;
	}
	size--;
	rewind(file);
	return size;
}

void printArray(int* num,int size){
	printf("=============\n");
	int counter = 0;
	while(counter<size){
		printf("%d\n",num[counter]);
		counter++;
	}
}

void insertSort(int* num,int size){
	int i = 0;
	int j = 0;
	int h;
	
	int outerLoopCount = 0;
	int innerLoopCount = 0;
	
	while(i<size-1){
		outerLoopCount++;
		if(num[i+1]>num[i]){
			i++;
		}else{
			i++;
			j = i;
			while(num[j-1]>num[j] && j > 0){
				innerLoopCount++;
				h = num[j];
				num[j] = num[j-1];
				num[j-1] = h;
				j--;
			}
		}
	}
	
	printArray(num,size);
	printf("durchlaufe innere schleife: %d\n",innerLoopCount);
}
