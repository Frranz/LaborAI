#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	listField l_field;
	
	linList_p newPoin = linListAllocCell("abcdefg");
	
	printf("mein char ist: %s",newPoin->text);	
	
	return 0;
}

linList_p linListAllocCell(char* payload){
	linList_p retCell = (linList_p) malloc(sizeof(linListCell));
	char* myString = (char*) malloc(STRINGLENGTH);
	strcpy(retCell->text,payload);
	return retCell;
}

void linListFreeCell(linList_p junk){
	free(junk);
}

void linListFree(listField){
	linList_p listEl;
	while(listEl->next){
		listEl = listEl->next;
		free(listEl)
	}
	
}
