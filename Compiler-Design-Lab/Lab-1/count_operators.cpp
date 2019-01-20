#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char ch;
	ifstream in;
	int ctr = 0;
	in.open("count_operators.cpp");
	while((in>>ch)){
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
			ctr++;
	}
	cout << "No. of operators: " << ctr << "\n";
	return 0;
}
