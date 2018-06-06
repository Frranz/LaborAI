#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE* in = stdin;
	Lab_p lab;
	
	if(argc == 2){
		in = fopen(argv[1],"r");
		if(!in){
			perror(argv[0]);
			return 0;
		}
	}
	
	
	
	return 0;
}
