#include <iostream>
using namespace std;

bool last_two_digs_are_odd(long n){
	int a = n%10; int b = n/10%10;
	if(a%2==1 && b%2==1) return true;
	else								 return false;
}

int main(){
	long i = 4;
	while(i < 100){
		cout << i << "^2 = " << i*i << endl;
		if(last_two_digs_are_odd(i*i)){
			cout << i*i << "we hit ODD!!" << endl;
			break;		
		}
		i++;
	}
	cout << "Finished!, No number exists because\n";
	cout << "by 100 the last two digs will repeat\n";
	cout << "simple example: 236 * 236 = 55696 \n"<<
					"                136 * 136 = 18496 \n"<<
					"                 36 * 36  =  1296";
}



