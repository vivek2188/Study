#include <bits/stdc++.h>
using namespace std;

int getbits(int n){
    int cnt = 0;
    while(n>0){
        cnt ++;
        n = n - (n&-n);
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int count = 0;
        for(int i=1;i<=n;i++){
            count += getbits(i);
        }
        cout << count << "\n";
    }
}