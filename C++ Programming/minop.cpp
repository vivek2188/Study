#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==0 || n==1 || n==2)
            cout << n << "\n";
        else{
            int cnt = 2;
            int j = n;
            while(j>2){
                if(j%2){
                    j--;
                    cnt++;
                }
                else{
                    j /=2;
                    cnt +=1;
                }
            }
            cout << cnt <<  "\n";
        }
    }
}