#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

struct complex{
	// Constructors
	complex(): r(0),i(0){}
	complex(int n){
		r = cos((2*M_PI)/n);
		i = sin((2*M_PI)/n);
	}
	complex(float R,float I){
		r = R;
		i = I;
	}
	// Addding two complex numbers
	complex add(complex b){
		return complex(r+b.r,i+b.i);
	}
	// Subtracting two complex numbers
	complex subtract(complex b){
		return complex(r-b.r,i-b.i);
	}
	// Multiplying two complex numbers
	complex multiply(complex b){
		return complex(r*b.r-i*b.i,r*b.i+i*b.r);
	}
	// Real and imaginary part
	float r,i;
};

class polynomial{
	vector<float> coeff;
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
			float element;
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
		vector<float> get_coefficient(){
			return coeff;
		}
		/// Adding two polynomials of same degree
		polynomial add(polynomial const&);
		/// Multiplying two polynomials of same degree
		polynomial multiply(polynomial const&);
		/// Coefficient form to point form representation
		vector<complex> to_point(vector<float>);
		/// Point form to coefficient form representation
		vector<float> to_coefficient(vector<complex>);
		/// Evaluate for x: Horner's Rule
		int evaluate(float x){
			if(degree==-1)
				return -1;
			float ans = 0;
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
			copy(coeff.begin(),coeff.end(),ostream_iterator<float>(cout," "));
			cout << endl;
		}
};
polynomial polynomial::add(polynomial const& p){
	if(degree!=p.degree || degree<0){
		cout << "Degree of two polynomial must be same and >= 0.\n";
		return polynomial(-1);
	}
	polynomial add_(degree);
	for(int i=0;i<=degree;++i)
		add_.coeff.push_back(coeff[i] + p.coeff[i]);
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
vector<complex> polynomial::to_point(vector<float> a){
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
	complex w(1,0);
	vector<float> a0, a1;
	for(int i=0;i<n;i++){
		if(i%2==0)
			a0.push_back(a[i]);
		else a1.push_back(a[i]);
	}
	/*copy(a0.begin(),a0.end(),ostream_iterator<float>(cout," "));
	copy(a1.begin(),a1.end(),ostream_iterator<float>(cout," "));*/
	vector<complex> y0 = to_point(a0);
	vector<complex> y1 = to_point(a1);
	// Initialising y
	for(int i=0;i<n;i++)
		y.push_back(complex());
	// Combining the subproblems
	for(int k=0;k<=n/2-1;++k){
		y[k] = y0[k].add(w.multiply(y1[k]));
		y[k+n/2] = y0[k].subtract(w.multiply(y1[k]));
		w = w.multiply(wN);
	}
	return y;
}
/// Applying Inverse FFT to convert the polynomial from point form to coefficient form
vector<float> to_coefficient(vector<complex> y){
	// Write code for inverse FFT
}

int main(void){
	int degree;
	cout << "Enter the degree: ";
	cin >> degree;
	polynomial p1(degree);
	p1.input();
	vector<float> coeff = p1.get_coefficient();
	vector<complex> y = p1.to_point(coeff);
	cout << "Point form is:\n";
	for(int i=0;i<y.size();++i)
		cout << " " << y[i].r << "\t" << y[i].i << "\n";
	return 0;
}
