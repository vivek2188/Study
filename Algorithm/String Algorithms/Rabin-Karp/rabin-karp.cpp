#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void rabin_karp_string_matcher(string T,string P,int q){
	int n = T.length();
	int m = P.length();
	int d = 10;	      // Assuming string is in radix-10 notation
	if(m>n){
		cout << "Error\n";
		exit(true);
	}
	T = "#" + T;
	P = "#" + P;
	// Preprocessing
	int t,p;
	t = p = 0;
	for(int i=1;i<=m;i++){
		p = (p*d + P[i]-'0') % q;
		t = (t*d + T[i]-'0') % q;
	}
	//Algorithm
	int h = pow(d,m-1);	// h = d^(m-1)
	int spurious_hits = 0;
	int compute[n-m+1];
	compute[0] = t;
	for(int s=0;s<=n-m;s++){
		if(t==p){
			int i=1;
			while(T[s+i]==P[i])
				i++;
			if(i==m+1)
				cout << "Pattern occurs with shift " << s << "\n";
			else spurious_hits++;
		}
		if(s<n-m){
			t = (d * (t - (T[s+1]-'0')*h) + T[s+m+1]-'0') % q;
			if(t<0)
				t += q;
			compute[s+1] = t;
		}
	}
	for(int i=0;i<=n-m;i++)
		cout << compute[i] << " ";
	cout << "\n";
	cout << "Number of spurious hits: " << spurious_hits << "\n";
}

int main(){
	string text, pattern;
	cout << "Enter text and pattern: ";
	cin >> text >> pattern;
	int q;
	cout << "Enter the prime number: ";
	cin >> q;
	rabin_karp_string_matcher(text,pattern,q);
	return 0;
}
