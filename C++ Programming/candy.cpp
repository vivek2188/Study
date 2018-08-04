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
        int i,j;
        i=0;
        j=n-1;
        int minp,maxp;
        minp = maxp = 0;
        while(j>i){
            minp += a[i];
            i++;
            j-=k;
        }
        if(i<n and j==i)
        minp += a[i];
        cout << minp << " ";
        i = 0;
        j = n-1;
        while(j>i){
            maxp += a[j];
            j--;
            i+=k;
        }
        if(j>=0 and i==j)
            maxp += a[j];
        cout << maxp <<  "\n";
    }
}