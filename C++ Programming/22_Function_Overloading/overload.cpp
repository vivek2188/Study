#include <string>
#include <locale>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

bool is_alpha(char ch){
	if(isalpha(ch,locale()))
		return true;
	return false;
}

bool is_alpha(string const& str){
	for(string::const_iterator w=str.begin();w!=str.end();++w){
		if(is_alpha(*w))
			continue;
		else return false;
	}
	return true;
}

char to_lower(char ch){
	return tolower(ch,locale());
}

string to_lower(string str){
	for(string::iterator w=str.begin();w!=str.end();++w)
		*w = to_lower(*w);
	return str;
}

char to_upper(char ch){
	return toupper(ch,locale());
}

string to_upper(string str){
	for(string::iterator w=str.begin();w!=str.end();++w)
		*w = to_upper(*w);
	return str;
}

int main(void){
	locale::global(locale(""));
	cin.imbue(locale());
	cout.imbue(locale());
	string str;
	while(cin >> str){
		if(is_alpha(str))
			cout << "Alpha\n";
		else cout << "Not Alpha\n";
		cout << "Lower: " << to_lower(str) << "\n"
			 << "Upper: " << to_upper(str) << "\n";
	}
	return 0;
}