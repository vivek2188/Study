#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[],int k,int size,int b[]){
	int c[k+1] = {0};
	for(int i=0;i<size;i++)
		c[a[i]]++;
	for(int i=1;i<=k;i++)
		c[i] += c[i-1];
	for(int j=size-1;j>=0;j--){
		b[c[a[j]]-1] = a[j];
		c[a[j]] -= 1;
	}
}

int main(){
	int k ;
	cout << "Range: ";
	cin >> k;
	int size ; 
	cout << "Size: ";
	cin >> size;
	int a[size];
	int b[size] = {0};
	cout << "Array: ";
	for(int i=0;i<size;i++)
		cin >> a[i];
	counting_sort(a,k,size,b);
	for(int i=0;i<size;i++)
		cout << b[i] <<  " ";
}