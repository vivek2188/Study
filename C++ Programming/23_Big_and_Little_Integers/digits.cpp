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

	cout << "Bits for long: ";
	if(numeric_limits<long>::is_signed)
		cout << numeric_limits<long>::digits + 1 << "\n";
	else cout << numeric_limits<long>::digits << "\n";

	cout << "Bits for long long: ";
	if(numeric_limits<long long>::is_signed)
		cout << numeric_limits<long long>::digits + 1 << "\n";
	else cout << numeric_limits<long long>::digits << "\n";

	cout << "Bits for short: ";
	if(numeric_limits<short>::is_signed)
		cout << numeric_limits<short>::digits + 1 << "\n";
	else cout << numeric_limits<short>::digits << "\n";
	return 0;
}