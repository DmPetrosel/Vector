#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vect.h"

int main() 
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target, dstep;
	cout << "Enter target distance (or q to quit: ";
	fstream fout;
	fout.open("output.txt", std::ios_base::app);//Open file output.txt
	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep)) {
			break;
		}
		cout << "Enter number of iteration: ";
		int n;
		int min_quant = INT_MAX, average = 0, max_quant = 0;
		if (!(cin >> n))
			break;

		while (n--) {
			fout << "Target distance: " << target << " Step size: " << dstep << '\n';
			while (result.magval() < target) {
				fout << steps << ": ";
				fout << result; //Adding to file
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			//cout << "After " << steps << " steps, the subject has following location.\n";
			//cout << result;
			result.polar_mode();
			//cout << "or\n" << result << '\n';
			//cout << "Average outward distance per steps: " << result.magval() / steps << '\n';
			fout << steps << ": ";
			fout << result;
			fout << "Average outward distance per steps: " << result.magval() / steps << '\n';
			fout.flush();
			min_quant = (min_quant > steps)? steps: min_quant;
			max_quant = (max_quant < steps) ? steps : max_quant;
			average = (max_quant + min_quant) / 2;
			steps = 0;
			result.reset(0.0, 0.0);

		}
		cout << "Max steps = " << max_quant << ". Average steps = " << average << ". Min steps = " << min_quant << ". \n";
		cout << "Enter target distance (or q to quit ";
	}
	cout << "Bye";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	fout.close();
	return 0;
}