#include <iostream>
using namespace std;

typedef double (* Func) (double);


//functions
double line(double a){return a;}
double square(double a) {return a*a;}
double cube(double a) {return a*a*a;}

//based on the instructions assignment
double integral(Func func, double a, double b, double width = .000001){
	double Approximation, height;
	for(double i = a; i <= b; i += width){
		height = func(i);
		Approximation += width * height;
	}
	return Approximation;
}


//truer to the formal definition of a riemann summ
//i.e. (lim -> infinity) of a summation from i=1 to n (where n is the number of rectangles)
//     of ((b-a)/n)f(a+(b-a)i/n)
double integral2(Func func, double a, double b, int n=10000000){
	double Approx, height;
	double width = ((b-a)/n);
	for(double i = 1; i <= n; i++){
		height = func(a+(width*i));
		Approx += height*width;
	}
	return Approx;
}


int main(){
	cout << "Homework Integral" << endl;
	cout << integral(line, 1, 5) << endl;
	cout << integral(square, 1, 5) << endl;
	cout << integral(cube, 1, 5) << endl;
	cout << "-------------------" << endl;
	cout << "Formal Integral" << endl;
  cout << integral2(line, 1, 5) << endl;
	cout << integral2(square, 1, 5) << endl;
	cout << integral2(cube, 1, 5) << endl;
	return 0;
}
