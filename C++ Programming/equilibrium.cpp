#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        a[0] = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            a[i] += a[i-1];
        }
        if(n==1)
            cout << 1 << "\n";
        else{
            int i;
            for(i=2;i<n;i++){
                if(a[i-1]==a[n]-a[i]){
                    cout << i << "\n";
                    break;
                }
            }
            if(i==n)
                cout << -1 << "\n";
        }
    }
    return 0;
}