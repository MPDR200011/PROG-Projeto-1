#include <iostream>
#include <fstream>
#include "playWordsUtils.h"
#include "router.h"

using namespace std;

int main() {
	//Fase de abertura da word list
	ifstream file;
	cout << "Word list file ? ";
	bool validFile = false;
	string fileName;
	do {
		pw::readString(fileName);
		file.open(fileName);
		if (!file.is_open()){
			cout << "File not found, try again." << endl;
			validFile = false;
		} else {
			cout << "File found!!!" << endl;
			validFile = true;
		}
	} while (!validFile);

	//Itens do menu
	vector<string> menu = {
		"4 - Random N Letters (Try to create a word using a set of N random characters).",
		"5 - Search Wildcard (Input a word with a wildcard and it will show all words that match)."
	};

	bool anotherGame = false;
	cout << "Welcome to Playwords!!!" << endl << endl;
	do {

		if (anotherGame) {
			file.open(fileName);
		}

		//Imprimir menu
		for (string menuItem : menu) {
			cout << menuItem << endl;
		}

		//Escolher jogo
		cout << endl << "Choose the game: ";
		size_t choice;
		bool validChoice = false;
		do {

			pw::takeInput(choice);
			if (choice < 1 || choice > 5) {
				validChoice = false;
				cout << "No such game, try again.";
			} else {
				validChoice = true;
			}
		} while (!validChoice);

		switch (choice) {
			case (1):
				break;
			case (2):
				break;
			case (3):
				break;
			case (4):
				randomNLetters(file);
				break;
			case (5):
				searchWildcard(file);
				break;
			default:
				break;
		}

		file.close();

		validChoice = false;
		string playAnotherChoice;
		cout << "Do you want to play another game? (y/n)";
		do {
			pw::readString(playAnotherChoice);
			playAnotherChoice = pw::trim(playAnotherChoice);
			playAnotherChoice = pw::makeUpper(playAnotherChoice);

			if (!playAnotherChoice.compare("Y")) {
				anotherGame = true;
				validChoice = true;
			} else if (!playAnotherChoice.compare("N")) {
				anotherGame = false;
				validChoice = true;
			} else {
				cout << "Invalid answer, try again." << endl;
				validChoice = false;
			}

		} while (!validChoice);
	} while (anotherGame);

	if (file.is_open()) {
		file.close();
	}

	return 0;
}