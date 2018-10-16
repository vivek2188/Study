#include <iostream>
#include <istream>
#include <ostream>
#include <locale>
#include <string>
#include <vector>
#include <map> 
using namespace std;

typedef map<string,int> count_map;
typedef count_map::iterator count_iter;
typedef string::size_type str_size;

int main(void){
	// Native locale
	locale native = locale("");
	cin.imbue(native);
	cout.imbue(native);
	count_map counts;
	string word;
	while(cin >> word){
		string copy;
		for(string::iterator itr=word.begin();itr!=word.end();itr++){
			if(isalnum(*itr,native))
				copy.push_back(*itr);
		}
		if(not copy.empty()){
			++counts[copy];
			cout << copy << "\n";
		}
	}
	// Printing out the map
	for(count_iter itr=counts.begin();itr!=counts.end();++itr)
		cout << itr->first << "\t" << itr->second << "\n";
	return 0;
}