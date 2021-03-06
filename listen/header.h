#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLENGTH 255

typedef struct linList{
	char text[STRINGLENGTH+1];
	struct linList *next;
}linListCell,*linList_p;

typedef struct listField{
	struct linList* start;
	struct linList* momentan;
	struct linList* zwischen;
}linListField;

typedef struct statStruct{
	char text[STRINGLENGTH+1];
	unsigned char counter;
	struct statStruct *next;
}hashStruct, *hashStruct_p;

linList_p linListAllocCell(char* c);
void linListFreeCell(linList_p junk);
void linListFree(linListField* f);
void linListInsertFirst(linListField* f, linList_p newFirstCell);
void linListInsertLast(linListField* f, linList_p newLasttCell);
linList_p linListExtractFirst(linListField* f);
void linListPrint(linListField f);
void linListPrintReverse(linListField f);
void deleteDublicatesNaive(linListField* f);
linList_p linListFind(linListField f,char* payload);
linList_p linListExtract(linListField *f, linList_p cell);
void linListRevert(linListField *f);
void linListSwap(linListField* f,linList_p cell1, linList_p cell2);
int createHashFromString(char text[], int maxSize);
void emptyArray(hashStruct* arr[],int arrLen);
int linListGetLength(linListField f);
void createHashTableFromLinList(linListField f, hashStruct* arr[], int arrLen);
hashStruct_p getStructFromHashTable(hashStruct* arr[],char* payload,int arrSize);
void printCounters(hashStruct* arr[],int arrSize);
