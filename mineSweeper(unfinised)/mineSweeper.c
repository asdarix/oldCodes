/*
 * mineSweeper.c
 * MUSTAFA SABRİ İNCE
 *  Created on: Oct 30, 2018
 *      Author: adaskin
 */


#include <stdio.h>
#include <stdlib.h>
#define M  10       /*Row*/
#define N  10       /*Column*/
int nmines = 0;     /*mayin sayisi*/

int minefield[M][N]; /*2d array for mine field*/
int clues[M][N];     /*2d array holds the clues*/


int mineSweeper(int n);
int generateField(void);
int generateClues(void);
void printClues();
void printField();
int countMines(int r, int c);


int countMines(int r, int c){

	int maysayisi= 0;
	for(int x = r-1; x<= r +1;x++){
		for(int y = c-1;y<=c+1;y++){
			if(!(x==r&&y==c)&& (x>=0 && x < M) && (y>=0 && y < N ) ){	
				if (1==minefield[x][y]){
					maysayisi++;
				}
			}
		}
	}

return maysayisi;
}
int generateClues(){
	/*TODO: for each nonmine cell on the minefield,
	 * call the function countmines(int r, int c)
	 * to find the number of mines
	 * in the surrounding 8 squares of the cell*/

	/*Turkish*/
	/*TODO: tarladaki mayin olmayan herbir hucre icin,
	 * mayinsay fonksiyonunu cagirarak etrafindaki mayin sayisini bulun
	 */
return 0;
}

/*initializes the minefield board using nmines*/
int generateField(){

	for(int x=0;x<M;x++){
		for(int y=0;y<N;y++){
			minefield[x][y]=0;
		}
	}
 int koyulanmayin=0;
	while(koyulanmayin < nmines){
		int c = rand()%M;
		int d = rand()%N;
		if(minefield[c][d] != 1){
			minefield[c][d] = 1;
			koyulanmayin++;
		}
			
		
	}	
			
return koyulanmayin;
}

/*prints the array clues*/
void printClues(){
	
	for(int x=0;x<M;x++){
		for(int y=0;y<N;y++){
			clues[x][y] = countMines(x,y);
			printf("%d ", clues[x][y]);
			
		}
		printf("\n");
	}
}

/*prints the array minefield*/
void printField(){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", minefield[i][j]);
		}
		printf("\n");
	}
}

/* initializes nmines and calls generateField and generateClues */
int mineSweeper(int n){
	nmines = n;
	generateField();
	

	return 0;
}

int main(){
	mineSweeper(14);
	printField();
	printf("asdasd\n");
	printClues();
	/*TODO call mineSweeper with an argument*/
	/*TODO call printField to print the board*/
	/*TODO call printClues to print the clues*/
	return 0;
}
