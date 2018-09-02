#include "stdafx.h"
#include "std_lib_facilities.h"
#include <iostream>

using namespace std;

int chap3_drills();
void ask_birthday();

int chap3_drills() {
	ask_birthday();
	return 0;
}

void ask_birthday() {
	int age;
	cout << "How old are you?\n";
	while (cin >> age) {
		(age <= 0 || age >= 100) ? simple_error("You gotta be kidding?") :  cout << "Happy birthday\n" ;
		cout << "How old are you?\n";
	}
}