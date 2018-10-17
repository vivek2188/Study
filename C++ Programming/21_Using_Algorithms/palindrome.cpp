#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <locale>
#include <algorithm>
using namespace std;

void initialize_streams(){
	cin.imbue(locale());
	cout.imbue(locale());
}

bool non_letter(char ch){
	if(isalnum(ch,locale()))
		return false;
	return true;
}

bool is_palindrome(string str){
	string::iterator new_end_iterator = remove_if(str.begin(),str.end(),non_letter);
	string rev(str.begin(),new_end_iterator);
	reverse(rev.begin(),rev.end());
	cout << "Rev: " << rev << "\n";
	return false;
}

int main(void){
	locale::global(locale(""));
	initialize_streams();
	string palin = "Hi, How you doing?";
	is_palindrome(palin);
	return 0;
}