#include <iostream>
#include <ostream>
using namespace std;

struct point{
	double x;	// x coordinate
	double y;	// y coordinate
};

int main(void){
	point origin, unity;
	origin.x = origin.y  = 0;
	unity.x = unity.y = 1;
	cout << "Origin: (" << origin.x << "," << origin.y << ")\n";
	cout << "Unity: (" << unity.x << "," << unity.y << ")\n";
	return 0;
}