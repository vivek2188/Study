#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iterator>
using namespace std;

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
		/// Addition of two polynomials
		polynomial add(polynomial const&);
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

int main(void){
	int degree;
	cout << "Enter the degree: ";
	cin >> degree;
	polynomial p1(degree);
	return 0;
}
