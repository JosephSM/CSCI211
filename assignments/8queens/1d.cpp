#include <iostream>
using namespace std;


bool checker(int q[8], int c){
	for(int i = 0; i < c; i++)
		if(c-i == abs(q[c] - q[i]) || q[c] == q[i])
			return false;
	return true;
}


void printBoard(int q[8]){
	for(int r = 0; r < 8; r++){
		for(int c = 0; c < 8; c++){
			if(r == q[c]) cout << "Q "; 
			else          cout << "- ";
		}
		cout << endl;
	}
	cout << endl;
}


int main(){
	int queens[8] = {-1}; 
	int c = 0;
	int count = 1;

	while(true){			
		queens[c]++;
		
		if(c == -1) break;
		if(c == 8){
			cout << count << endl;
			count++;
			printBoard(queens);
			c--;
		}

		else if(queens[c] == 8){
			queens[c] = -1;
			c--;
		}
		
		else if(checker(queens, c))
			c++;
	}
	return 0;
}
