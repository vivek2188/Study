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

// EUCLID's Theorem for finding GCD of two numbers
void gcd(int a,int b){
	if(a<b)
		swap(a,b);
	while(b>0){
		a = a%b;
		swap(a,b);
	}
	cout << "GCD: " << a << "\n";
}

// Extended Euclid's theorem
/*
	If a,b are coprime:
		x = Modular Multiplicative Inverse of a under modulo b
		y = Modular Multiplicative Inverse of b under modulo a
*/
void gcd_extended(int a,int b,int &x,int &y,int &_gcd){
	if(b==0){
		x = 1;
		y = 0;
		_gcd = a;
	}
	else{
		gcd_extended(b,a%b,x,y,_gcd);
		int temp = x;
		x = y;
		y = temp - y * (a/b);
	}
}

int main(){
	int a,n,m;
	cin >> a >> n >> m;
	exponentiation(a,n);
	modexp(a,n,m);
	int p,q;
	cin >> p >> q;
	gcd(p,q);
	int _gcd,x,y;
	gcd_extended(p,q,x,y,_gcd);
	cout << "Extended Euclidean: " << _gcd << " " << x << " " << y << "\n";
	return 0;
}