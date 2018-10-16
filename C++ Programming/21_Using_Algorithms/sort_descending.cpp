#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

// Predicate function
bool compare(int a,int b){
	if(a>b)
		return false;
	return true;
}

int main(void){
	vector<int> data;
	// Input
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(data));
	// Sorting in the descending order
	sort(data.begin(),data.end(),compare);
	// Print
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
	cout << "\n";
	return 0;
}
