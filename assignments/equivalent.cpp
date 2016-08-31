#include <iostream>
using namespace std;


int findStart(int arr1[], int len, int arr2[]){
	for(int i = 0; i < len; i++){
		if(arr1[0] == arr2[i]) return i;
	}
	return -1;
}

bool isEquiv(int arr1[], int len, int arr2[]){
	int start = findStart(arr1, len, arr2);
	if(start == -1) return false;


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
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {3,4,5,1,2};


	if(isEquiv(arr1, arrlen, arr2)) cout << "Equivalent!";
	else cout << "Not Equivalent!!" << endl;
	return 0;
}

