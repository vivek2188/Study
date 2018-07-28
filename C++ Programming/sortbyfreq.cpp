#include <bits/stdc++.h>
using namespace std;

struct arr{
	int val,indx,count;
};

bool comp_by_val(arr a,arr b){
	return a.val < b.val;
}

bool comp_by_count(arr a,arr b){
	if(a.count!=b.count)
		return a.count < b.count;
	else return a.indx > b.indx;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		arr a[n];
		for(int i=0;i<n;i++){
			int t;
			cin >> t;
			a[i].count = 0;
			a[i].indx = t;
			a[i].val = t;
		}
		sort(a,a+n,comp_by_val);
		a[0].count=1;
		for(int i=1;i<n;i++){
			if(a[i].val==a[i-1].val){
				a[i].count += a[i-1].count + 1;
				a[i-1].count = -1;
				a[i].indx = a[i-1].indx;
			}
			else a[i].count = 1;
		}
		sort(a,a+n,comp_by_count);
		for(int i=n-1;i>=0;i--){
			if(a[i].count!=-1){
				while(a[i].count>0){
					cout << a[i].val << " ";
					a[i].count--;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}