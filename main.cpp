#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const string mix(const string& word) {
	string mystery("");
	string tmp(word);
	while (tmp != "") {
		int index;
		index = rand() % tmp.size();

		mystery += tmp[index];
		tmp.erase(index, 1);
	}
	return mystery;
}

int main(int argc, const char** argv) {

	srand(time(0));

	string word;
	cout << "Select a word" << endl;
	cin >> word;

	string mystery;
	mystery = mix(word); 

	bool found(false);
	string attempt("");
	while (!found) {
		cout << endl << "What is the correct word ? " << mystery << endl;
		cin >> attempt;
		if (attempt == word)
			found  = true;
		else 
			cout << "This is not the correct word !" << endl;
	}

	cout << endl << "Congratulation !" << endl;

	return 0;
}
