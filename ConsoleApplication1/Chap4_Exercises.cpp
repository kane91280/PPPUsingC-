#include "stdafx.h"
#include "std_lib_facilities.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;
constexpr int factorial(const int n);
void print_char_and_int();
void temperatures();
void dictionary();
void length_conversion();
void number_guessing_game();
void route_cities();
void calculator();
void string_to_number();
int find_string_in_vec( const vector<string> &v, string const s);
bool check_string_is_integer(const string& s);
void chess_game_price();
void rock_paper_scissors();
void prime_number_find();

constexpr double pi = 3.14;
constexpr double inch_to_cm = 2.54;
constexpr double meter_to_cm = 100;
constexpr double ft_to_inch = 12;

int main() {
	//cout << factorial(5) << "\n";
	//print_char_and_int();
	//temperatures();
	//dictionary();
	//length_conversion();
	//number_guessing_game();
	//route_cities();
	//calculator();
	//string_to_number();
	//chess_game_price();
	//rock_paper_scissors();
	prime_number_find();
}

constexpr int factorial(const int n) {
	return (n == 1) ? 1 : n*factorial(n - 1);
}

void test_constexpr(const double n) {
	constexpr double a = pi + 6;	
	const double b = n + 9;
}

void convert_to_dollar() {
	double amt;
	cout << "Enter amount of money and currency (eg. 10 y)";
	cin >> amt;
}

void print_char_and_int() {
	char character = 'a';	

	/*while (character < 123) {
		cout << character << "\t" << int(character) << "\n";
		++character;
	}*/

	for (character = 'a'; character < 123; ++character) 
		cout << character << "\t" << int(character) << "\n";	

	for (int a = 65; a < 90; ++a)
		cout << a << "\t" << char(a) << "\n";
}

void temperatures() {
	vector<double> temperatures;
	double sum = 0;

	for (double temperature; cin >> temperature;) {
		temperatures.push_back(temperature);
		sort(temperatures.begin(), temperatures.end());
		cout << "Median temperature is : " << temperatures[temperatures.size() / 2] << "\n";
	}

	for (double temperature : temperatures)
		sum += temperature;
		
	sort(temperatures.begin(), temperatures.end());

	cout << "Lowest to highest temperature" << "\n";
	for (double temp : temperatures)
		cout << temp << "  ";
	cout << "\n";
	cout << "Average temperature is : " << sum / temperatures.size() << "\n";
	//cout << "Median temperature is : " << temperatures[temperatures.size() / 2] << "\n";
}

void dictionary() {
	vector<string> words;
	int size = 0;
	string profanity = "fuck";

	for (string word; cin >> word;)
		words.push_back(word);
	size = words.size();

	sort(words.begin(), words.end());

	for (int i = 0; i < size; ++i) {
		if (i == 0 || words[i] != words[i - 1]) {
			if (words[i] == profanity)
				cout << "Bleeps" << "\t";
			else
				cout << words[i] << "\t";
		}
	}
	cout << "\n";
}

void length_conversion() {
	double len;
	string unit;	
	double smallest;
	double largest;
	double len_in_meter = 0;
	vector<double> lens_in_meter;
	int cnt = 0;

	//take input and compute conversion
	while (cin >> len >> unit) {		
		if (unit == "cm") {
			len_in_meter = len / meter_to_cm;
			cout << len << " cm = " << len / meter_to_cm << " m";
			cout << " OR " << len / inch_to_cm << " in";
			cout << " OR " << (len / inch_to_cm) / ft_to_inch << " ft";
		}
		else if (unit == "m") {
			len_in_meter = len;
			cout << len << " m = " << len * meter_to_cm << " cm";
			cout << " OR " << (len * meter_to_cm) / inch_to_cm << " in";
			cout << " OR " << ((len * meter_to_cm) / inch_to_cm) / ft_to_inch << " ft";
		}
		else if (unit == "in") {
			len_in_meter = (len * inch_to_cm) / meter_to_cm;
			cout << len << "in = " << len / ft_to_inch << " ft";
			cout << " OR " << len * inch_to_cm << " cm";
			cout << " OR " << (len * inch_to_cm) / meter_to_cm << " m";
		}
		else if (unit == "ft") {
			len_in_meter = ((len * ft_to_inch) * inch_to_cm) / meter_to_cm;
			cout << len << " ft=" << len * ft_to_inch << " in";
			cout << " OR " << (len * ft_to_inch) * inch_to_cm << " cm";
			cout << " OR " << ((len * ft_to_inch) * inch_to_cm) / meter_to_cm << " m";
		}
		else if (unit == "y" || unit == "yard" || unit == "meter" || unit == "km" || unit == "gallons")
			cout << "Sorry,  we don't take this units as input. Press anything to continue OR Ctrl^Z to terminate";
		else
			cout << "Incorrect unit input. Press anything to continue OR Ctrl^Z to terminate";

		//compute smallest and largest
		if (cnt == 0)
			smallest = largest = len_in_meter;
		else {
			if (len_in_meter < smallest) smallest = len_in_meter;
			if (len_in_meter > largest) largest = len_in_meter;			
		}			
		cout << "\nSmallest value so far is: " << smallest << " m";
		cout << "\nLargest value so far is: " << largest << " m";

		lens_in_meter.push_back(len_in_meter);

		cout << "\n";
		cnt++;
	}//end while taking input

	sort(lens_in_meter.begin(), lens_in_meter.end());
	cout << "\nLengths in meter entered so far are : ";
	for (double len : lens_in_meter)
		cout << len << "  ";
	cout << "\n";

}//end of length_conversion()

void number_guessing_game() {	
	vector<int> numbers;
	cout << "I'm trying to guess the number that you're thinking about.\n Please answer 'y' or 'no'\n\n";
	cout << "Is the number less than 50?\n";
	for (char answer; cin >> answer;) {		
		if (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N') 
			cout << "You have to answer 'y' or 'n' or 'Y' or 'N'";		
		else {			
			if (answer == 'y' || answer == 'Y') { //the number is less than 50
				cout << "Is the number even?\n";
				cin >> answer;
				if (answer == 'y' || answer == 'Y') { // the number is even
					cout << "Is the square root of the number less than 5?\n";
					cin >> answer;
					if (answer == 'y' || answer == 'Y') { // the number is in range 2 - 24
						cout << "Is the number less than or equal to a dozen?\n";
						cin >> answer;
						if (answer == 'y' || answer == 'Y') { //the number is in range 2 - 12
							cout << "Is the number present the month in the first half of a year?\n";
							cin >> answer;
							if (answer == 'y' || answer == 'Y') { // the number is in the range of 2 - 6
								numbers.push_back(2);
								numbers.push_back(4);
								numbers.push_back(6);
								cout << "Is it " << numbers[0]<<"\n";
								cin >> answer;
								if (answer == 'y' || answer == 'Y') {
									cout << "Hey, I found the number that you're thinking about, it's " << numbers[0] << "\n";
								}
								else {
									cout << "Is it " << numbers[1] << "\n";
									cin >> answer;
									if (answer == 'y' || answer == 'Y') {
										cout << "Hey, I found the number that you're thinking about, it's " << numbers[1] << "\n";
									}
									else 
										cout << "Hey, I found the number that you're thinking about, it's " << numbers[2] << "\n";
								}

							}
							else { // the number is in the range of 8 - 12
							}
						}
						else { //the number is in the range of 14 to 24						
						}
					}
					else { //the number if in range 26 - 48
					}
				}
				else {//the number is odd
				}
			}
			else { //the number is more than or equal to 50
			}
		} 
	}
}//end of number guessing game

void route_cities() {
	vector<double> distances;
	cout << "Enter routes between 2 cities\n";

	for (double distance; cin >> distance;)
		distances.push_back(distance);

	sort(distances.begin(), distances.end());

	cout << "Shortest distance is : " << distances[0] << " Longest distance is: " << distances[distances.size()-1] << "\n";
	cout << "Mean distance is " << (distances[0] + distances[distances.size()-1]) / 2 << "\n";
}

void calculator() {
	cout << "Please enter 2 numbers followed by an operator\n";
	int num1, num2;
	string s1, s2;
	char c_operator;
	int pos;
	string s_arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> s_vec(s_arr, s_arr + sizeof(s_arr) / sizeof(string));
	
	while (cin >> s1 >> s2 >> c_operator) {
		if (check_string_is_integer(s1)) 
			num1 = stoi(s1);		
		else {
			if ((pos = find_string_in_vec(s_vec, s1)) != -1)
				num1 = pos;
			else {
				cout << "We cannot calculate this number " << s1 << "\n";
				return;
			}
		}
	
		if (check_string_is_integer(s2)) 
			num2 = stoi(s2);			
		else {
			ptrdiff_t it = find(s_vec.begin(), s_vec.end(), s2) - s_vec.begin();
			if (it >= s_vec.size()) {
				cout << "We cannot calculate this number " << s2 << "\n";
				return;
			}
			else
				num2 = it;
		}

		if (num1 <= 0 || num1 >= 10) {
			cout << s1 << " is out of range 0-9" << " .We cannot calculate this number\n";
		}
		if (num2 <= 0 || num2 >= 10) {
			cout << s2 << " is out of range 0-9" << " .We cannot calculate this number\n";
		}
	
		if (c_operator == '+')	
			cout << num1 + num2 << "\n";		
		else if (c_operator == '-')
			cout << num1 - num2 << "\n";
		else if (c_operator == '*')
			cout << num1 * num2 << "\n";
		else if (c_operator == '/')
			cout << num1 / num2 << "\n";
	}
}

void string_to_number() {
	string n;
	int i;	
	int pos = -1;		
		
	string s_arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> s_vec(s_arr, s_arr + sizeof(s_arr)/sizeof(string));
	

	while (cin >> n) {
		if (check_string_is_integer(n)) {
			i = stoi(n);
			if (i < 10 && i >= 0)
				cout << s_vec[i] << "\n";
			else if (i >= 10)
				cout << "Sorry, the number is not in out list\n";
		}
		else {			
			/*if ((pos = find_string_in_vec(s_vec, n)) != -1)
				cout << pos << "\n";
			else {
				pos = -1;
				cout << "Sorry, we have not found the integer\n";
			}*/
			//C++ 98
			ptrdiff_t it = find(s_vec.begin(), s_vec.end(), n) - s_vec.begin();			
			if (it >= s_vec.size())
				cout << "The term is not in our list\n";
			else
				cout << it << "\n";
		}
	}
}

int find_string_in_vec(const vector<string> &v, string const s) {
	int r = -1;
	for (string temp : v) {
		++r;
		if (temp == s) {			
			return  r;
		}
	}
	return -1;
}

bool check_string_is_integer(const string& s) {	
	for (char c : s) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

void chess_game_price() {
	long sum = 0; 	
	int threshold_1000 = false;
	int threshold_1mil = false;
	int threshold_1bil = false;
	for (int i = 0; i < 64; ++i) {
		sum += pow(2,i);
		if (sum >= 1000) {
			if (!threshold_1000) {
				threshold_1000 = true;
				cout << "There should be " << i + 1 << " squares to get 1000 grains of rice\n";
			}
		}
		if (sum >= 1000 * 1000) {
			if (!threshold_1mil) {
				threshold_1mil = true;
				cout << "There should be " << i + 1 << " squares to get 1 million grains of rice\n";
			}
		}
		if (sum >= 1000 * 1000 * 1000) {
			if (!threshold_1bil) {
				threshold_1bil = true;
				cout << "There should be " << i + 1 << " squares to get 1 billion grains of rice\n";
			}
		}
	}
}

void rock_paper_scissors() {
	int player_choice;		
	int computer_choice = 0;
	srand((int)time(NULL));

	cout << "Please enter your choice (1: Rock, 2: Paper, 3: Scissors)\n";	
	
	while (cin >> player_choice) {		
		computer_choice = (rand() % 3) + 1;
		/*cout << "Computer choice was : " << computer_choice << "\n";
		continue;*/
		if (player_choice < 1 || player_choice > 3) {
			cout << "Please enter 1 of the following options: 1: Rock, 2: Paper, 3: Scissors)\n";
			continue;
		}
		cout << "Player choice test: " << player_choice << "\n";
		switch (player_choice) {
			case 1:
				cout << "Your choice was Rock\n";
				switch (computer_choice) {
				case 1:
					cout << "My choice was also Rock\nWe draw\n";
					break;
				case 2:
					cout << "My choice was paper\nYou loose\n";
					break;
				case 3:
					cout << "My choice was scissors\nYou win\n";
					break;
				default:
					break;
				}
				break;
			case 2:
				cout << "Your choice was Paper\n";
				switch (computer_choice) {
				case 1:
					cout << "My choice was Rock\nYou win\n";
					break;
				case 2:
					cout << "My choice was also paper\nWe draw\n";
					break;
				case 3:
					cout << "My choice was scissors\nYou lose\n";
					break;
				default:
					break;
				}
				break;
			case 3:
				cout << "Your choice was Scissors\n";
				switch (computer_choice) {
				case 1:
					cout << "My choice was Rock\nYou lose\n";
					break;
				case 2:
					cout << "My choice was paper\nYou win\n";
					break;
				case 3:
					cout << "My choice was also scissors\nWe draw\n";
					break;
				default:
					break;
				}
				break;
			default:
				break;
		}//end of switch player choice
	}//end of while
}//end of rock_paper_scissor game

void prime_number_find() {
	int max;
	bool is_prime;
	vector<int> primes;
	
	primes.push_back(2);

	cout << "Select a number to define a range of primes from 1 to your selected number\n";
	cin >> max;

	for (int i = 3; i <= max; ++i) {
		is_prime = true;
		for (int j = 2; j < i; ++j) {
			if (i%j == 0) {
				is_prime = false;
				break;
			}
		}//inner for
		if (is_prime)
			primes.push_back(i);
	}//outer for

	//check prime vector
	cout << "The prime numbers from 1 to " << max << " are: \n";
	for (int prime : primes)
		cout << prime << " ";
	cout << "\n";
}//end of prime_number_find()