/*
 Suppose that all characters in the pattern P are different. Show how to 
 accelerate naive string matching algorithm to run in O(n) on an 
 n-character text T.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	string text, pattern;
	cout << "Enter text and pattern: ";
	cin >> text >> pattern;
	int n = text.length();
	int m = pattern.length();
	if(m>n){
		cout << "Error\n";
		exit(true);	
	}
	// ALgorithm for pattern with distinct characters - O(n)
	text = "#" + text;
	for(int s=0;s<=n-m;){	
		int i=1;
		while(i<=m and text[s+i]==pattern[i-1])
			i++;
		if(i==m+1)
			cout << "Pattern occurs with shift " << s << "\n";
		if(i==1)
			s = s+1;
		else 
			s = s+i-1;
	}
	return 0;
}
