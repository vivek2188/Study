#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x,y,z;
        cin >> x >> y >> z;
        int mini = min(x,min(y,z));
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<=n;i++)
            dp[i] = -1;
        for(int i=mini;i<=n;i++){
            if(i>=x and dp[i-x]!=-1)
                dp[i] = max(dp[i],dp[i-x]+1);
            if(i>=y and dp[i-y]!=-1)
                dp[i] = max(dp[i],dp[i-y]+1);
            if(i>=z and dp[i-z]!=-1)
                dp[i] = max(dp[i],dp[i-z]+1);
        }
        cout << dp[n] << "\n";
    }
}