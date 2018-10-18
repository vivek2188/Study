#include <iostream>
#include <ostream>
#include <algorithm>
using namespace std;

/// Compute the greatest common divisor of two numbers using Euclid's algorithm
int gcd(int a,int b){
	a = abs(a);
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

/// Defining the custom "rational" type
struct rational{
	int numerator;		///< numerator gets the sign of the rational value
	int denominator;	///< denominator is always positive
};

int main(void){
	rational pi;
	pi.numerator = 155;
	pi.denominator = 255;
	cout << "pi is about " << pi.numerator << "/" << pi.denominator << "\n";
	return 0;
}