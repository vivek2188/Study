#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
using namespace std;

typedef vector<int> coef;

class polynomial{
	coef a;
	public:
		polynomial(){
			polynomial(0);
		}
		polynomial(int degree){
			cout << "Enter the coefficient vector: ";
			int element;			
			for(int i=0;i<=degree;i++){
				cin >> element;
				a.push_back(element);
			}
		}
};

int main(void){
	int degree;
	cout << "Enter the degree: ";
	cin >> degree;
	polynomial p1(degree);
	return 0;
}
