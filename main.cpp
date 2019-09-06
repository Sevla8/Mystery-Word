#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

#define MAX_ATTEMPTS 5
#define DICO "dico.txt"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;

const int init();
const string mix(const string&);
const int countLines(const string&);
const string getConsoleWord();
const string getDictionaryWord();
void play(const string&, bool*);
void play1();
void play2();

const int init() {
	cout << "Select : " << endl << "1 Player - 1" << endl << "2 Players - 2" << endl;
	string players;
	getline(cin, players);
	while (players != "1" && players != "2") {
		cout << "Select between '1' and '2'" << endl;
		getline(cin, players);
	}
	return players == "1" ? 1 : 2;
}

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

const int countLines(const string& filename) {
	ifstream file(filename);

	int lines(0);
	string word;
	while (file >> word)
		lines += 1;

	return lines;
}

const string getConsoleWord() {
	string word;
	cout << "Select a word" << endl;
	cin >> word;
	return word;
}

const string getDictionaryWord(const string filename) {
	int lines = countLines(filename);

	int random(rand() % lines);

	ifstream file(filename);

	string word;
	while (random != 0) {
		file >> word;
		random -= 1;
	}

	return word;
}

void play(const string& word, bool* again) {
	string mystery;
	mystery = mix(word);

	int count(MAX_ATTEMPTS);

	bool found(false);
	string attempt("");
	while (!found && count != 0) {
		cout << endl << "What is the correct word ? " << mystery << " - " << count << " attempts letf" << endl;
		cin >> attempt;
		if (attempt == word) {
			found  = true;
			cout << endl << "Congratulation ! Found in " << MAX_ATTEMPTS - count + 1 << " attempts." << endl;
		}
		else {
			count -= 1;
			cout << "This is not the correct word !" << endl;
		}
		if (count == 0)
			cout << "The correct word was " << word << endl;
	}

	cout << endl << "Do you want to play again ? (y/n)" << endl;
	string answer;
	getline(cin, answer);
	while (answer != "y" && answer != "n") {
		cout << endl << "Select between 'y' and 'n'" << endl;
		getline(cin, answer);
	}
	if (answer == "n")
		*again = false;
}

void play1() {
	bool again = true;

	do {
		string word;
		word = getDictionaryWord(DICO);

		play(word, &again);

	} while (again);
}

void play2() {
	bool again = true;

	do {
		string word;
		word = getConsoleWord();

		play(word, &again);

	} while (again);
}

int main(int argc, const char** argv) {

	const int players(init());

	srand(time(0));

	if (players == 1) {
		play1();
	}
	else {
		play2();
	}

	cout << endl << "Bye Bye !" << endl;

	return 0;
}
