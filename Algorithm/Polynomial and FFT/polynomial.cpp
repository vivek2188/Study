#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

struct complex{
	complex(): r(0),i(0){}
	complex(int n){
		r = cos((2*M_PI)/n);
		i = sin((2*M_PI)/n);
	}
	complex(int R,int I){
		r = R;
		i = I;
	}
	// Real and imaginary part
	float r,i;
};

class polynomial{
	vector<int> coeff;
	int degree;
	public:
		/// Default Constructor
		polynomial(): degree(-1){}
		/// @param deg degree of the polynomial
		polynomial(int deg): degree(deg){}
		/// Copy Constructor
		polynomial(polynomial const& p){
			degree = p.degree;
			coeff = p.coeff;
		}
		/// Getting the input
		void input(){
			cout << "Enter the coefficient vector: ";
			int element;
			for(int i=0;i<=degree;++i){
				cin >> element;
				coeff.push_back(element);
			}
		}
		void input(int deg){
			if(deg==-1)
				return;
			degree = deg;
			coeff.clear();
			input();
		}
		/// Accessing the coefficient vector
		vector<int> get_coefficient(){
			return coeff;
		}
		/// Adding two polynomials of same degree
		polynomial add(polynomial const&);
		/// Multiplying two polynomials of same degree
		polynomial multiply(polynomial const&);
		/// Coefficient form to point form representation
		vector<complex> to_point(vector<int>);
		/// Evaluate for x: Horner's Rule
		int evaluate(int x){
			if(degree==-1)
				return -1;
			int ans = 0;
			for(int i=degree;i>=0;--i)
				ans = x*ans + coeff[i];
			return ans;
		}
		/// Print the coefficient vector
		void print(){
			if(degree==-1){
				cout << "Empty vector\n";
				return;
			}
			cout << "Coefficient Vector: ";
			copy(coeff.begin(),coeff.end(),ostream_iterator<int>(cout," "));
			cout << endl;
		}
};
polynomial polynomial::add(polynomial const& p){
	if(degree!=p.degree || degree<0){
		cout << "Degree of two polynomial must be same and >= 0.\n";
		return polynomial(-1);
	}
	polynomial add_(degree);
	for(int i=0;i<=degree;++i){
		int data = coeff[i] + p.coeff[i];
		add_.coeff.push_back(data);
	}
	return add_;
}
// Time Complexity: O(n*n)
polynomial polynomial::multiply(polynomial const& p){
	if(degree!=p.degree || degree<0){
		cout << "Degree of two polynomial must be same and >= 0.\n";
		return polynomial(-1);
	}
	polynomial mult(2*degree-1);
	for(int i=0;i<=mult.degree;++i){
		mult.coeff.push_back(0);
		for(int j=0;j<=i;j++)
			if(j<=degree and i-j<=degree)
				mult.coeff[i] += coeff[j] * p.coeff[i-j];
	}
	return mult;
}
/// Applying FFT to convert the polynomial from coefficient form to point form
vector<complex> polynomial::to_point(vector<int> a){
	vector<complex> y;
	int n = a.size();
	if((n&(n-1))!=0){
		cout << "Degree bound must be power of 2\n";
		return y;
	}
	if(n==1){
		complex y1(a[0],0);
		y.push_back(y1);
		return y;
	}
	complex wN(n);
	return y;
}

int main(void){
	int degree;
	cout << "Enter the degree: ";
	cin >> degree;
	polynomial p1(degree);
	p1.input();
	vector<int> coeff = p1.get_coefficient();
	p1.to_point(coeff);
	return 0;
}
