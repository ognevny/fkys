#include <fstream>
#include <iostream>
using namespace std;

int array[500];
int pointer = 0, user_input;
char input;
bool integer_mode = true;

void eval(char input) {
	switch (input) {

		//pointer management
		case '>':
			pointer++;
			if (pointer > 500) pointer -= 500;
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

		//newline
		case 'n':
			cout << "\n";
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


int main() {
	ifstream compile_file("main.fkys");
	int array[500];
	for (int i = 0; i < 500; i++) array[i] = 0;

	int pointer = 0, user_input;
	char input;

	bool integer_mode = true;

	while (compile_file >> input && input != 'e') {
		eval(input);
	}
	
	cout << "\nProgram ended." << endl;
	return 0;
}
