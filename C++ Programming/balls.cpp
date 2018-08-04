#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        int path1,path2;
        path1 = path2 = 0;
        int i,j;
        i=j=0;
        while(i<n and j<m){
            if(a[i]<b[j]){
                path1 += a[i];
                i++;
            }
            else if(a[i]>b[j]){
                path2 += b[j];
                j++;
            }
            else{
                path1 += a[i];
                path2 += b[j];
                if(path1<path2)
                    path1 = path2;
                else path2 = path1;
                i++;
                j++;
            }
        }
        if(a[i-1]==b[j-1]){
            if(path1<path2)
                path1 = path2;
            else path2 = path1;
        }
        while(i<n){
            path1+=a[i];
            i++;
        }
        while(j<m){
            path2 += b[j];
            j++;
        }
        if(path1>path2)
            cout << path1 << " ";
        else cout << path2 << " ";
    }
    return 0;
}