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
	/// Assign the numerator and denominator, then to reduce to normal form
	/// @param num numerator
	/// @param deno denominator
	void assign(int num,int deno){
		numerator = num;
		denominator = deno;
		reduce();
	}
	/// Reduce the numerator and denominator by their gcd
	void reduce(){
		assert(denominator!=0);
		int div = gcd(numerator,denominator);
		cout << div << "\n";
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;		///< numerator gets the sign of the rational value
	int denominator;	///< denominator is always positive
};

int main(void){
	rational pi;
	pi.numerator = 155;
	pi.denominator = 255;
	pi.reduce();
	cout << "pi is about " << pi.numerator << "/" << pi.denominator << "\n";
	rational new_var;
	new_var.assign(6,24);
	cout << "new_var is about " << new_var.numerator << "/" << new_var.denominator << "\n";
	return 0;
}