#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int p,int r){
	int pivot = a[r];
	int i = p-1;
	for(int j=p;j<r;j++){
		if(a[j]<pivot){
			i = i + 1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return (i+1);
}

void qsort(int a[],int p,int r){
	if(p<r){
		int q = partition(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}
}

int main(){
	int size;
	cout << "Size: ";
	cin >> size;
	int arr[size];
	cout << "Array: ";
	for(int i=0;i<size;i++)
		cin >> arr[i];
	qsort(arr,0,size-1);
	for(int i=0;i<size;i++)
		cout << arr[i] << " ";
	return 0;
}
