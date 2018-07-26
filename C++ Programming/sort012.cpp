#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int cnt[3] = {0};
        for(int i=0;i<n;i++){
            cin >>a[i];
            if(a[i]==0)
                cnt[a[i]]++;
            else if(a[i]==1) 
                cnt[a[i]]++;
            else cnt[a[i]]++;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<cnt[i];j++)
                cout << i <<  " ";
        }
        cout << "\n";
    }
    return 0;
}