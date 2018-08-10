#include <bits/stdc++.h>
using namespace std;

/*
	MODULAR ARITHEMETIC
	
	1. (a + b) % m = ( a %m  + b%m ) % m
	2. (a - b) % m = ( a %m  - b%m + m ) % m
	3. (a * b) % m = ( a %m  * b%m ) % m
	4. (a / b) % m = ( a %m  * (b-1)%m ) % m
		b-1 is the modular multiplicative inverse of b and c
*/

// EXPONENTIATION log2(n) Time Complexity
void exponentiation(int a,int n){
	int ans = 1;
	while(n>0){
		if(n&1)
			ans *= a;
		a *= a;
		n = (n>>1);
	}
	cout << "Exponentiation: " << ans << "\n";
}

// MODULAR EXPONENTIATION
void modexp(int a,int n,int m){
	int ans = 1;
	a = a%m;
	while(n>0){
		if(n&1)
			ans = (ans*a)%m;
		a = (a*a)%m;
		n = (n>>1);
	}
	cout << "Modular Exponentiation: " << ans << "\n";
}

int main(){
	int a,n,m;
	cin >> a >> n >> m;
	exponentiation(a,n);
	modexp(a,n,m);
	return 0;
}