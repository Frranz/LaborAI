#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	hashStruct* hashMap;
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
	
	hashMap = (hashStruct_p)malloc(sizeof(hashStruct_p)*amount);
	emptyArray(hashMap,amount);
	createHashTableFromLinList(l_field,hashMap,linListGetLength(l_field));
	hashStruct_p test = getStructFromHashTable(hashMap,"getpetrus",amount);
	printCounters(hashMap,amount);

	


//	linListPrint(l_field);
//	linListRevert(&l_field);
//*/
//	linListPrintReverse(l_field);
/*	deleteDublicatesNaive(&l_field);
	linListPrint(l_field);
	
	linList_p findMe = linListFind(l_field,"b");
	printf("find me got element with text: %s\n",findMe->text);
	
	linList_p findMe2 = linListFind(l_field,"c");
//	linListSwap(&l_field,findMe,findMe2);
	linListPrint(l_field);
	
	linList_p extracted = linListExtract(&l_field,findMe);
	printf("content of extracted cell: %s\n",extracted->text);
	printf("Adresse von findMe: %10x und von extracted %10x\n",findMe,extracted);
	
	linListPrint(l_field);
	
	linListFree(&l_field);
	linListPrint(l_field);*/
	
/*	linList_p newPoin = linListAllocCell("abcdefg");	
	linList_p newPoin2 = linListAllocCell("hc");	
		
	
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
	linList_p buffer;
	buffer = f->start;
	while(buffer!=0){
		buffer = f->start->next;
		linListFreeCell(f->start);
		f->start = buffer;
	}
	printf("everything has been deleted my friend\n");
}

void linListInsertFirst(linListField* f, linList_p newFirstCell){   //nicht sicher, warum das einen rückgabewert braucht
	newFirstCell->next = f->start;
	f->start = newFirstCell;
	printf("%s als erstes Element eingefügt\n",f->start->text);
}

void linListInsertLast(linListField* f, linList_p newLastCell){   //nicht sicher, warum das einen rückgabewert braucht4+
	linList_p buffer;
	if(f->start==0){
		f->start = newLastCell;
		buffer = f->start;
	}else{
		buffer = f->start;
		while(buffer->next){
			buffer = buffer->next;
		}
		buffer->next = newLastCell;
		buffer = buffer->next;
	}
	printf("%s als letztes Element eingefügt\n",buffer->text);
}

linList_p linListExtractFirst(linListField* f){
	return f->start;
}

void linListPrint(linListField f){
	linList_p buffer;
	printf("=======================================\n");
	printf(">list from first to last\n");
	buffer = f.start;
	while(buffer){
		printf("%s\n",buffer->text);
		buffer=buffer->next;
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

void deleteDublicatesNaive(linListField* f){
	printf("========================================\n");
	printf(">deleting duplicates\n");
	linList_p firstOccurance;
	linList_p runner;
	linList_p deleteBuffer;
	firstOccurance = f->start;
	
	while(firstOccurance){
		runner = firstOccurance;
		while(runner->next){
			if(strcmp(runner->next->text,firstOccurance->text)==0){
				deleteBuffer = runner->next;
				runner->next = runner->next->next;
				linListFreeCell(deleteBuffer);
			}else{
				runner = runner->next;	
			}
		}
		firstOccurance = firstOccurance->next;
		
	}
}

linList_p linListFind(linListField f,char* payload){
	linList_p runner;
	runner = f.start;
	while(runner){
		if(strcmp(runner->text,payload)==0){
			return runner;
		}
		runner = runner->next;
	}
}

linList_p linListExtract(linListField *f, linList_p cell){
	linList_p runner;
	runner = f->start;
	
	if(f->start == cell){
		f->start == cell->next;
		return cell;
	}
	
	while(runner->next){
		if(runner->next == cell){
			runner->next = runner->next->next;
			return cell;
		}
		runner = runner->next;
	}
	
	return 0;
}

void linListRevert(linListField *f){
	/*printf("list reverted\n");
	linList_p runner;
	linList_p startFront;
	linList_p startBack;
	linList_p saveLast;
	runner = f->start;
	while(runner->next){
		runner = runner->next;
	}
	
	startFront = f->start;
	while(startFront!=startBack && startFront->next != startBack){
		startBack = startFront;
		while(startBack->next != runner){
			
		}
	}*/
	
	linList_p runner;
	linList_p saveLast;
	linList_p swapBuffer;
	runner = f->start;
	while(runner->next){
		runner = runner->next;
	}
	saveLast = runner;
	
	runner = f->start;
	while(f->start!=saveLast){
		swapBuffer = saveLast->next;
		saveLast->next = f->start;
		f->start = f->start->next;
		saveLast->next->next = swapBuffer;
	}
}

void linListSwap(linListField* f,linList_p cell1, linList_p cell2){
	printf("swapping %s and %s\n",cell1->text,cell2->text);
	linList_p before1;
	linList_p before2;
	linList_p buffer;
	
	before1 = f->start;
	before2 = f->start;
	
	while(before1->next != cell1 && before1->next != 0){
		before1 = before1->next;
	}
	
	while(before2->next != cell2 && before2->next != 0){
		before2 = before2->next;
	}
	
	if(f->start == cell1){
		f->start = cell2;
		buffer= cell1->next;
		cell1->next = cell2->next;
		cell2->next = buffer;
		before2->next = cell1;
	}else if(f->start == cell2){
		f->start = cell1;
		buffer= cell2->next;
		cell2->next = cell1->next;
		cell1->next = buffer;
		before1->next = cell2;
	}else{
		before1->next = cell2;
		before2->next = cell1;
		
		buffer = cell2->next;
		cell2->next = cell1->next;
		cell1->next = buffer;
	}
	
}

int createHashFromString(char text[], int maxSize){
	int sum = 0;
	int counter = 0;
	while(text[counter]){
		sum += (int) text[counter];
		counter ++;
	}
	
	return sum % maxSize;
}

int linListGetLength(linListField f){
	int lCounter = 0; //length counter
	linList_p runner;
	
	runner = f.start;
	
	while(runner){
		lCounter++;
		runner = runner->next;
	}
	return lCounter;
}

void emptyArray(hashStruct* arr[],int arrLen){
	arrLen -=1;
	while(arrLen>-1){
		arr[arrLen] = 0;
		arrLen--;
	}
}

void createHashTableFromLinList(linListField f, hashStruct* arr[], int arrLen){
	int hashVal;
	linList_p outerRunner;
	hashStruct_p innerRunner;
	hashStruct* hashStrucCell;
	char* cellText;
	signed char textFound;
	outerRunner = f.start;
	while(outerRunner){
		hashVal = createHashFromString(outerRunner->text,arrLen);
		innerRunner = arr[hashVal];
		textFound = 0;
		while(innerRunner && !textFound){
			if(strcmp(innerRunner->text,outerRunner->text)==0){
				textFound = 1;
				innerRunner->counter += 1;
			}
			if(innerRunner->next==0){
				break;
			}else {
				innerRunner = innerRunner->next;	
			}
					
		}
		if(!textFound){
			hashStrucCell = malloc(sizeof(hashStruct));
//			cellText = (char*) malloc(STRINGLENGTH);
			if(innerRunner == 0){
				arr[hashVal] = hashStrucCell;
				innerRunner = arr[hashVal];
			}else{
				innerRunner->next = hashStrucCell;
				innerRunner = innerRunner->next;
			}
//			innerRunner->text = cellText;
			strcpy(innerRunner->text,outerRunner->text);
			innerRunner->next = 0;
			innerRunner->counter = 1;
		}
		
		
		outerRunner = outerRunner->next;
	}
}

hashStruct_p getStructFromHashTable(hashStruct* arr[],char* payload,int arrSize){
	hashStruct_p runner;
	int hashVal = createHashFromString(payload,arrSize);
	runner = arr[hashVal];
	while(runner){
		if(strcmp(runner->text,payload)==0){
			return runner;
		}
		runner = runner->next;
	}
	return 0;
}

void printCounters(hashStruct* arr[],int arrSize){
	hashStruct_p runner;
	arrSize--;
	while(arrSize>-1){
		runner = arr[arrSize];
		while(runner){
			printf("payload %s appeared %d times\n",runner->text,runner->counter);
			runner = runner->next;
		}
		
		arrSize--;
	}
}
