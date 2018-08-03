#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s; 
        if(s>n*9 || s<=0) cout << -1 << "\n";
        else{
            int dig = 0,max = 9;
            while(dig<n){
                while(s<max)
                    max--;
                cout << max ;
                s -= max;
                dig++;
            }
        }
        cout << "\n";
    }
}