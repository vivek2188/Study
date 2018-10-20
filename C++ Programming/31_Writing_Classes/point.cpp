#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

struct point{
	// Distance from the origin
	double distance(){
		return sqrt(x*x+y*y);
	}
	// Angle relative to x-axis
	double angle(){
		return atan2(y,x);
	}
	// Add an offset to x and y
	void offset(double off){
		offset(off,off);
	}
	void offset(double off_x,double off_y){
		x += off_x;
		y += off_y;
	}
	// Scale x and y
	void scale(double mult){
		scale(mult,mult);
	}
	void scale(double mult_x,double mult_y){
		x *= mult_x;
		y *= mult_y;
	}
	// Data members
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