#include <bits/stdc++.h>
using namespace std;

void max_heapify(int a[],int i,int heapsize){
	int largest = i;
	int lch = (i<<1) + 1;
	int rch = (i<<1) + 2;
	if(a[largest] < a[lch] and lch < heapsize)
		largest = lch;
	if(a[largest] < a[rch] and rch < heapsize)
		largest = rch;
	if(largest!=i){
		swap(a[largest],a[i]);
		max_heapify(a,largest,heapsize);
	}
}

void build_max_heap(int a[],int size){
	int heapsize = size;
	for(int i=(size-2)/2;i>=0;i--)
		max_heapify(a,i,heapsize);
}

void heapsort(int a[],int size){
	int heapsize = size;
	build_max_heap(a,size);
	while(heapsize>0){
		swap(a[0],a[heapsize-1]);
		max_heapify(a,0,heapsize-1);
		heapsize--;
	}
}

void heap_max(int a[]){
	cout << "Maximum element: " << a[0];
}

void heap_extract_max(int a[],int heapsize){
	cout << a[0] << endl;
	swap(a[0],a[heapsize]);
	heapsize--;
	max_heapify(a,0,heapsize);
}

void heap_increase_key(int a[],int i,int key){
	a[i] = key;
	while(i>0 and a[i]>a[(i-1)/2]){
		swap(a[i],a[(i-1)/2]);
		i = (i-1) / 2;
	}
}

void heap_insert(int a[],int heapsize,int x){
	heapsize = heapsize + 1;
	a[heapsize] = INT_MIN;
	heap_increase_key(a,heapsize,x);
}

int main(){
	int size ; 
	cout << "Size: " ;
	cin >> size;
	int a[size];
	cout << "Array: ";
	for(int i=0;i<size;i++)
		cin >> a[i];
	build_max_heap(a,size);
	for(int i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
	heap_insert(a,4,7);
	//heap_increase_key(a,3,10);
	//heapsort(a,size);
	for(int i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
