#include <iostream>
using namespace std;


int main(){
	int board[8][8] = {0};
	int	r = (-1); //row
	int c = 0;    //column
	int count = 1; //solution count to be printed later
  
  nr: r++;
  	//if all tiles in column failed
  	//we need to backtrack to the previous column
  	//and start checking at the next row
	if(r == 8) goto backtrack;

	//check that there are no queens in the same row
	for(int i = 0; i < c; i++){ 
		if(board[r][i] == 1){
			goto nr;
		}
	}
	//check the upper-left diagonal for any queens
	for(int i = 0; ((r - i) >= 0) && i <= c; i++){
		if(board[r-i][c-i] == 1){
			goto nr;
		}
	}

	//checks the lower-left diagonal for any queens
	for(int i = 0; ((r + i) < 8) && i <= c; i++){
		if(board[r+i][c-i] == 1){
			goto nr;
		}
	}

	//when the row and column location pass the above 3 tests
	//set a queen at that location...
	board[r][c] = 1;	
	//and continue to the next column
	//reset r to -1
	//r will be incremented to 0 later at nr:
	nc: c++; 
	r = -1;
  	
	//if c is 8 then columns 1-7 
	//have queen in them therefore a solution was hit
  	if(c == 8) goto print; 
  	//if no solution was hit
	goto nr;	


	backtrack:
	//goes back to the previous column
	c--;
	if(c == -1){
		//when all solutions had already been checked we exit
		cout << "The End! " << endl;
		return 0;
	}
	//wherever this column previously had a queen
	//we remove it and set r to that location
	//where it will be incremented when nr is hit
	for(int i = 0; i < 8; i++){
		if(board[i][c] == 1){
			board[i][c] = 0;
			r = i;
			break;
		}
	}
	goto nr;


	print:
		cout << count << endl;
		for(int r = 0; r < 8; r++){
			for(int c = 0; c < 8; c++){
				if(board[r][c] == 1) cout << "Q ";
				else cout << "- ";
			}	
		cout << endl;
		}
	cout << endl;
	
	count++;
	goto backtrack;
}

