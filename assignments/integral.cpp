#include <iostream>
using namespace std;

typedef double (* Func) (double);


//functions
double line(double a){return a;}
double square(double a) {return a*a;}
double cube(double a) {return a*a*a;}

//ideally width is optional argument
double integral(Func func, double a, double b, double width = .000001){
	double integralApproximation, height;
	int n = (int)((b-a)/width);
	for(int i = 1; i <= n; i++){
		height = func(a + (width * i));
		integralApproximation += width * height;
	}
	return integralApproximation;
}


int main(){
	cout << integral(line, 1, 5) << endl;
	cout << integral(square, 1, 5) << endl;
	cout << integral(cube, 1, 5) << endl;
	return 0;
}
