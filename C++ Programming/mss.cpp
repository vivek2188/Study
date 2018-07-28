//---------------VERSION 1-------------------//
// Time complexity O(n*k)
/*
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
		int val[n];
		val[0] = a[0];
		for(int i=1;i<n;i++){
			int mx = INT_MIN;
			for(int j=0;j<i;j++)
				if(a[j]<a[i])
					mx = max(val[j],mx);
			if(mx!=INT_MIN)	
				val[i] = mx + a[i];
			else val[i] = a[i];
		} 
		int mx = INT_MIN;
		for(int i=0;i<n;i++)
			mx = max(mx,val[i]);
		cout << mx << "\n";
	}
}
*/

//---------------VERSION 2-----------------//
// Time complexity O(n*log(n))
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
		multiset<int>set;
		for(int i=0;i<k;i++)
		    set.insert(a[i]);
		cout << *set.rbegin() << " ";
		for(int i=k;i<n;i++){
		    auto itr = set.find(a[i-k]);
		    set.erase(itr);
		    set.insert(a[i]);
		    cout << *set.rbegin() << " ";
		}
		cout << "\n";
	}
}