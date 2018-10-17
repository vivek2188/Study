#include <limits>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

int main(void){
	cout << "Bits for int: ";
	if(numeric_limits<int>::is_signed)
		cout << numeric_limits<int>::digits + 1 << "\n";
	else cout << numeric_limits<int>::digits << "\n";
	cout << "Bits for bool: ";
	if(numeric_limits<bool>::is_signed)
		cout << numeric_limits<bool>::digits + 1 << "\n";
	else cout << numeric_limits<bool>::digits << "\n";
	return 0;
}