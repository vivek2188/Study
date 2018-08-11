#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming with bit masking
/*
	PROBLEM DESCRIPTION: 
		Suppose there are n persons and n tasks, each task is to be assigned to 
		exactly one person. We are also given a cost matrix of size n x n, where 
		every entry(i,j) denotes how much the person i charges for the j task. 
		Now we need to assign the task to the persons such that cost is minimum.
*/

int effexp(int a,int n){
	int res = 1;
	int x = a;
	while(n>0){
		if(n&1)
			res = res * x;
		x = x * x;
		n = n >> 1; 
	}
	return res;
}

int count_setbits(int n){
	int count = 0;
	while(n>0){
		count ++;
		n = n - (n&-n);
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	int cost[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin >> cost[i][j];
	}
	int exp = effexp(2,n);
	int dp[exp];
	memset(dp,INT_MAX,sizeof(dp));
	dp[0] = 0;
	for(int i=0;i<exp;i++){
		int x = count_setbits(i);
		for(int j=0;j<n;j++){
			if(((n>>j)&1)==0)
				dp[i|(1<<j)] = min(dp[i|(1<<j)],dp[i]+cost[x][j]);
		}
	}
	cout << dp[exp-1] << "\n";
	return 0;
}