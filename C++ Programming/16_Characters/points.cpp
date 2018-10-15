#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <ios>
using namespace std;

typedef vector<int> points;
typedef points::iterator iter;

int main(void){
	points xs,ys;
	char ch;
	int x,y;
	char sep;
	while(cin >> x >> sep and sep==',' and cin >> y){
		xs.push_back(x);
		ys.push_back(y);
	}
	cout << "Collection of points: \n";
	for(iter itx=xs.begin(),ity=ys.begin();itx!=xs.end();itx++,ity++)
		cout << *itx << " " << *ity << "\n";
	return 0;
}
