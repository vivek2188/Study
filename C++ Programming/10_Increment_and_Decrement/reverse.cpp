#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> data;
	// Input
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(data));
	// Reverse
	for(vector<int>::iterator start=data.begin(),end=data.end();start!=end;){
		end--;
		if(start!=end){
			swap(*start,*end);
			++start;
		}
}
	// Print the reversed vector
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
	cout << "\n";
	return 0;
}
