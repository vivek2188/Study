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
/*
    For finding the prime number we can also use Fermat's little theorem:
        According to Fermat's theorem : 
            If 'p' is a prime number then for all number in the range (0,p) say a,
                REMEMBER - It is an open interval.
                a^(p-1) % p = 1
            Otherwise
                'p' is composite number.
*/
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

// O(sqrt(n)) Time Complexity
void factorise(int n){
	for(int j=2;j*j<=n;j++){
		while(n%j==0){
			cout << j << " ";
			n /=j;
		}
	}
	if(n>1)
		cout << n;
	cout << "\n";
}

// O(log(n)) Time Complexity
void factorise_eff(int n){
	int minprime[n+1];
	memset(minprime,0,sizeof(minprime));
	for(int i=2;i*i<=n;i++){
		if(minprime[i]==0){
			for(int j=i*i;j<=n;j+=i){
				if(minprime[j]==0)
					minprime[j] = i;
			}
		}
	}
	minprime[1] = 1;
	for(int i=2;i<=n;i++)
		if(minprime[i]==0)
			minprime[i] = i;
	while(n>1){
		cout << minprime[n] << " ";
		n /= minprime[n];
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
		factorise(n);
		factorise_eff(n);
	}
}