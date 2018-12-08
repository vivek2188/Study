// An simple agent that calculates the square root of a given number.

#include <iostream>
#include <istream>
#include <ostream>
#include <algorithm>
using namespace std;

float precept(){
	float input;
	cout << "Input: ";
	cin >> input;
	return input;
}

// Uses Newton's Method
float sqaure_root_function(float x){
	float z = 1.0;
	while(abs(z*z-x) > 1e-15){
		z = z - (z*z - x) / (2 * z);
	}
	return z;
}

int main(void){
	// Agent precepts from its environment
	float x = precept();
	// The action performed by it.
	float action = sqaure_root_function(x);
	printf("Output: %.15f\n",action);
	return 0;
}