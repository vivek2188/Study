#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int val[n] = {0};
        val[0] = 1;
        for(int i=1;i<n;i++){
            int mx = -1;
            for(int j=0;j<i;j++){
                if(a[j]<a[i])
                mx = max(mx,val[j]);
            }
            if(mx!=-1)
            val[i] = mx +1;
            else val[i]=1;
        }
        int mx = -1;
        for(int i=0;i<n;i++)
            mx = max(mx,val[i]);
        cout << mx << "\n";
    }
}