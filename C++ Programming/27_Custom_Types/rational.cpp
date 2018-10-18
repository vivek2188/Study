#include <iostream>
#include <ostream>
#include <algorithm>
#include <cassert>
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
	/// Reduce the numerator and denominator by their gcd
	void reduce(){
		assert(denominator!=0);
		int div = gcd(numerator,denominator);
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;		///< numerator gets the sign of the rational value
	int denominator;	///< denominator is always positive
};

int main(void){
	rational pi;
	pi.numerator = 155;
	pi.denominator = 0;
	pi.reduce();
	cout << "pi is about " << pi.numerator << "/" << pi.denominator << "\n";
	return 0;
}