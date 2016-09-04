#include <iostream>
using namespace std;


bool checkHorizontal(int r, int c, int arr[][8]){
	for(int i = 0; i < c; i++){
		if(arr[r][i] == 1){
			if(r==7 && c==0){
				cout << "hoz fail\n";	
			}	
			return false;
		}	
	}
	return true;
}

bool checkUpperDiagonal(int r, int c, int arr[][8]){
	for(int i = r; i > 0; i--){
		if(arr[r-i][c-i] == 1){
			return false;	
		}
	}
	return true;
}

bool checkLowerDiagonal(int r, int c, int arr[][8]){
	for(int i = c; i > 0; i--){
		if(arr[r+i][c-i] == 1){
			return false;
		}
	}
	return true;
}

bool checker(int r, int c, int arr[][8]){
	if(checkHorizontal(r, c, arr) && checkLowerDiagonal(r, c, arr) && checkUpperDiagonal(r, c, arr)){
		return true;
	}
	return false;
}

int row_where_c(int c, int arr[][8]){
	for(int i = 0; i < 8; i++){
		if(arr[i][c] == 1){
			return i;
		}
	}
}

void printBoard(int arr[][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(arr[j][i]){
				cout << j << " ";
			}
		}
	}
	cout << endl;
}


int main(){
	int board[8][8] = {0}; 
	int r = 0;
	int c = 0;
	int solution = 1;


	while(c <= 8 && r <= 8){
		if(c == 8){
			cout << "Solution " << solution << " = ";
			printBoard(board);
			solution++;
			c = 6;
			board[row_where_c(7, board)][7] = 0;
			r = row_where_c(c, board) + 1;
			board[row_where_c(6, board)][6] = 0;
			char a;
			cin >> a;

		}
		else if(r == 8){
			if(c == 0){
				c+=1;
				board[row_where_c(c, board)][c] = 0;
				r = row_where_c(c, board) + 1;
			}
			else {
				cout << "r = " << r << " c = "<< c << " r == 8! \n";
				c -= 1;
				board[row_where_c(c, board)][c] = 0;
				r = row_where_c(c, board) + 1;
			}
		}
		else if(checker(r, c, board)){
			cout << "r = "<< r << " c = "<< c << " checker Passed!\n";
			board[r][c] = 1;
			c++;
			r = 0;
		}
		else{
			cout << "r = "<< r << " c = "<< c << " checker Failed!\n";
			r++;
		}
	}
	return 0;
}

