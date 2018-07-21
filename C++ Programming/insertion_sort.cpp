#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[6] ;
	int size = sizeof(a) / sizeof(int);
	for(int i=0;i<size;i++)
		cin >> a[i] ;
	int key = a[1];
	for(int j=1;j<size;j++){
		key = a[j];
		int i = j-1;
		while(i>=0 and a[i]>key){
			a[i+1]  = a[i];
			i -= 1;
		}
		a[i+1] = key;
	}
	for(int i=0;i<size;i++)
		cout << a[i] << " ";
	return 0;
}
