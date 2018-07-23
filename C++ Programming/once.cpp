#include <iostream>
using namespace std;

int find(int a[],int p,int r){
    if(p<=r){
        if(p==r)
            return a[p];
        int q = (p+r)/2;
        if(q%2==0){
            if(a[q+1]==a[q])
                return find(a,q+2,r);
            else return find(a,p,q);
        }
        else{
            if(a[q]==a[q-1])
                return find(a,q+1,r);
            else return find(a,p,q);
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin >> a[i];
	    cout << find(a,0,n-1) << "\n";
	}
	return 0;
}