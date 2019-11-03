// Complex number calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void input(double& a, double& b);
void output(double a, double b);
void mag(double& a, double& b);
void add(double& a, double& b, double c, double d);
void sub(double& a, double& b, double c, double d);
void mul(double& a, double& b, double c, double d);
bool div(double& a, double& b, double c, double d);

int main() {
	double a, b, c, d;
	char comm;	
	do {
		cout << "Command? (C,L,S,+,-,*,/): ";
		cin >> comm;
		if (comm == 'C') {
			input(a, b);
			output(a, b);
		}
		else if (comm == 'L') {
			mag(a, b);
		}
		else if (comm == '+') {
			input(c, d);
			add(a, b, c, d);
			output(a, b);
		}
		else if (comm == '-') {
			input(c, d);
			sub(a, b, c, d);
			output(a, b);
		}
		else if (comm == '*') {
			input(c, d);
			mul(a, b, c, d);
			output(a, b);
		}
		else if (comm == '/') {
			input(c, d);
			if (div(a, b, c, d))
				output(a, b);
			else {
				cout << "Can't divide by 0" << endl;
				output(a, b);
			}
		}
	} while (comm != 'S');
	return 0;
}

void input(double& a, double& b) {
	cout << "Input the real part: " << endl;
	cin >> a;
	cout << "Input the imag part: " << endl;
	cin >> b;
	}

void output(double a, double b) {
	if (b < 0) {
		cout << "Current Value is " << fixed << setprecision(2) << a << " " << b << "i" << endl;
		}
	else {
		cout << "Current Value is " << fixed << setprecision(2) << a << " + " << b << "i" << endl;
		}
	}
void mag(double& a, double& b) {
	cout << "Length of current value is " << sqrt(a*a + b*b) << endl;
	}

void add(double& a, double& b, double c, double d) {
	a = a + c;
	b = b + d;
	}

void sub(double& a, double& b, double c, double d) {
	a = a - c;
	b = b - d;
	}

void mul(double& a, double& b, double c, double d) {
	double e, f;
	e = a;
	f = b;
	a = e * c - f * d;
	b = e * d + f * c;
	}

bool div(double& a, double& b, double c, double d) {
	if (c == 0 && d == 0) {
		return false;
	}
	else {
		double e, f;
		e = a;
		f = b;
		a = (e * c + f * d) / (c * c + d * d);
		b = (f * c - e * d) / (c * c + d * d);
		return true;
	}
}
