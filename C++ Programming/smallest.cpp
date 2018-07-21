#include <bits/stdc++.h>
using namespace std;

int main(){
	int size;
	cout << "Size: ";
	cin >> size;
	int a[size];
	cout << "Array: ";
	for(int i=0;i<size;i++)
		cin >> a[i];
	int small , sec_small ;
	small = sec_small = a[0];
	for(int i=1;i<size;i++){
		if(small>a[i]){
			sec_small = small;
			small = a[i];
		}
		else if(sec_small>a[i] and a[i]!=small)
			sec_small = a[i];
	}
	cout << "Smallest Element: " << small << "\n" << "Second Smallest Element: " << sec_small << "\n";
	return 0;
}