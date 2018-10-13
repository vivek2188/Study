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
	// Printing the trasformed vector
	for(vector<int>::size_type i=0;i<data.size();i++)
		cout << data.at(i) << " ";
	cout << "\n";
}
