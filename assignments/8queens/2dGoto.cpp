#include <iostream>
using namespace std;


int main(){
	int board[8][8] = {0};
	int	r = -1;
	int c = 0; 
	int count = 1;

	nr: r++;
	if(r == 8) goto backtrack;

	for(int i = 0; i < c; i++) 
		if(board[r][i] == 1) goto nr;
	for(int i = 0; ((r - i) >= 0) && i <= c; i++)
		if(board[r-i][c-i] == 1) goto nr;
	for(int i = 0; ((r + i) < 8) && i <= c; i++)
		if(board[r+i][c-i] == 1) goto nr;

	board[r][c] = 1;	
	

	nc: c++; 
	r = -1;
  	if(c == 8) goto print; 
	goto nr;	


	backtrack: c--;
	if(c == -1) return 0;

	for(int i = 0; i < 8; i++)
		if(board[i][c] == 1){
			board[i][c] = 0;
			r = i;
			break;
		}
	goto nr;


	print:
		cout << count << endl;
		for(int r = 0; r < 8; r++){
			for(int c = 0; c < 8; c++)
				if(board[r][c] == 1) cout << "Q ";
				else cout << "- ";	
		cout << endl;
		}
	cout << endl;
	count++;
	goto backtrack;
}

