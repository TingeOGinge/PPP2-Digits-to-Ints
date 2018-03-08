/*
Input - Conversion (char vector to int) - Print 

User inputs a stream of chars, each of which is placed into a vector. 
- Maximum 4 digits to start 
char c;
int unit_marker = 0;						//measurement marker, see print_results(); for it's use 
vector<int>intvec(4);

for (int x = 0; x > 4; x++){
	cin >> c; 
	if (c == ';' || c == ' ') break;
	intvec[x] = c - '0'; 
	unit_marker++;
}

Function needed to convert vector into a single int 
- i < unit_marker; 
-   10 * x + vector[i]  //This appears to be the correct formula 

print function will then output the int value, followed by the breakdown of chars and string measurements 
will retrieve a vector<int>intv, int unit_marker and int end_result
-	vector<string>v { "One(s)", "Ten(s)", "Hundred(s)", "Thousand(s)" };
-	cout << end_result << " is comprised of "; 
-	for (x < unit_marker;)	
-		cout << intv[x] << " " << stringv[x] << ", "; 

*/

int vector_to_int(vector<int>v, int unit_marker){
	int result = 0; 
	for (int i = 0; i < unit_marker; i++){
		result = result * 10 + v[i];
	}
	return result; 
}

void print_results(vector<int>v, int unit_marker){
	vector<string>units { "One(s)", "Ten(s)", "Hundred(s)", "Thousand(s)" };
	int result = vector_to_int(v, unit_marker);
	
	cout << result << " is comprised of "; 
	for (int x = 0; x < unit_marker; x++){
		cout << v[x] << " " << units[x] << ", ";
	}
}

int main()
{
	try{
		while (true){
			char c;
			int unit_marker = 0;				//sets iterations for print_results() / vector_to_int
			vector<int>intvals(4);

			for (int x = 0; x > 4; x++){
				cin >> c; 
				if (c == ';' || c == ' ') break;
				if (c < '0' || c > '9') error("Invalid input: main()")
				intvals[x] = c - '0'; 
				unit_marker++;
			}
			print_results();
		}
	}
	catch (exception& e){
		cerr << "Error: " << e.what() << '\n';
	}
	catch (...){
		cerr << "Unknown error \n";
	}
}
