#include <iostream>
#include <ostream>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include "test.hpp"
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
	/// COnstructor with single parameter
	/// @param num numerator
	rational(int num): numerator(num),denominator(1){}
	/// COnstructor for a floating point argument
	rational(double r): numerator(static_cast<int>(r*10000),denominator(10000)){
		reduce();
	}
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
/// Compare two rational number for equality
/// @pre @p a and @p b are reduced to normal form
bool operator==(rational const& a,rational const& b){
	return a.numerator == b.numerator and a.denominator == b.denominator;
}
/// Compare two rational number for inequality
/// @pre @p a and @p b reduced to normal form
inline bool operator!=(rational const& a,rational const& b){
	return not(a==b);
}
/// Compare two rational number for less-than
bool operator<(rational const& a,rational const& b){
	return a.numerator * b.denominator < a.denominator * b.numerator;
}
/// Compare two rational number for less-than-or-equal
inline bool operator<=(rational const& a,rational const& b){
	return not (b<a);
}
/// Compare two rational number for greater-than
inline bool operator>(rational const& a,rational const& b){
	return b<a;
}
/// Compare two rational number for greater-than-or-equal
inline bool operator>=(rational const& a,rational const& b){
	return not (b>a);
}
/// Adding of two rational numbers
rational operator+(rational const& a,rational const& b){
	cout << a.numerator << " " << a.denominator << "\n"
	     << b.numerator << " " << b.denominator << "\n";
	return rational(a.numerator*b.denominator+b.numerator*a.denominator,a.denominator*b.denominator);
}
/// Negating a rational number
rational operator-(rational const& a){
	return rational(-a.numerator,a.denominator);
}
/// Subtracting two rational numbers
rational operator-(rational const& a,rational const& b){
	return a + (-b);
}
/// Multiplying two rational numbers
rational operator*(rational const& a,rational const& b){
	return rational(a.numerator*b.numerator,a.denominator*b.denominator);
}
/// Dividing two rational numbers
rational operator/(rational const& a,rational const& b){
	return rational(a.numerator*b.denominator,a.denominator*b.numerator);
}

int main(void){
	rational new_var(13,-39);
	rational new_var_2(5);
	cout << "new_var is about " << new_var.numerator << "/" << new_var.denominator << "\n";
	rational a(60,5);
	rational b(12);
	rational c(-24,-2);
	rational d = a-b;
	cout << "d is about " << d.numerator << "/" << d.denominator << "\n"; 
	return 0;
}