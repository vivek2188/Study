#include <iostream>
#include <string>
using namespace std;

void compute_prefix_function(int *prefix,string pattern){
	int m = pattern.length();
	// For simplicity
	pattern = '#' + pattern;
	int k = 0;
	for(int i=2;i<=m;i++){
		while(k>0 and pattern[k+1]!=pattern[i])
			k = prefix[k];
		if(pattern[k+1]==pattern[i])
			k = k+1;
		prefix[i] = k;
	}	
}

void kmp_matcher(string text,string pattern){
	int n = text.length();
	int m = pattern.length();
	// Preprocessing stage
	int prefix[m+1] = {0};
	compute_prefix_function(prefix,pattern);
	// Print prefix
	cout << "Prefix value: ";
	for(int i=1;i<=m;i++)
		cout << prefix[i] << " ";
	cout << "\n";
}

int main(){
	string text, pattern;
	cout << "Enter text: ";
	cin >> text;
	cout << "Enter pattern: ";
	cin >> pattern;
	kmp_matcher(text,pattern);
	return 0;
}
