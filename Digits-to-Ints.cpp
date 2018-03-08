/*
Input - Conversion (vector of digits to int) - Print 
*/

constexpr digit_limit = 4; 			//Added to prevent "magic number", plus allows for easier expansion of program in future

int vector_to_int(vector<int>v, int unit_marker){
	int result = 0; 
	for (int i = 0; i < unit_marker; i++){
		result = result * 10 + v[i];
	}
	return result; 
}

void print_results(vector<int>digits, int unit_marker){
//Prints the result of a vector turned into an int, with corresponding units, from a different vector 	
	vector<string>units { "One", "Ten", "Hundred", "Thousand" };
	int result = vector_to_int(digits, unit_marker);
	
	cout << result << " is comprised of "; 
	for (int x = unit_marker; x > 0; x--){
		cout << digits[x] << " " << units[x];
		if (digits[x] > 1) "s, "; 		//adds 's' when needed to ensure continuity for user
		else cout << ", "; 
	}
}

int main(){
//takes chars from user and places them into a vector<int>	
//Pre-condition: user must enter either a number between 0-9, a semi-colon or a space
//Post-condition: user input must be <= 4 digits				 
	try{		
		while (true){
			char c;
			int unit_marker = 0;				//sets iterations for print_results()
			vector<int>intvals(digit_limit);

			for (int x = 0; x < digit_limit; x++){
				cin >> c; 
				if (c == ';' || c == ' ') break;
				if (c < '0' || c > '9') error("main() pre-condition");
				if (intvals.size(); + 1 > digit_limit) error("main() post-condition);
				intvals[x] = c - '0'; 
				unit_marker++;
			}									     
			print_results(intvals, unit_marker);
			if (c == ';') break;									     
		}
	}
	catch (exception& e){
		cerr << "Error: " << e.what() << '\n';
	}
	catch (...){
		cerr << "Unknown error \n";
	}
}
