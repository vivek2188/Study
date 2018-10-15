#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

void ignore_line(){
	char ch;
	while((cin >> ch) and ch!='\n');
}

int prompted_read(string prompt){
	cout << prompt;
	int x = 0;
	cin >> x;
	ignore_line();
	return x;
}

void print_result(int count,float sum){
	if(count==0){
		cout << "No data\n";
		return;
	}
	cout << "Count: " << count << "\n"
	     << "Sum: " << sum << "\n"
	     << "Average: " << (sum/count) << "\n";
}

int main(void){
	float sum = 0;
	int count = 0;
	while(cin){
		int x = prompted_read("Enter the value: ");
		if(cin){
			sum += x;
			++count;
		}
	}
	print_result(count,sum);
	return 0;
}
