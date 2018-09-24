/*
	ofstream - Stream class to write on files
	ifstream - Stream class to read from files
	fstream  - Stream class to both read and write from/to files
*/
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;

// Function to check whether the file exist or not
bool file_exist(string filename){
	if(FILE *file = open(filename.c_str(),'r')){
		fclose(file);
		return true;	// Exist
	}	
	else return false;	// Does not exist
}

int main(){
	
	return 0;
}
