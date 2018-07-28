#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int count[26] = {0};
        for(int i=0;i<26;i++)
            count[s[i]-'a']++;
        priority_queue<int> heap;
        for(int i=0;i<26;i++){
            if(count[i]>0)
                heap.push(count[i]);
        }
        int size = 0;
        int prev = -1;
        while(!heap.empty()){
            int mx_val = heap.top();
            heap.pop();
            size++;
            mx_val--;
            if(prev>0)
                heap.push(prev);
            prev = mx_val;
        }
        if(size==s.size())
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}