#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
	string line;
	ifstream in;
	int ctr = 0;
	in.open("input_c_program.cpp");
	while(getline(in,line)){
		ctr++;
	}
	cout << "Lines: " << ctr << "\n";
	return 0;
}
