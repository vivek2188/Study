#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> data;
	data.insert(data.begin(),istream_iterator<int>(cin),istream_iterator<int>());
	vector<int>::iterator it = find(data.begin(),data.end(),0);
	vector<int> copy_vec(it,data.end());
	copy(copy_vec.begin(),copy_vec.end(),ostream_iterator<int>(cout," "));
	cout << "\n";
	return 0;
}