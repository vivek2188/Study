#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[],int p,int r,int k){
	if(p<=r){
		if(p==r){
			if(k!=a[p])
				return -1;
			else return p;
		}
		int q = (p+r)/2;
		if(a[q]==k)
			return q;
		else if(a[q]>k)
			return binary_search(a,p,q-1,k);
		else return binary_search(a,q+1,r,k);
	}
	else return -1;
}

int main(){
	int t;
	cout << "#Testcases: ";
	cin >> t;
	while(t--){
		int n ;
		cout << "Size: ";
		cin >> n; 
		cout << "Array: ";
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		int k ;
		cout << "Find: ";
		cin >> k;
		int find = -1;
		find = binary_search(a,0,n-1,k);
		cout << find << "\n";
	}	
	return 0;
}