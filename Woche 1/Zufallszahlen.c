#include <stdio.h>

#define MAXNUM 1000
#define MAXITEMS 1000

int main(void){
	int amount;
	int outnum;
	int arrnum[MAXITEMS];
	int i;
	
	printf("Wie viele Zufallszahlen sollen generiert werden?");
	scanf("%d",&amount);
	fflush(stdin);
	
	for(i=0;i<amount;i++){
		outnum = rand() % MAXNUM;
		arrnum[i] = outnum;
	}
	
	printarr(amount,arrnum);
	
	printf("numbers doubled\n");
	double_num(amount,&arrnum);
	printarr(amount,arrnum);
	
	printf("numbers reversed\n");
	reverse_str(amount,&arrnum);
	printarr(amount,arrnum);

	return(0);
}

void printarr(int arrlen, int* arrnum){
	int i;
	for(i=0;i<arrlen;i++){
		printf("%d\n",arrnum[i]);
	}
}

void double_num(int arrlen,int* arrnum){
	int i;
	for(i=0;i<arrlen;i++){
		arrnum[i] = arrnum[i] * 2;
	}
}

void reverse_str(int arrlen,int* arrnum){
	int i;
	int help;
	
	for(i=0;i<arrlen/2;i++){
		help = arrnum[i];
		arrnum[i] = arrnum[arrlen-i-1];
		arrnum[arrlen-i-1] = help;
	}
}


