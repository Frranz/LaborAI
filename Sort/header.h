#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* initArrayFromFile(char fileName[]);
int getFileLength(FILE* file);
void printArray(int* num,int size);
void insertSort(int* num,int size);
void mergeSort(int *num, int size);
