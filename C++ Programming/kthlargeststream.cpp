#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> k >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        multiset<int>s;
        for(int i=0;i<k-1;i++)
        	cout << -1 << " ";
        for(int i=0;i<k;i++)	
        	s.insert(a[i]);
        cout << *s.begin() << " ";
        for(int i=k;i<n;i++){
        	if(*s.begin()<a[i]){
        		s.erase(s.begin());
				s.insert(a[i]);
        		cout << *s.begin() << " ";
			}
			else cout << *s.begin() << " ";
		}
    	cout << "\n";
    }
}