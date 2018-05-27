#include <stdio.h>

int main(void){
	int goal;
	int steps;
	
	printf("welche Zahl?\n");
	scanf("%d",&goal);
	fflush(stdin);
	
	steps = greedy(goal);
	printf("number of steps: %d",steps);
	
/*	int start = 1;
	
	while(start*3<GOAL/2){
		start = start*3;
		printf("3");
	}
	while(start*2<=GOAL){
		start = start*2;
		printf("2");
	}
	while(start!=GOAL){
		start++;
		printf("1");
	}*/
	
	return(0);
}

int greedy(int goal){
	int steps = 0;
	while(goal!=1){
		if(goal%3 == 0){
			goal /=3;
			printf("3\n");
			steps++;
		}else if(goal%2==0){
			goal/=2;
			printf("2\n");
			steps++;
		}else{
			goal++;
			printf("1\n");
			steps++;
		}
	}
	return steps;
}
