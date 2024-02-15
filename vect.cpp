#include<cmath>
#include"vect.h" // iostream included

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	const double rad_to_degree = 45.0 / atan(1.0);//qunatity degrees in one readian 

	//Closed methods 
	//Compute module x and y
	void Vector::set_mag() {
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0) {
			ang = 0.0;
		}
		else {
			ang = atan2(y, x);
		}
	}
	void Vector::set_x() {
		x = mag * cos(ang);
	}
	void Vector::set_y() {
		y = mag * sin(ang);
	}
	// Default constructor
	Vector::Vector() {	
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2 / rad_to_degree;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect third argument to Vector()-- ";
			cout << "vector set to null";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2 / rad_to_degree;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect third argument to Vector()-- ";
			cout << "vector set to null";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector() 
	{}

	void Vector::polar_mode() {
		mode = POL;
	}
	void Vector::rect_mode() {
		mode = RECT;
	}

	//Overloading methods
	//Sum of two vectors 
	Vector Vector::operator+(const Vector& b)const {
		return Vector(x + b.x, y + b.y);
	}
	//Subtract vector b
	Vector Vector::operator-(const Vector& b)const {
		return Vector(x - b.x, y - b.y);
	}
	//Sign shifting
	Vector Vector::operator-()const {
		return Vector(-x, -y);
	}
	//Multiple object by n
	Vector Vector::operator*(double n)const {
		return Vector(n * x, n * y);
	}
	// Multiple n by object
	Vector operator*(double n, const Vector& a) {
		return a * n;
	}
	// Output cout
	std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.mode == Vector::RECT) {
			os << "{x, y} = (" << v.x << ", " << v.y << ")\n";
		}
		else if (v.mode == Vector::POL) {
			os << "{m, a} = (" << v.mag << ", " << v.ang << ") \n";
		}
		else {
			os << "Vector object mode is incorrect\n";
		}
		return os;
	}
	//Writing to file (fout)
	std::fstream& operator<<(std::fstream& fs, const Vector& v) {
		if(v.mode == Vector::RECT)
				fs << "{x, y} = (" << v.x << ", " << v.y << ")\n";
		else if (v.mode == Vector::POL) {
			fs << "{m, a} = (" << v.mag << ", " << v.ang << ") \n";
		}
		else {
			fs << "Vector object mode is incorrect\n";
		}
		return fs;
	}

}// End of VECTOR namespace