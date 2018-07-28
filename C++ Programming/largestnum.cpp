#include <bits/stdc++.h>
using namespace std;

bool comparefun(string a,string b){
    string s1,s2,s3;
    s3 = a;
    s1 = a.append(b);
    s2 = b.append(s3);
    if(stoi(s1)>stoi(s2)){
        return 1;
    }
    else return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n,comparefun);
        for(int i=0;i<n;i++)
            cout << a[i] ;
        cout << "\n";
    }
    return 0;
}