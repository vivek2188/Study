#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
	string line;
	ofstream write;
	write.open("write.c");
	while(getline(cin,line)){
		if(line=="$")
			break;
		write << line << "\n";
	}
	write.close();
	return 0;
}
