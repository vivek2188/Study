#include <bits/stdc++.h>
using namespace std;

struct meet{
  int s,e,idx;  
};

bool comp(meet* n1,meet* n2){
    if(n1->e < n2->e)
        return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int start[n],end[n];
        for(int i=0;i<n;i++)
            cin >> start[i];
        for(int i=0;i<n;i++)
            cin >> end[i];
        vector<meet*>v;
        for(int i=0;i<n;i++){
            meet* n = new meet;
            n->s = start[i];
            n->e = end[i];
            n->idx = i+1;
            v.push_back(n);
        }
        sort(v.begin(),v.end(),comp);
        cout << v[0]->idx << " ";
        int end_ = v[0]->e;
        for(int i=1;i<v.size();i++){
            if(v[i]->s>=end_){
                cout << v[i]->idx << " ";
                end_ = v[i]->e;
            }
        }
        cout << "\n";
    }
    return 0;
}