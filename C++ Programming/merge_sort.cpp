#include <bits/stdc++.h>
using namespace std;

void merge_sort(int *a,int p,int q,int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int left[n1+1];
	int right[n2+1];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	
	for(int i=0;i<n1;i++)
		left[i] = a[p+i];
	for(int i=0;i<n2;i++)
		right[i] = a[q+i+1];
	
	int indx1 , indx2 ; 
	indx1 = indx2 = 0;
	for(int i=p;i<=r;i++){
		if(left[indx1]<=right[indx2]){
			a[i] = left[indx1];
			indx1++;
		}
		else{
			a[i] = right[indx2];
			indx2++;
		}
	}
	
}

void merge(int *a,int p,int r){
	if(p<r){
		int q = (p+r) /2; 
		merge(a,p,q);
		merge(a,q+1,r);
		merge_sort(a,p,q,r);
	}
}

int main(){
	int size ;
	cout << "Enter the size of array: ";
	cin >> size;
	int a[size];
	cout << "Enter the array: ";
	for(int i=0;i<size;i++)
		cin >> a[i];
	merge(a,0,size-1);
	for(int i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0; 
}
