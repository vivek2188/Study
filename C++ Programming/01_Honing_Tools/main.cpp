#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ostream>
#include <string>
#include <iterator>
using namespace std;

void read(istream &input_stream,vector<string> &text){
	string line;
	while(getline(input_stream,line))
		text.push_back(line);
}

int main(int argc,char *argv[]){
	vector<string> text;
	if(argc<2)
		read(cin,text);
	else{
		ifstream in(argv[1]);	// If there is no such file than return NULL
		if(not in){
			perror(argv[1]);	// Prints the error message
			return EXIT_FAILURE;
		}
		read(in,text);
	}
	return 0;
}
