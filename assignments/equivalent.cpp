#include <iostream>
using namespace std;

bool isEquiv(int arr1[], int len, int arr2[], int start){
 	for(int i = 0; i < len; i++){
		cout << arr1[i] << " = " << arr2[start%len] << endl;
		if(arr1[i] != arr2[start%len]){
			return false;
		}
		start++;
	}
	return true;
}
int main(){
	int arrlen = 5;
	int arr1[5] = {1,2,3,1,5};
	int arr2[5] = {3,1,5,1,2};

  for(int i = 0; i < arrlen; i++)
		if(arr1[0] == arr2[i]){
			if(isEquiv(arr1, arrlen, arr2, i))
				cout << "Equivalent!";	
			else
				cout << "Not Equivalent!!" << endl;
		}
	return 0;
}

