#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n,l,r;
	    cin >> n >> l >> r;
	    int a = ((1<<r)-1) ^ ((1<<(l-1))-1);
	    cout << (n^a) << "\n";
	}
	return 0;
}