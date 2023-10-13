#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream compile_file("main.fkys");
	int array[500];
	for (int i = 0; i < 500; i++) array[i] = 0;

	int pointer = 0, user_input;
	char input;

	while (compile_file >> input && input != 'e') {
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
				array[pointer]++;
				break;
			case '-':
				array[pointer]--;
				break;

			//input and output
			case 'o':
				cout << array[pointer];
				break;
			case 'p':
				cin >> user_input;
				array[pointer] = user_input;
				break;

			//newline
			case 'n':
				cout << "\n";
				break;
		}
	}
	cout << "\nProgram ended." << endl;
	return 0;
}
