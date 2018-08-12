// Problem Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

set<string>set1;
void permute(string &s,int l,int r){
    if(l==r)
        set1.insert(s);
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        permute(s,l+1,r);
        swap(s[l],s[i]);
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        //cout << s << "  ";
        permute(s,0,s.size()-1);
        for(auto it=set1.begin();it!=set1.end();it++)
            cout << *it << " ";
        cout << "\n";
    }
}
