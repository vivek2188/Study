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
	/// Constructor for the rational datatype
	/// @param num numerator
	/// @param deno denominator
	/// @pre denominator > 0
	rational(int num,int deno): numerator(num),denominator(deno){
		reduce();
	}
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
		if(denominator<0){
			numerator = -numerator;
			denominator = -denominator;
		}
		int div = gcd(numerator,denominator);
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;		///< numerator gets the sign of the rational value
	int denominator;	///< denominator is always positive
};

int main(void){
	rational new_var(13,-39);
	cout << "new_var is about " << new_var.numerator << "/" << new_var.denominator << "\n";
	return 0;
}