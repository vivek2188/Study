#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        m = m ^ n;
        cout << log2(m&-m) + 1 << "\n";
    }
}