#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>
#include <vector>
using namespace std;

void modify(int a){
	a = 10;
}

int triple(int b){
	return 3*b;
}

void add(vector<int> data,int a){
	for(vector<int>::iterator it=data.begin();it!=data.end();++it)
		*it += a;
}

void print_vector(vector<int> data){
	copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
	cout << "\n";
}

int main(void){
	int a = 42;
	modify(a);
	cout << "a: " << a << "\n";
	int b = triple(14);
	cout << "b: " << b << "\n"; 
	vector<int> data;
	for(int i=1;i<=5;i++)
		data.push_back(i*10);
	cout << "Initial vector: ";
	print_vector(data);
	add(data,a);
	cout << "Final vector: ";
	print_vector(data);
	return 0;
}

/*
	Keywords: 1. Actual Arguments
		  2. Formal Arguments
		  3. Call by value
*/
