int vector_to_int(vector<int>v, int unit_marker) {
	int result = 0;
	for (int i = 0; i < unit_marker; i++) {
		result = result * 10 + v[i];
	}
	return result;
}

void print_results(vector<int>digits, int unit_marker) {
	//Prints the result of a vector turned into an int, with corresponding units, from a different vector 	
	int result = vector_to_int(digits, unit_marker);
	vector<string>units{ "Thousand", "Hundred", "Ten", "One" };
	cout << result << " is comprised of \n";
	for (int x = 0; x < unit_marker; x++) {
		cout << digits[x] << " " << units[x + 4 - unit_marker] << '\n';
	}
	cout << '\n';
}

int main() {
	//takes chars from user and places them into a vector<int>	
	//Pre-condition: user must enter either a number between 0-9, a semi-colon or a space
	//Post-condition: user input must be <= 4 digits				 
	try {
		while (true) {
			char c;
			int unit_marker = 0;				//sets iterations for print_results()
			vector<int>digits(4);

			for (int x = 0; x < 4; x++) {
				cin >> c;
				if (c == ';' || c == 'q') break;
				if (c < '0' || c > '9') error("main() pre-condition");
				if (digits.size() > 4) error("main() post-condition");
				digits[x] = c - '0';
				unit_marker++;
			}
			print_results(digits, unit_marker);
		}
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << '\n';
	}
	catch (...) {
		cerr << "Unknown error \n";
	}
}
