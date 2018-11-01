#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
	int buffer_size;
	cout << "Buffer size: ";
	cin >> buffer_size;
	unordered_map<int,bool> mp;
	int i;
	queue<int> buffer;
	int page_fault=0;
	int k;
	cout << "Total number of pages: ";
	cin >> k;
	cout << "Pages are: ";
	while(k--){
		cin >> i;
		if(buffer.size()<buffer_size){
			if(mp.find(i)!=mp.end())
				continue;
			page_fault++;
			mp[i] = true;
			buffer.push(i);
		}
		else{
			if(mp.find(i)!=mp.end())
				continue;
			page_fault++;
			mp[i] = true;
			mp.erase(buffer.front());
			buffer.pop();
			buffer.push(i);
		}
	}
	cout << "Total number of page faults: " << page_fault << "\n";
	return 0;
}
