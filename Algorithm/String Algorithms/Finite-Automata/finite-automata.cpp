#include <iostream>
#include <string>
#include <utility>
#include <map>
using namespace std;

void finite_automata_matcher(string T,map<pair<int,char>,int>transition,int m,int z){
	/*
	  Arguments: 
		string T 		            Input Text String
		map<pair<int,char>,int> transition  It is the transition function for the automata
						    which map from STATE x CHARACTER to STATE 
		int m				    Length of the pattern
		int z				    Size of the alphabet
	*/
	int n = T.length();
	int q = 0;		// Initial state
	for(int i=0;i<n;i++){
		q = transition[make_pair(q,T[i])];
		if(q==m)
			cout << "Pattern occurs at shift" << i-m+1 << "\n";
	}
}

int main(){
	string text, pattern;
	cout << "Enter Text and Pattern: ";
	cin >> text >> pattern;
	int alphabet_size;
	cout << "Size of the alphabet: ";
	cin >> alphabet_size;
	return 0;
}
