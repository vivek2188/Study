#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int p,int r){
	int pivot = a[r];
	int i = p-1;
	for(int j=p;j<r;j++){
		if(a[j]<pivot){
			i = i+1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return (i+1);
}

int order_statistics(int a[],int p,int r,int indx){
	if(p==r)
		return a[p];
	int q = partition(a,p,r);
	int pos = q - p;
	cout << "pos: " << pos << a[pos] << "\n";
	if(indx==pos)
		return a[q];
	else if(indx < pos)
		return order_statistics(a,p,q-1,indx);
	else{
		return order_statistics(a,q+1,r,indx-pos-1);
	}
}

int main(){
	int size;
	cout << "Size: ";
	cin >> size;
	int a[size];
	cout << "Array: ";
	for(int i=0;i<size;i++)
		cin >> a[i];
	cout << "Index: ";
	int indx;
	cin >> indx;
	int val = order_statistics(a,0,size-1,indx);
	cout << "Value: " << val;
	return 0;
}