// Subset Sum Problem
#include <iostream>
#include <istream>
#include <ostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	cout << "Set size: ";
	cin >> n;
	vector<int> s;
	for(int i=1;i<=n;i++){
		int j;
		cin >> j;
		s.push_back(j);
	}
	set<int> sum;
	sum.insert(0);
	int t;
	cout << "Required sum: ";
	cin >> t;
	for(int i=1;i<=n;i++){
		vector<int> temp_sum;
		for(set<int>::iterator itr=sum.begin();itr!=sum.end();itr++){
			int element = *itr + s[i-1];
			temp_sum.push_back(element);
		}
		for(int j=0;j<temp_sum.size();j++)
			sum.insert(temp_sum[j]);
	}
	if(find(sum.begin(),sum.end(),t) != sum.end())
		cout << "There exists a subset whose sum is " << t << "\n";
	else
		cout << "There is no subset whose sum is " << t << "\n";
	return 0;
}