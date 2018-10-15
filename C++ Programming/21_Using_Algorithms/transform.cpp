#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int twice(int a){
	return 2*a;
} 

int main(void){
	vector<int> data;
	// Input
	data.insert(data.begin(),istream_iterator<int>(cin),istream_iterator<int>());
	// Transform by multiplying each element by 2
	transform(data.begin(),data.end(),data.begin(),twice);
	// Print the vector
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
	cout << "\n";
	return 0;
}
