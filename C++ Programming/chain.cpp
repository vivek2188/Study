#include <bits/stdc++.h>
using namespace std;

struct val{
    int first,second;
};

bool comp(struct val v1,struct val v2){
    if(v1.first<v2.first)
        return true;
    return false;
}

int maxChainLen(struct val p[],int n){
    int count = 1;
    sort(p,p+n,comp);
    int start = p[n-1].first;
    for(int i=n-2;i>=0;i--){
        if(p[i].second<start){
            count++;
            start = p[i].first;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        val p[n];
        for(int i=0;i<n;i++)
            cin >> p[i].first >> p[i].second;
        cout << maxchainLen(p,n);
    }
    return 0;
}