#include <iostream>
using namespace std;

typedef double (* Func) (double);


//functions
double line(double a){return a;}
double square(double a) {return a*a;}
double cube(double a) {return a*a*a;}

//ideally width is optional argument
double integral(Func func, double a, double b, double width = .000001){
	double Approximation, height;
	for(double i = a; i < b; i += width){
		height = func(i);
		Approximation += width * height;
	}
	return Approximation;
}


int main(){
	cout << integral(line, 1, 5) << endl;
	cout << integral(square, 1, 5) << endl;
	cout << integral(cube, 1, 5) << endl;
	return 0;
}
