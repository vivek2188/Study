#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second)
        return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> >v;
        int start[n],end[n];
        for(int i=0;i<n;i++)
            cin >> start[i];
        for(int j=0;j<n;j++)
            cin >> end[j];
        for(int i=0;i<n;i++)
            v.push_back(make_pair(start[i],end[i]));
        sort(v.begin(),v.end(),comp);    
        /*for(int i=0;i<n;i++)
            cout << v[i].first << " " << v[i].second << "\n";
        cout << "------------\n";*/
        int count = 1,end_ = v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>=end_){
                count++;
                end_ = v[i].second;
            }
        }
        cout << count << "\n";
    }
    return 0;
}