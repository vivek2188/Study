#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> data;
	// Taken the input from the stdin and insert to the vector data
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(data));
	// Sort the data
	sort(data.begin(),data.end());
	// Output data to stdout
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
}
