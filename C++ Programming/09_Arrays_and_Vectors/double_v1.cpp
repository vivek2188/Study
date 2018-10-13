#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> data;
	int x;
	while(cin >> x)
		data.push_back(x);
	// Double each element
	for(vector<int>::size_type i=0;i<data.size();i++)
		data.at(i) *=2;
	// Print the vector
	for(vector<int>::iterator it=data.begin();it!=data.end();it++)
		cout << *it << " ";
	cout << "\n";
}
