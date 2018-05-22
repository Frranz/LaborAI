#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLENGTH 31

typedef struct linList{
	char* text[STRINGLENGTH];
	struct linList *next;
}linListCell,*linList_p;

typedef struct listField{
	struct linList* start;
	struct linList* momentan;
}linListField;

linList_p linListAllocCell(char* c);
void linListFreeCell(linList_p junk);
void linListFree(linListField* f);
void linListInsertFirst(linListField* f, linList_p newFirstCell);
void linListInsertLast(linListField* f, linList_p newLasttCell);
linList_p linListExtractFirst(linListField* f);
void linListPrint(linListField f);
void linListPrintReverse(linListField f);
