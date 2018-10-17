#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <locale>
#include <string>
#include <iomanip>
using namespace std;

typedef map<string,int> count_map;
typedef count_map::iterator count_iter;
typedef string::size_type str_size;

void initilalize_streams(locale native){
	cin.imbue(native);
	cout.imbue(native);
}

str_size get_longest_key(count_map counts){
	str_size longest_key = 0;
	for(count_iter it=counts.begin();it!=counts.end();++it)
		if(longest_key < it->first.size())
			longest_key = it->first.size();
	return longest_key;
}

void print_counts(count_map counts){
	str_size longest_key = get_longest_key(counts);
	const int max_size = 10;
	for(count_iter it=counts.begin();it!=counts.end();++it)
		cout << setw(longest_key) << it->first
			 << setw(max_size) << it->second << "\n";
}

string sanitize(string str,locale native){
	string result;
	for(string::iterator w=str.begin();w!=str.end();++w)
		if(isalnum(*w,native))
			result.push_back(tolower(*w,native));
	return result;
}

int main(void){
	locale native = locale("");
	initilalize_streams(native);
	string word;
	count_map counts;
	while(cin >> word){
		string copy = sanitize(word,native);
		if(not copy.empty())
			++counts[copy];
	}
	print_counts(counts);
	return 0;
}