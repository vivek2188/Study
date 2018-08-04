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
        int f=0;
        unordered_set<int>s;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(s.size()<k){
                if(s.find(a[i])==s.end()){
                    s.insert(a[i]);
                    f+=1;
                }
                mp[a[i]] = i;
            }
            else{
                if(s.find(a[i])==s.end()){
                    int lru = INT_MAX;
                    unordered_set<int>::iterator val;
                    for(auto it=s.begin();it!=s.end();it++){
                        if(lru>mp[*it]){
                            lru = mp[*it];
                            val = it;
                        }
                    }
                    s.erase(val);
                    s.insert(a[i]);
                    f++;
                }
                mp[a[i]] = i;
            }
        }
        cout << f << "\n";
    }
}