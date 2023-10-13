#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int array[500];
int pointer = 0, user_input;
char input;
bool integer_mode = true;

string code = "";
bool collecting_code = false;

void eval(char input) {
	switch (input) {

		//pointer management
		case '>':
			pointer = (pointer + 1) % 500;
			break;

		case '<':
			pointer--;
			if (pointer < 0) pointer += 500;
			break;
			
		//increment and decrement
		case '+':
			::array[pointer]++;
			break;

		case '-':
			::array[pointer]--;
			break;

		//input and output
		case 'o':
			if (integer_mode) cout << ::array[pointer];
			else cout << (char) ::array[pointer];
			break;

		case 'p':
			cin >> user_input;
			::array[pointer] = user_input;
			break;

		//symbols
		case 'n':
			cout << "\n";
			break;

		case 's': 
			cout << " ";
			break;

		//output modes
		case 'i':
			integer_mode = true;
			break;
			
		case 'c':
			integer_mode = false;
			break;
	}
}

void eval_code(string code) {
	while (true) {
		for (char elem : code) {
			if (elem == 'b') break;
			else eval(elem);
		}
		if (::array[pointer] == 0) break;
	}
}

int main() {
	ifstream compile_file("main.fkys");
	int array[500];
	for (int i = 0; i < 500; i++) array[i] = 0;

	int pointer = 0, user_input;
	char input;

	bool integer_mode = true;

	while (compile_file >> input && input != 'e') {
		if (!collecting_code) eval(input);
		else code += input;
		
		if (input == '[') {
			collecting_code = true;
		} else if (input == ']') {
			collecting_code = false;
			eval_code(code);
			code = "";
		}
	}

	cout << "\n" << code;
	cout << "\nProgram ended." << endl;
	return 0;
}
