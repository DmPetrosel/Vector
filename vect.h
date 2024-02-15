#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>
#include<fstream>
namespace VECTOR
{
	class Vector {
	public:
		enum Mode { RECT, POL };
	private: 
		double x; // x coordinate (horizontal)
		double y; // y coordinate (vertical)
		double mag; // length of vector by module 
		double ang; // direction if vector in degrees
		Mode mode; //RECT or POL
		//Closed methods for setting values 
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public: 
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();

		//Operation overload 
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const; 
		Vector operator*(double n)const; 
		
		//Friends
		friend Vector operator * (double n, const Vector& a);
		friend std::ostream& operator << (std::ostream& os, const Vector& v);
		friend std::fstream& operator << (std::fstream &fs, const Vector& v);
	};
}
#endif //VECTOR_H_