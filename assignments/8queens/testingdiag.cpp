#include <iostream> 
using namespace std;


bool checkLowerDiagonal(int r, int c, int arr[][8]){
  for(int i = 1; (i <= c) && r+i < 8; i++){
    if(arr[r+i][c-i] == 1){
      cout << "low diag fail" << endl;
      return false;
    }
  }
  return true;
}

int main(){         

				   //0,1,2,3,4,5,6,7
	int q[8][8] = { {1,0,0,0,0,0,0,0},//0
					{0,0,0,0,0,0,1,0},//1
					{0,0,0,1,0,0,0,0},//2
					{0,0,0,0,0,1,0,0},//3
					{0,0,0,0,0,0,0,1},//4
					{0,1,0,0,0,0,0,0},//5
					{0,0,0,0,1,0,0,0},//6
					{0,0,1,0,0,0,0,0} //7
				}; 


	for(int r = 0; r < 8; r++){
		for(int c = 0; c < 8; c++){
			if(q[r][c] == 1){
				if(checkLowerDiagonal(r,c,q)){
					cout << "passed" << endl;
				}
				
			}
		}
	}




	return 0;
}