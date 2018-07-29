#include <bits/stdc++.h>
using namespace std;

int dp[101][101] = {0};

void edit_distance(string s1,string s2,int n,int m){
    for(int i=1;i<=n;i++)
        dp[0][i] = i;
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s2[i-1]==s1[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
            }
        }
    }
    /*for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1 >> s2;
        memset(dp,0,sizeof(dp));
        edit_distance(s1,s2,n,m);
        cout << dp[m][n] << "\n";
    }
}