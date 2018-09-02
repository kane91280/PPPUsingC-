#include "stdafx.h"
#include "std_lib_facilities.h"
#include <iostream>

using namespace std;
int chap3_exercises();
void miles_to_km();
void order_integer();
void echo_integer_word();
void read_operator_operands();

int chap3_exercises() {
	//miles_to_km();
	//order_integer();
	//echo_integer_word();
	read_operator_operands();
	return 0;
}

void miles_to_km() {
	int distance_in_mile{1};
	double distance_in_km{distance_in_mile*1.609};
	
	cout << "Enter the distance in mile(s)\n";
	while (cin >> distance_in_mile) {
		distance_in_km = distance_in_mile * 1.609;
		cout << "The distance in km is " << distance_in_km << "\n\n";
		cout << "Enter the distance in mile(s)\n";
	}

}

void order_integer() {
	int a, b, c;

	cout << "Enter 3 integers: \n";
	cin >> a >> b >> c;
	if (a <= b && a <= c) {
		if (b <= c) cout << a << ' ' << b << ' ' << c << endl;
		if (c <= b) cout << a << ' ' << c << ' ' << b << endl;
	}

	else if (b <= a && b <= c) {
		if (a <= c) cout << b << ' ' << a << ' ' << c << endl;
		if (c <= a) cout << b << ' ' << c << ' ' << a << endl;
	}

	else if (c <= a && c <= b) {
		if (a <= b) cout << c << ' ' << a << ' ' << b << endl;
		if (b <= a) cout << c << ' ' << b << ' ' << a << endl;
	}
}

void echo_integer_word() {
	int n;

	cout << "Enter an integer: \n";
	while (cin >> n) {
		if (n == 0)
			cout << "Zero\n";
		else if (n == 1)
			cout << "One\n";
		else if (n == 2)
			cout << "Two\n";
		else if (n == 3)
			cout << "Three\n";
		else if (n == 4)
			cout << "Four\n";
		else if (n == 5)
			cout << "Five\n";
		else if (n == 6)
			cout << "Six\n";
		else if (n == 7)
			cout << "Seven\n";
		else if (n == 8)
			cout << "Eight\n";
		else if (n == 9)
			cout << "Nine\n";
		else
			cout << "Sorry I don't know that number\n";
		cout << "Enter an integer: \n";
	}
}//end of echo_integer_word()

void read_operator_operands() {
	string m_operator;
	double a, b;

	cout << "Enter an operator followed by 2 operands (eg. + 100 20)\n";
	while (cin >> m_operator >> a >> b) {
		if (m_operator == "+") {
			cout << "Addition result is : " << a << " + " << b << " = " << a + b << "\n\n";
		}
		else if (m_operator == "-") {
			cout << "Subtraction result is : " << a << " - " << b << " = " << a - b << "\n\n";
		}
		else if (m_operator == "*") {
			cout << "Multiplication result is : " << a << " * " << b << " = " << a * b << "\n\n";
		}
		else if (m_operator == "/") {
			cout << "Division result is : " << a << " / " << b << " = " << a / b << "\n\n";
		}	
		else {
			cout << "I don't know the operation\n\n";
		}
		cout << "Enter an operator followed by 2 operands (eg. + 100 20)\n";
	}
}