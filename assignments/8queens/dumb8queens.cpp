#include <iostream>
using namespace std;

// Returns true if the board configuration is ok.  You must check all of the queens, not just one.
bool checkHorizontal(int r, int c, int arr[][8]){
  for(int i = 0; i < c; i++){
    if(arr[r][i] == 1){
     // cout << "hoz fail" << endl;
      return false;
    }
  }
  return true;
}

bool checkUpperDiagonal(int r, int c, int arr[][8]){
  for(int i = 1; (i <= c) && (r-i >= 0); i++){
    if(arr[r-i][c-i] == 1){
     // cout << "upp diagfail" << endl;
      return false;
    }
  }
  return true;
}

bool checkLowerDiagonal(int r, int c, int arr[][8]){
  for(int i = 1; (i <= c) && (r+i < 8); i++){
    if(arr[r+i][c-i] == 1){
    //  cout << "low diag fail" << endl;
      return false;
    }
  }
  return true;
}

bool ok(int q[][8]) {
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(q[i][j] == 1){
          if(!checkHorizontal(i, j, q) || !checkLowerDiagonal(i, j, q) || !checkUpperDiagonal(i, j, q)){ 
            return false;
          }
        }
      } 
    }
    return true;
}

void print(int q[][8]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\n";
   for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j)
         cout << q[i][j];
      cout << "\n";
   }
}

int main() {
   int q[8][8] = {};
   // i0 is the position of the queen in column #0, i1 is the position of the queen in column #1, etc.
   // You are testing all 8^8 possible board configurations (with the restriction of 1 queen per column),
   // as opposed to the backtracking version where you test only a small portion of the board configurations.
   for (int i0 = 0; i0 < 8; ++i0)
      for (int i1 = 0; i1 < 8; ++i1)
         for (int i2 = 0; i2 < 8; ++i2)
            for (int i3 = 0; i3 < 8; ++i3)
               for (int i4 = 0; i4 < 8; ++i4)
                  for (int i5 = 0; i5 < 8; ++i5)
                     for (int i6 = 0; i6 < 8; ++i6)
                        for (int i7 = 0; i7 < 8; ++i7) {
                           // Place the 8 queens on the chessboard:
                           q[i0][0] = 1; 
                           q[i1][1] = 1; 
                           q[i2][2] = 1; 
                           q[i3][3] = 1; 
                           q[i4][4] = 1; 
                           q[i5][5] = 1; 
                           q[i6][6] = 1; 
                           q[i7][7] = 1; 
                           

                           if(ok(q))
                              print(q);
                            
                           
                           q[i0][0] = 0;
                           q[i1][1] = 0;
                           q[i2][2] = 0;
                           q[i3][3] = 0;
                           q[i4][4] = 0;
                           q[i5][5] = 0;
                           q[i6][6] = 0;
                           q[i7][7] = 0;
                        }
   return 0;   
}
