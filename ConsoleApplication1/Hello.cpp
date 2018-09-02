// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "std_lib_facilities.h"
#include <iostream>

using namespace std;
int test();
void arithmetics();
void basic_string_operations();
void find_repeated_words();
void safe_conversion();

int test()
{		 
	/*cout << "Open main entrance door\nWalk straight 2 metres\nWalk up the stair all the way to the top of the stair\n";
	cout << "Stop\nTurn 90 degree to the right\nWalk 2 metres\nTurn right\nOpen the door\n\n";*/
	
	//arithmetics();
	//basic_string_operations();
	//find_repeated_words();
	safe_conversion();
		
    return 0;
}

void arithmetics() {
	int n;
	cout << "Enter an integer: \n";
	cin >> n;
	cout << "Twice of n == " << n * 2 << endl;
	cout << "Half of n == " << n / 2 << endl;
	cout << "Modulus of n == " << n % 2 << endl;
	cout << "n squared == " << n*n << endl;
	cout << "Square root of n == " << sqrt(n) << endl;

}

void basic_string_operations() {
	string first_name = "Khoa";
	string last_name = "Dang";

	cout << "Tell us your first name and last name please:\n";
	cin >> first_name >> last_name;
	cout << "Hello " << first_name << "(" << last_name << ")" << ", Welcome to our program!\n\n";	

	(first_name > last_name) 
		? cout << "first name comes after last name\n" 
		: cout << "first name comes before last name\n";
	cout << "Your full name is : " << first_name + " " + last_name << endl;
}

void find_repeated_words() {
	string prev = "";
	string current = "";
	int cnt = 0;

	while (cin >> current) {
		if (current == prev) {
			cout << "repeated word : " << current << "\n";			
			if (++cnt > 1)
				cout << "repeated word is in a sequence\n";
		} else 
			cnt = 0;
		prev = current;
	}
}

void safe_conversion() {
	/*bool a = true;
	int b = a;
	bool c = b;*/

	double d1 = 2.3;
	double d2 = d1 + 2.3;

	
	cout << d1 << ' ' << d2 << ' '<< endl;
}