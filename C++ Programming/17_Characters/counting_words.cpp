#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <locale>
#include <map>
using namespace std;

typedef map<string,int> count_map;
typedef count_map::iterator count_iter;

int main(){
	string word;
	count_map counts;
	while(cin >> word){
		string copy;
		for(string::iterator w=word.begin();w!=word.end();++w){
			if(isalnum(*w,locale("")))
				copy.push_back(*w);
		}
		if(not copy.empty()){
			cout << copy << "\n";
			++counts[copy];
		}
	}
	// Printing the count map	
	for(count_iter itr=counts.begin();itr!=counts.end();++itr)
		cout << itr->first << "\t" << itr->second << endl;
	return 0;
}
