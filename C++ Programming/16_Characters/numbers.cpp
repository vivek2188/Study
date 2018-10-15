#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

int main(void){
	int value;
	char ch;
	bool have_value = false;
	while(cin.get(ch)){
		if(ch>='0' and ch<='9'){
			value = ch-'0';
			have_value = true;
			while(cin.get(ch) and ch<='9' and ch>='0')
				value = value * 10 + ch - '0';
		}
		if(ch=='\n'){
			if(have_value==true){
				cout << "Value: " << value << "\n";
				have_value = false;
			}
		}
		else if(ch==' ' or ch=='\t'){
			cout << "\a";
			while(cin.get(ch) and ch!='\n');
		}
	}
	return 0;
}
