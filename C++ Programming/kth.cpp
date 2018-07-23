#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m,k;
	    cin >> n >> m >> k;
	    k--;
	    int l[n+1],r[m+1];
	    l[n] = INT_MAX;
	    r[m] = INT_MAX;
	    for(int i=0;i<n;i++)
	        cin >> l[i];
	    for(int i=0;i<m;i++)
	        cin >> r[i];
	    int i , j;
	    i = j = 0;
	    int ans = -1;
	    for(int indx=0;indx<=k;indx++){
	        if(l[i]<r[j]){
	            ans = l[i];
	            i++;
	        }
	        else{
	            ans = r[j];
	            j++;
	        }
	    }
	    cout << ans << "\n";
	}
	return 0;
}