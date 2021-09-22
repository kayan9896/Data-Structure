#include <stdio.h>
#include <stdlib.h>
int g[5];
int guessnum=0;
int right;
int try;
int i;
	
void game(){
	while (guessnum != right){
		printf("Input guess number 1-10 :");
		scanf("%d",&guessnum);
		if (guessnum==right){
			printf("Correct\n-------------------------------------\n");
			try+=1;
			break;
		}
		else if (guessnum>right){
			printf("Guess lower\n");
			try+=1;
		}
		else {
			printf("Guess higher\n");
			try+=1;
		}
	}
}

int main(){
	for(i=0;i<=4;i++){
		right= rand()%10 ;
		try=0;
		game();
		g[i]=try;
	}
	for(i=0;i<=4;i++){
		printf("Game %d took %d Guesses\n", i,g[i]);
	}
	return 0;
}
