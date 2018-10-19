#include <iostream>
#include <ostream>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <ios>
#include <limits>
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
	rational(double r): numerator(static_cast<int>(r*10000)),denominator(10000){
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
	/// Converting to floating point types
	float as_float(rational const& a){
		return static_cast<float>(a.numerator) / a.denominator;
	}
	double as_double(rational const& a){
		return static_cast<double>(a.numerator) / a.denominator;
	}
	long double as_long_double(rational const& a){
		return static_cast<long double>(a.numerator) / a.denominator;
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
	/// Assignment operator
	rational& operator=(rational const& r){
		this->numerator = r.numerator;
		this->denominator = r.denominator;
		return *this;
	}
	/// Assignment operator with int on RHS
	rational& operator=(int a){
		this->numerator = a;
		this->denominator = 1;
		return *this;
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
/// Optimizing for single specific type
rational operator*(rational const& a,int b){
	return rational(a.numerator*b,a.denominator);
}
inline rational operator*(int b,rational const& a){
	return a*b;
}
/// Computing the absolute value
rational absval(rational const& a){
	return rational(abs(a.numerator),a.denominator);
}
/// Output operator
ostream& operator<<(ostream& out,rational const& r){	// don't miss & in return type
	ostringstream temp;		// ostringstream is defined in the "sstream" header file
	temp << r.numerator;
	if(r.denominator!=1)
		temp << '/' << r.denominator;
	out << temp.str();
	return out;
}
/// Input operator
istream& operator>>(istream& in,rational& r){
	int n,d;
	char sep;
	if(not(in >> n >> sep))
		in.setstate(cin.failbit);
	else if(sep!='/'){
		in.unget();
		r.assign(n,1);
	}
	else if(in >> d)
		r.assign(n,d);
	else 
		in.setstate(cin.failbit);
	return in;
}
/// Test for failbit
bool iofailure(istream& in){
	return in.fail() and not in.bad();
}

int main(void){
	rational r(0);
	while(cin){
		if(cin >> r){
			cout << "r is about: " << r << endl;
		}
		else if(iofailure(cin)){
			cout << "Error detected\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(),'\n');
		}
		if(cin.bad()){
			cerr << "Unrecoverable error\n";
			break;
		}
	}
	return 0;
}