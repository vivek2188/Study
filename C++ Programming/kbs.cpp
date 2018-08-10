#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n , k;
	    cin >> n >> k;
	    n = (n >> k);
	    if((n&1))
	        cout << "Yes\n";
	    else cout << "No\n";
	}
	return 0;
}