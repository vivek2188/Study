#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int count = 0;
        int ans[n];
        for(int i=0;i<n;i++)
            ans[i] = INT_MAX;
        count = 0;
        ans[0] = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<=i+a[i] and j<n;j++)
                ans[j] = min(ans[j],ans[i]+1);
        }
        if(a[0] and ans[n-1]!=INT_MAX)
            cout << ans[n-1] << "\n";
        else cout << -1 << "\n";
    }
    
}