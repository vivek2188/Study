#include <iostream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;

int predict(vector<int> buffer,int pages[],int j,int n){
	int p = 0;
	for(int i=j;i<n and buffer.size()>1;i++){
		vector<int>::iterator it = find(buffer.begin(),buffer.end(),pages[i]);
		if(it!=buffer.end())
			buffer.erase(it);
	}
	return buffer[0];
}

int main(void){
	int buffer_size;
	cout << "Buffer size: ";
	cin >> buffer_size;
	int k,i;
	cout << "Total number of pages: ";
	cin >> k;
	int page_fault = 0;
	vector<int> buffer;
	int pages[k];
	cout << "Pages are: ";
	for(int i=0;i<k;i++)
		cin >> pages[i];
	int j =0;
	while(j<k){
		i = pages[j];
		if(buffer.size()<buffer_size){
			if(find(buffer.begin(),buffer.end(),i)==buffer.end()){
				page_fault++;
				buffer.push_back(i);
			}
		}
		else if(find(buffer.begin(),buffer.end(),i)==buffer.end()){
			int l = predict(buffer,pages,j,k);
			page_fault++;
			buffer[find(buffer.begin(),buffer.end(),l)-buffer.begin()] = i;
		}
		j++;
	}
	cout << "Total number of Page Faults: " << page_fault << "\n";
	return 0;
}
