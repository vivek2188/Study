#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
using namespace std;

#define MAX_VAL 100
int allocated[MAX_VAL][MAX_VAL];
int required[MAX_VAL][MAX_VAL];
int available[MAX_VAL];

int main(void){
	int n,m;
	cout << "Number of processes: ";
	cin >> n;
	cout << "Number of resources: ";
	cin >> m;
	cout << "Enter the allocated resource matrix\n";
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin >> allocated[i][j];
	cout << "Enter the max required matrix\n";
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin >> required[i][j];
	cout << "Total number of resources: ";
	for(int i=0;i<m;i++)
		cin >> available[i];
	cout << "Running the banker's algorithm...\n";
	backtrack(n,m);
	return 0;
}