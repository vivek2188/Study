#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int find_coins(int a[],int i,int n,int k){
    if(k==0)
        return 1;
    if(k<0)
        return 0;
    if(i>=n and k>=1)
        return 0;
    if(dp[i][k])
        return dp[i][k];
    dp[i][k] = find_coins(a,i+1,n,k) + find_coins(a,i,n,k-a[i]);
    return dp[i][k];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            cin >> a[i];
        int k;
        cin >> k;
        cout << find_coins(a,0,n,k) << "\n";
    }
}