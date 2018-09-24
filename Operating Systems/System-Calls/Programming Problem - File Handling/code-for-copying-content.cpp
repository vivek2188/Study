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
	if(FILE *file = fopen(filename.c_str(),"r")){
		fclose(file);
		return true;	// Exist
	}	
	else return false;	// Does not exist
}

int main(){
	// Acquire input file name
	string input_filename, output_filename;
	cout << "Enter input file name: ";
	cin >> input_filename;
	// Acquire output file name
	cout << "Enter output file name: ";
	cin >> output_filename;
	// Check whether input file exist or not
	if(file_exist(input_filename)){
		cout << "Input file exist\nProceeding...\n";
	}
	else{
		cout << "File doesn't exist";
		exit(1);
	}
	// Checking whether the output file already exist
	if(file_exist(output_filename)){
		cout << "Output file already exist\nAborting...\n";
		exit(1);
	}
	else{
		cout << "Output file does not exist\nProceeding...\n";
	}
	return 0;
}
