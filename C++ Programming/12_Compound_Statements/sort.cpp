#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void){
	vector<int> data;
	// Input
	data.insert(data.end(),istream_iterator<int>(cin),istream_iterator<int>());
	// Sort
	for(vector<int>::iterator iter=data.begin();iter!=data.end();++iter){
		int value = *iter;
		vector<int>::iterator here, position;
		position = lower_bound(data.begin(),iter,value);
		iter = data.erase(iter);
		data.insert(position,value);
	}
	// Print
	copy(data.begin(),data.end(),ostream_iterator<int>(cout,", "));
	return 0;
}
