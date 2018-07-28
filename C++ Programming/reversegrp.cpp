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
        int k ;
        cin >> k;
        for(int i=0;i<ceil(n/float(k));i++){
            stack<int>s;
            for(int j=i*k;j<(i+1)*k and j<n;j++)
                s.push(a[j]);
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}