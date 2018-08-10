#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if((n>>k)&1)
            cout << n << "\n";
        else cout << n + (1<<k) << "\n";
    }
    return 0;
}