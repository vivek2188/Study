#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        m ^=n;
        int count = 0;
        while(m>0){
            count ++;
            m = m - (m & -m);
        }
        cout << count << "\n";
    }
    return 0;
}