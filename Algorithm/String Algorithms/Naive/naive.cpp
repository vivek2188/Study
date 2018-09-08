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
	//Algorithm 
	text = "#"  + text;	// text = T[1..n]
	for(int s=0;s<=n-m;s++){
		string str = "";
		for(int i=s+1;i<=s+m;i++)
			str += text[i];
		if(str.compare(pattern)==0)
			cout << "Pattern occurs with shift " << s << "\n";
	}
	return 0;
}
