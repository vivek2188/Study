#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

struct point{
	public:
		// Constructors
		point(): x(0),y(0){}
		point(double x_cor,double y_cor): x(x_cor),y(y_cor){}
		point(point const& p): x(p.x),y(p.y){}
		// Accessing the private mmebers using public member functions
		double get_x() const{
			return x;
		}
		double get_y() const{
			return y;
		}
		// Distance from the origin
		double distance() const{
			return sqrt(x*x+y*y);
		}
		// Angle relative to x-axis
		double angle() const{
			return atan2(y,x);
		}
		void move_cartesian(double x_,double y_){
			x = x_;
			y = y_;
		}
		void move_polar(double r,double angle_){
			return move_cartesian(r*cos(angle_),r*sin(angle_));
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
	private:
		// Data members
		double x;	// x coordinate
		double y;	// y coordinate
};

int main(void){
	point origin, unity;/*
	origin.x = origin.y  = 0;
	unity.x = unity.y = 1;
	cout << "Origin: (" << origin.x << "," << origin.y << ")\n";
	cout << "Unity: (" << unity.x << "," << unity.y << ")\n";*/
	return 0;
}