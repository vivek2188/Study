#include <iostream>
#include <ostream>
using namespace std;

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