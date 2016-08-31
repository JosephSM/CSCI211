#include <iostream>
using namespace std;

bool last_two_digs_are_odd(long n){
	int a = n%10; int b = n/10%10;
	if(a%2==1 && b%2==1) return true;
	else								 return false;
}

int main(){
	long i = 4;
	while(true){
		if(last_two_digs_are_odd(i*i)){
			cout << i << "^2 = " << i*i << endl;
			break;		
		}
		i++;
	}
	cout << "Finished";
	return 0;
}



