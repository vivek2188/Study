#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
using namespace std;

#define MAX_VAL 100
int allocated[MAX_VAL][MAX_VAL];	// Already allocated resources to the processes
int required[MAX_VAL][MAX_VAL];		// Total maximum requirement for each process
int available[MAX_VAL];				// Total number of instances of each resource
bool finish[MAX_VAL];				// Maintains the array which keeps track of process has finished or not

void backtrack(int n,int m){
	
}

int main(void){
	// Input
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