#include<iostream>

using namespace std;

int main(){

	int b[8] = {0};
	cout << "sizeof b " << " " << sizeof(b) << endl;
	cout << "sizeof int = " << sizeof(int) << endl; 
	cout << "length of array = sizeof(b)/sizeof(int) = " << sizeof(b)/(sizeof(int)) << endl;
	cout << "b = " << b << endl;
	cout << "b = &b[0]  Ex. " << b << " " << &b[0] << endl;
	cout << "&b + 1 = " << &b + 1 << endl;
	for(int i = 0; i <= 8; i++)
	cout << "b + "<< i << " = "  << b + i << endl;


}
