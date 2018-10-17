#include <locale>
#include <string>
#include <algorithm>
using namespace std;

bool non_letter(char ch){
	if(isalnum(ch,locale()))
		return false;
	return true;
}

char lower_case(char ch){
	return tolower(ch,locale());
}

string sanitize(string word){
	// remove_if returns the valid end iterator 
	word.erase(remove_if(word.begin(),word.end(),non_letter),word.end());
	transform(word.begin(),word.end(),word.begin(),lower_case);
}