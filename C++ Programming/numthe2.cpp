#include <bits/stdc++.h>
using namespace std;

// O(n) Time Complexity
void naive_prime(int n){
	bool flag = 1;
	for(int i=2;i<n;i++){
		if(n%i==0){
			flag = 0;
			break;
		}
	}
	if(flag and n!=1 and n!=0)
		cout << "Prime\n";
	else cout << "Not Prime\n";
}

// O(sqrt(n)) Time Complexity
void better_prime(int n){
	bool flag = 1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			flag = 0;
			break;
		}
	}
	if(flag and n!=1 and n!=0)
		cout << "Prime\n";
	else cout << "Not Prime\n";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		naive_prime(n);
		better_prime(n);
	}
}