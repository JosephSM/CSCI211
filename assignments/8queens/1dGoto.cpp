#include <iostream>

using namespace std;

int main(){
	int q[8] = {-1};
	int c = 0;
	int count = 1;
	nr:
	q[c]++;
	if(q[c] == 8) goto backtrack;
	for(int i = 0; i < c; i++){
		if(q[c]==q[i] || c-i == abs(q[c]-q[i])){
			goto nr;
		}
	}
	nc:
	c++;
	if(c == 8) goto print;
	goto nr;


	backtrack:
 	q[c] = -1;	
	c--;
	if(c == -1){
		cout << "The End!" << endl;
		return 0;
	}
	goto nr;

	print:
		cout << count << endl;
		for(int r = 0; r < 8; r++){
			for(int i = 0; i < 8; i++){
				if(q[i] == r){
					cout << "Q ";
				}
				else cout << "- ";
			}
		cout << endl;
		}
	cout << endl;
	count++;
	goto backtrack;




	return 0;
}
