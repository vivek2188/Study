#include <fstream>
#include <istream>
#include <ostream>
using namespace std;

int main(void){
	ifstream input("input.txt");
	if(not input)		// Input does not exist
		perror("input.txt");
	else{				// Input exists
		ofstream output("write.txt");
		if(not output)	// Error opening write.txt
			perror("write.txt");
		else{
			int x;
			while(input >> x)
				output << x;
			output.close();
			input.close();
		}
	}
	return 0;
}
