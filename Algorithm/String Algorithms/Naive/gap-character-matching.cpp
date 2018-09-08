/*
 Suppose we allow the pattern P to contain occurencs of a gap characters 
 '?' that can match an arbitrary string of chaacters(even of zero length).
 For the pattern ab?ba?c occurs in the text cabccbacbacab. Note that the
 gap character may occur an arbitrary number of times in the pattern but 
 not at all in the text. Give a polynomial time algorithm whether such a 
 pattern P occurs in a given text T, and analyze the running time of your
 algorithm.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string text, pattern;
	cout << "Enter text and pattern: ";
	cin >> text >> pattern;
	int n = text.length();
	int m = pattern.length();
	bool dp[n+1][m+1];
	memset(dp,false,sizeof(dp));
	for(int j=0;j<=n;j++)
		dp[j][0] = true;
	int k=1;
	while(k<=m and pattern[k-1]=='?')
		k++;
	for(int j=1;j<k;j++)
		dp[0][j] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = dp[i-1][j];
			if(pattern[j-1]!='?'){
				if(text[i-1]==pattern[j-1])
					dp[i][j] |= dp[i-1][j-1];
			}
			else{
				dp[i][j] |= dp[i][j-1];
			}
		}
	}
	if(dp[n][m])
		cout << "Pattern found\n";
	else cout << "Pattern does not exist\n";
	return 0;
}
