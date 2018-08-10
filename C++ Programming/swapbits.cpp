#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    unsigned int i = 2 * (pow(4,16)-1) / 3;
    cin >> t;
    while(t--){
        unsigned int n,m,p;
        cin >> n;
        m = (i&(n<<1));
        p = ((i/2)&(n>>1));
        cout << (m|p) << "\n";
    }
}