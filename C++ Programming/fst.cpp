#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int tcomp = -n;
        tcomp = n & tcomp;
        if(n)
            cout << log2(tcomp) + 1 << "\n";
        else cout << 0 << "\n";
    }
}