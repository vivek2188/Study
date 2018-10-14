#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
using namespace std;

int main(void){
	map<string,int> mp;
	string word;
	// Count the occurence of each word
	while(cin >> word)
		++mp[word];
	int longest_word_size = 0;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		int word_size = it->first.size();
		if(longest_word_size < word_size)
			longest_word_size = word_size;
	} 
	const int max_count_size = 10;
	// Printing the map
	cout << "Content of the map stored:\n";
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		cout << setw(longest_word_size) << left << it->first
			 << setw(max_count_size) << right << it->second << "\n";
	}
	return 0;
}
