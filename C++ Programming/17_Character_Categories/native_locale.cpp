#include <iostream>
#include <istream>
#include <ostream>
#include <locale>
#include <map>
#include <vector>
using namespace std;

int main(void){
	// Native locale
	cout.imbue(locale(""));
	// Initiailising the required values
	int sum = 0;
	int x;
	//int i=0;
	while(cin >> x /*and (i++ != 5)*/){
		sum += x;
	}
	// Printing the sum
	cout << "Sum: " << sum << "\n";
	return 0;
}