#include "std_lib_facilities.h"

constexpr int digit_limit = 4;		//Added to prevent a 'magic number', but also to help expand the program in the future if needed 

int vector_to_int(vector<int>v, int marker) {
//Converts a series of digits from a vector into a single int e.g. { 3, 2, 1 } = 321
	int result = 0;
	for (int i = 0; i < marker; i++) {
		result = result * 10 + v[i];
	}
	return result;
}


void print_results(vector<int>digits, int marker) {
//Prints the result of a vector turned into an int, with corresponding units, from a different vector 	
	int result = vector_to_int(digits, marker);
	vector<string>units{ "Thousand", "Hundred", "Ten", "One" };
	cout << result << " is comprised of \n";
	for (int x = 0; x < marker; x++) {
		cout << digits[x] << " " << units[x + digit_limit - marker];
		if (digits[x] > 1 || digits[x] == 0) cout << "s";		//pluralises the units if necessary
		if (x < marker - 1) cout << " and ";				//adds conjunction if necessary 
	}
	
	cout << '\n';
}

int main() {
//takes chars from user and places them into a vector<int>	
//Pre-condition: user must enter either a digit between 0-9, a semi-colon or a space	
//Post-condition: user cannot enter a number larger than 9999
	try {
		cout << "Enter any number between 0 - 9999 \n"
			"Press ; to run the program \n"
			"Press q to quit \n";
		while (true) {
			char c = ' ';
			int marker = 0;				//sets iterations for print_results()
			vector<int>digits(4);

			for (int x = 0; c != ';'; x++) {
				cin >> c;
				if (c == 'q' || c == ';') break;
				if (c < '0' || c > '9') error("main() pre-condition");
				marker++;
				if (marker > digit_limit) error("main() post-condition");
				digits[x] = c - '0';
			}
			if (c == 'q') break;
			print_results(digits, marker);
		}
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Unknown error \n";
	}
}
