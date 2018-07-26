#include <bits/stdc++.h>
using namespace std;

int find(int a[],int p,int r){
    if(p<=r){
        if(p==r and a[p]==p)
            return p+1;
        else if(p==r and a[p]>p)
            return p;
        int q = (p+r)/2;
        if(a[q]==q)
            return find(a,q+1,r);
        else return find(a,p,q);
            
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        a[0] = 0 ;
        for(int i=1;i<n;i++)
            cin >> a[i];
        sort(a+1,a+n);
        cout << find(a,1,n-1) << "\n";       
    }
}