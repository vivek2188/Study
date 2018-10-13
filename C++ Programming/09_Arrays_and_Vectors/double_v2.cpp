#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void){
	vector<int> data;
	// Input
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(data));
	// Double each element
	for(vector<int>::iterator it=data.begin();it!=data.end();++it)
		*it *= 2;
	// Print to console
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
	return 0;
}
