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

char lower_case(char ch){
	return tolower(ch,locale());
}

bool same_char(char a,char b){
	if(lower_case(a) == lower_case(b))
		return true;
	return false;
}

bool is_palindrome(string str){
	string::iterator new_end_iterator = remove_if(str.begin(),str.end(),non_letter);
	string rev(str.begin(),new_end_iterator);
	reverse(rev.begin(),rev.end());
	if(not rev.empty() and equal(str.begin(),new_end_iterator,rev.begin(),same_char))
		return true;
	return false;
}

int main(void){
	locale::global(locale(""));
	initialize_streams();
	string palin;
	getline(cin,palin);
	if(is_palindrome(palin))
		cout << "\"" << palin << "\" is a palindrome\n";
	else 
		cout << "\"" << palin << "\" is not a palindrome";
	return 0;
}