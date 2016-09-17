#include <iostream>
using namespace std;


void printBoard(int cross[]){
	cout << endl;
	cout << " "      << " " << cross[1] << " " << cross[4] << endl;
	cout << cross[0] << " " << cross[2] << " " << cross[5] << " " << cross[7] << endl;
	cout << " "      << " " << cross[3] << " " << cross[6] << endl;
	cout << endl;
}



bool checker(int r, int cross[], int neighbors[][6]){
	for(int i = 0; i < r; i++)
		if(cross[r] == cross[i]){
			//cout << "             r = " << cross[r] << " i = " << cross[i] << endl;
			return false;
		}
	for(int i = 0; i < r && neighbors[r][i] != 0; i++)
		if(abs(cross[r] - cross[neighbors[r][i]-1]) < 2 && cross[neighbors[r][i]-1] != 0){
			return false;
		}	
	return true;
}

void printBoard2(int Board[]){
	for(int i = 0; i < 8; i++){
		cout << Board[i] << " ";
	}
	cout << endl;
}



int main(){
	int count = 0; 
	int row = 0;
	int cross[8] = {0};
	int neighbors[8][6] = {
		{2,3,4},      //1
		{1,3,5,6},    //2
		{1,2,4,5,6,7},//3
		{1,3,6,7},    //4
		{2,3,6,8},    //5
		{2,3,4,5,7,8},//6
		{3,4,6,8},    //7
		{5,6,7}       //8
	};


	while(true){
		cross[row]++;
		if(row == 8){
			count++;
			cout << "Solution " << count << endl;
			printBoard(cross);
			row--;
		}
		else if(row == -1){
			break;
		}
		else if(cross[row] == 9){
			cross[row] = 0;
			row--;
		}
		else if(checker(row, cross, neighbors)){
			row++;
		}

	}
	cout << "end!" << endl;
	return 0;
}