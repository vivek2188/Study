#include <iostream>
#include <ostream>
#include <iomanip>
//#include <ios> provides left and right for alignment purpose
using namespace std;

int main(void){
	// Printing the sqaures and cubes for first 10 natural numbers
	cout << setw(2) << "N" << setw(4) << "N^2" << setw(5) << "N^3" << "\n";
	for(int i=1;i<=10;i++)
		cout << setw(2) << i  << setw(4) << i*i << setw(5) << i*i*i << "\n"; 
	return 0;
}
// cout << setfill(ch), for the filling out the black spaces
