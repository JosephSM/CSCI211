#include <iostream>
using namespace std;

bool checkHorizontal(int r, int c, int arr[][8]){
	// returns false if neighboring rows contain any 1s
	for(int i = 0; i < c; i++){
		if(arr[r][i] == 1){
			return false;
		}	
	}
	return true;
}

bool checkUpperDiagonal(int r, int c, int arr[][8]){
	//returns false if any upper-left diagonal "tiles" contain any 1s
	for(int i = 0; (i <= c) && (r-i >= 0); i++){
		if(arr[r-i][c-i] == 1){
			return false;
		}
	}
	return true;
}

bool checkLowerDiagonal(int r, int c, int arr[][8]){
	//checks if any lower left diagonal tiles contain any 1s
	for(int i = 0; (i <= c) && (r+i < 8); i++){
		if(arr[r+i][c-i] == 1){
			return false;
		}
	}
	return true;
}

bool check(int r, int c, int arr[][8]){
	//returns true if all 3 conditions above return true 
	if(checkHorizontal(r, c, arr) && checkLowerDiagonal(r, c, arr) && checkUpperDiagonal(r, c, arr)){
		return true;
	}
	return false;
}


void nextRow(int &r){
	r++;
}

void nextColumn(int &r, int &c){
	c++;
	r = 0;
}

void backtrack(int &r, int &c, int (&arr)[8][8]){
	//moves to the previous column
	//clears the location where the queen is
	//and sets r at the subsequent row in that column
	c--;
	for(int i = 0; i < 8; i++){
		if(arr[i][c] == 1){
			arr[i][c] = 0;
			r = i;
			nextRow(r);
			break;
		}
	}
}

void printBoard(int &count, int arr[][8]){
	cout << count << endl;
	count++;

	for(int r = 0; r < 8; r++){
		for(int c = 0; c < 8; c++){
			if(arr[r][c] == 1){
				cout << "q ";
			}
			else cout << "- ";
		}
	cout << endl;
	}
}





int main(){
int arr[8][8] = {0};
int col = 0;
int row = 0;
int count = 1;

while(true){
	if(col == -1){
		break;
	}
	if(col == 8){
		printBoard(count, arr);
		backtrack(row, col, arr);
	}
	else if(row == 8){
		backtrack(row, col, arr);
	}
	else if(check(row, col, arr)){
		arr[row][col] = 1;
		nextColumn(row, col);
	}
	else{
		nextRow(row);
	}
}

return 0;
}


