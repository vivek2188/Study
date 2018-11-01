#include <iostream>
#include <istream>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;

int predict(vector<int> buffer,int pages[],int j){
	int n = sizeof(pages)/sizeof(pages[0]);
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
	cin >> buffer_size;
	int k,i;
	cin >> k;
	int page_fault = 0;
	vector<int> buffer;
	int pages[k];
	cout << "Pages: ";
	for(int i=0;i<k;i++)
		cin >> pages[i];
	int j =0;
	while(j++<k){
		i = pages[j-1];
		if(buffer.size()<buffer_size){
			if(find(buffer.begin(),buffer.end(),i)!=buffer.end())
				continue;
				//page_fault++;
			buffer.push_back(i);
		}
		else{
			if(find(buffer.begin(),buffer.end(),i)!=buffer.end())
				continue;
			int l = predict(buffer,pages,j);
			page_fault++;
			buffer[find(buffer.begin(),buffer.end(),l)-buffer.begin()] = i;
		}
	}
	cout << page_fault << "\n";
	return 0;
}
