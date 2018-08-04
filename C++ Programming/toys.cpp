#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        int i = 0;
        int cnt = 0;
        while(cnt+a[i]<k and i<n){
            cnt += a[i];
            i++;
        }
        cout << i << "\n";
    }
}