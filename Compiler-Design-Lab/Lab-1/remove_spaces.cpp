#include <iostream>
#include <fstream>
using namespace std;
/*program to copy a file without spaces and new lines*/

int main(){
	char ch;
	ifstream in;
	ofstream out;
	int ctr = 0;
	in.open("count_operators.cpp");
	out.open("abc.txt");
	while((in>>ch)){
		if(ch=='\n'||ch==' ')
			continue;
		out<<ch;
	}
	cout << "File Copied\n";  //done
	out.close();	//file closed
	return 0;
}
