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
	sort(data.begin(),data.end());
	// Print the vector
	for(vector<int>::iterator it=data.begin();it!=data.end();it++)
		cout << *it << " ";
	return 0;
}
