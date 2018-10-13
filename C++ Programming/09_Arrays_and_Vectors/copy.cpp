#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int main(void){
	vector<int> input(3);
	vector<int> output(3);
	input.at(0) = 10;
	input.at(1) = 20;
	input.at(2) = 30;
	// Copy function
	copy(input.begin(),input.end(),output.begin());
	assert(input==output);
	return 0;
}
