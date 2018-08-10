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

// Seive of Eratosthenes
void seive(int n){
	bool flag[n+1];
	memset(flag,1,sizeof(flag));
	flag[0] = flag[1] = 0; 
	for(int i=3;i*i<=n;i+=2){
		if(flag[i]==1){
			for(int j=i*i;j<=n;j+=2*i){
				if(flag[j])
					flag[j] = 0; 
			}
		}
	}
	cout << 2 << " ";
	for(int i=3;i<n;i+=2){
		if(flag[i])
			cout << i << " ";
	}
	cout << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		naive_prime(n);
		better_prime(n);
		seive(n);
	}
}