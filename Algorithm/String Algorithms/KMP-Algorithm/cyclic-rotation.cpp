/*
	Give a linear-time algorithm to determine whether a text T is a
        cyclic rotation of another string T'. For example, arc and car are
        cyclic rotations of each other.
*/
#include <iostream>
#include <string>
using namespace std;

void compute_prefix_function(int *prefix,string pattern){
	int m = pattern.length();
	// For simplicity
	pattern = '#' + pattern;
	// Computing Prefix array
	int k = 0;
	for(int i=2;i<=m;i++){
		while(k>0 and pattern[k+1]!=pattern[i])
			k = prefix[k];
		if(pattern[k+1]==pattern[i])
			k = k+1;
		prefix[i] = k;
	}	
}

bool cyclic_rotation(string text,string pattern){
	int n = text.length();
	int m = pattern.length();
	// Preprocessing stage
	int prefix[m+1] = {0};
	compute_prefix_function(prefix,pattern);
	//For simplicity
	pattern = '#' + pattern;
	text = '#' + text;
	int s = 0;
	for(int i=1;i<=n;i++){
		while(s>0 and pattern[s+1]!=text[i])
			s = prefix[s];
		if(pattern[s+1]==text[i])
			s = s+1;
		if(s==m)
			return true;
	}
	return false;
}

int main(){
	string t0, t1;
	cout << "String 1: ";
	cin >> t0;
	cout << "String 2: ";
	cin >> t1;
	string newString;	
	newString = t0 + t0;
	bool flag = cyclic_rotation(newString,t1);
	if(flag)
		cout << "String " << t0 << " is a cyclic rotation of " << t1 << "\n";
	else cout << "String " << t0 << " is not a cyclic rotation of " << t1 << "\n";
	return 0;
}
