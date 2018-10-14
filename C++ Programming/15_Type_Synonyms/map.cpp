#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

typedef map<string,int> count_map;
typedef count_map::iterator count_iter;
typedef string::size_type str_size;

int main(void){
	count_map counts;
	string word;
	while(cin >> word)
		++counts[word];
	str_size longest_word_size = 0;
	for(count_iter iter=counts.begin();iter!=counts.end();iter++){
		str_size word_size = iter->first.size();
		if(longest_word_size < word_size)
			longest_word_size = word_size;
	} 
	const int max_count_size = 10;
	// Printing the map
	cout << "Content of the map stored:\n";
	for(count_iter iter=counts.begin();iter!=counts.end();iter++){
		cout << setw(longest_word_size) << left << iter->first
			 << setw(max_count_size) << right << iter->second << "\n";
	}
	string find_word = "the";
	if(counts.find(find_word)==counts.end())
		cout << "\"" << find_word << "\" not found\n";
	else cout << "Count of \"" << find_word << "\" is: " << counts[find_word] << "\n";
	return 0;
}
