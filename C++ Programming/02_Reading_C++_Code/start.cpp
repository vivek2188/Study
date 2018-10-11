#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
using namespace std;

int main(void){
	int min(numeric_limits<int>::max());
	int max(numeric_limits<int>::min());
	bool entered = false;
	// Getting user input
	int x;
	while(cin >> x){
		entered = true;
		if(x<min)
			min = x;
		if(x>max)
			max = x;
	}
	if(entered==false)
		cout << "Input not provided\n";
	else
		cout << "Min: " << min << "\n" << "Max: " << max << "\n";
	return 0;
}
