#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	linListField l_field;
	l_field.start = 0;
	l_field.momentan = 0;
	
	int amount;
	int counter = 0;
	char stringBuffer[255+1];
	printf("wie viele strings sollen eingelesen werden?\n");
	scanf("%d",&amount);
	fflush(stdin);
	
	
	while(counter<amount){
		scanf("%255s",stringBuffer);
		fflush(stdin);
		if(strlen(stringBuffer)<256){
			linList_p newElement = linListAllocCell(stringBuffer);
			linListInsertLast(&l_field,newElement);
			counter++;
		}
	}
	
	linListPrint(l_field);
	linListPrintReverse(l_field);
	
/*	linList_p newPoin = linListAllocCell("abcdefg");	
	linList_p newPoin2 = linListAllocCell("petrusmeinsohn");	
		
	
	linListInsertFirst(&l_field,newPoin);
	linListInsertFirst(&l_field,newPoin2);
	linListPrint(l_field);
	
	linListFree(&l_field);
	linListPrint(l_field);
	return 0;
*/}

linList_p linListAllocCell(char* payload){
	linList_p retCell = (linList_p) malloc(sizeof(linListCell));
	char* myString = (char*) malloc(STRINGLENGTH);
	strcpy(retCell->text,payload);
	retCell->next = 0;
	return retCell;
}

void linListFreeCell(linList_p junk){   //noch nicht fertig. schauen ob die cell am anfang ist
	free(junk);
}

void linListFree(linListField* f){
	f->momentan = f->start;
	while(f->momentan!=0){
		f->momentan = f->start->next;
		linListFreeCell(f->start);
		f->start = f->momentan;
	}
	printf("everything has been deleted my friend\n");
}

void linListInsertFirst(linListField* f, linList_p newFirstCell){   //nicht sicher, warum das einen rückgabewert braucht
	newFirstCell->next = f->start;
	f->start = newFirstCell;
	printf("%s als erstes Element eingefügt\n",f->start->text);
}

void linListInsertLast(linListField* f, linList_p newLastCell){   //nicht sicher, warum das einen rückgabewert braucht4
	if(f->start==0){
		f->start = newLastCell;
		f->momentan = f->start;
	}else{
		f->momentan = f->start;
		while(f->momentan->next){
			f->momentan = f->momentan->next;
		}
		f->momentan->next = newLastCell;
		f->momentan = f->momentan->next;
	}
	printf("%s als letztes Element eingefügt\n",f->momentan->text);
}

linList_p linListExtractFirst(linListField* f){
	return f->start;
}

void linListPrint(linListField f){
	printf("=======================================\n");
	printf(">list from first to last\n");
	f.momentan = f.start;
	while(f.momentan){
		printf("%s\n",f.momentan->text);
		f.momentan=f.momentan->next;
	}
}

void linListPrintReverse(linListField f){
	linList_p elemBuffer;
	printf("=======================================\n");
	printf(">list from last to first\n");
	f.momentan = f.start;
	while(f.momentan){
		f.momentan=f.momentan->next;
	}
	//f.momentan now on last element
	elemBuffer = f.momentan;
	f.momentan = f.start;
	
	while(elemBuffer!=f.start){
		while(f.momentan->next!=elemBuffer){
			f.momentan =f.momentan->next;
		}
		printf("%s\n",f.momentan->text);
		elemBuffer = f.momentan;
		f.momentan=f.start;
	}
	
	
}
