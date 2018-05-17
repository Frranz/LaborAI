#include <stdio.h>
#include <stdlib.h>

#define STRINGLENGTH 31

typedef struct linList{
	char* text[STRINGLENGTH];
	struct linList *next;
}linListCell,*linList_p;

typedef struct listField{
	struct linList* start;
	struct linList* momentan;
}

linList_p linListAllocCell(char* c);
void linListFreeCell(linList_p junk);
void linListFree(linList_p *anchor)

