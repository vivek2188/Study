#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int set1[n],set2[n];
        for(int i=0;i<n;i++)
            cin >> set1[i];
        for(int i=0;i<n;i++)
            cin >> set2[i];
        sort(set1,set1+n);
        sort(set2,set2+n);
        int prod = 0;
        for(int i=0;i<n;i++)
            prod += set1[i] * set2[n-i-1];
        cout << prod << "\n";
    }
}