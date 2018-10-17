#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <iomanip>
#include <iterator>
using namespace std;

void print(int a){
	cout << a;
}

void print(int a,int b){
	cout << setw(b) << a;
}

void print(vector<int> data,string a,string b,string c,int field_width){
	cout << a;
	for(vector<int>::iterator it=data.begin();it!=data.end();++it){
		print(*it,field_width);
		if(it+1 != data.end())
			cout << b;
	}
	cout << c << "\n";
}

void print(vector<int> data,string a,string b,string c){
	print(data,a,b,c,0);
}

int main(void){
	vector<int> data;
	int field_width;
	cout << "Enter field_width: ";
	cin >> field_width;
	cout << "Vector: ";
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(data));
	string start = " start";
	string between = " between";
	string end = " end";
	cout << "Output:";
	print(data,start,between,end,field_width);
	return 0;
}