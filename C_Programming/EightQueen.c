#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define chessSize 4


void fourQueens(int i, int queenpos[chessSize]){

	if (i == chessSize){
		for (int k = 0;k<chessSize;k++){
			printf("%d  ",queenpos[k] );
		}
	printf("\n");
	return;
	}
	for (int k = 0; k < chessSize ;k++){
		bool conflict =false;
		for (int j = 0;j < i && (!conflict);j++){
			if ((i-j)== abs(queenpos[j]-k) || queenpos[j] == k ) {
				conflict = true;
			}
		}
		if (!conflict){
			queenpos[i] = k;
			fourQueens(i+1,queenpos);
		}
	}
	return;
}
int main(void){
	int queenpos[chessSize];
	fourQueens(0,queenpos);
	return 0;
}
