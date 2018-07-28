#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int p,int r){
    int pivot = a[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(a[j]<pivot){
            i = i+1;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

int qsort(int a[],int p,int r,int k){
    if(p<=r){
        if(p==r)
            return a[k];
        int q = partition(a,p,r);
        if(q==k)
            return a[q];
        else if(q>k)
            return qsort(a,p,q-1,k);
        else return qsort(a,q+1,r,k);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        a[0] = 0;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        int k ;
        cin >> k;
        cout << qsort(a,1,n,k) << "\n";
    }
    return 0;
}