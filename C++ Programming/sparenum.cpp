#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&(n>>1))
            cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}