#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i] = n*a[i];
	int k = 1;
	for(int j=k;j<n;j++){
		for(int i=0;i<n-k;i++)
			dp[i][i+j] = max(a[i]*(n-j)+dp[i+1][i+j],a[i+j]*(n-j)+dp[i][i+j-1]);
		k++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
}