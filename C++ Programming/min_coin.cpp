#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int a[] = {1,2,5,10,20,50,100,500,1000};
    while(t--){
        int s;
        cin >> s;
        int indx = 8;
        while(s>0){
            while(a[indx]<=s){
                cout << a[indx] << " ";
                s -= a[indx];
            }
            indx--;
        }
        cout << "\n";
    }
    return 0;
}