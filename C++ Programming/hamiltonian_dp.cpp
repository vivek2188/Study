#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    long long int cost[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j] = INT_MAX;
    while(m--){
        int x,y;
        long long int z;
        cin >> x >> y >> z;
        cost[x-1][y-1] = min(cost[x-1][y-1],z);
        cost[y-1][x-1] = min(cost[y-1][x-1],z);
    }
    long long int dp[n][1<<n];
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++)
            dp[j][i] = INT_MAX;
    }
    for(int i=0;i<n;i++)    
        dp[i][1<<i] = 0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=0;k<n;k++){
                    if(j!=k and i&(1<<k))
                        dp[j][i] = min(dp[j][i],cost[k][j]+dp[k][i^(1<<j)]);
                }
            }
        }
    }
    long long int ans = INT_MAX;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[i][(1<<n)-1]);
    }
    cout << ans << "\n";
}