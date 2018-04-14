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

	cout << "                                          __ " << endl;
	cout << " _____ _            _ _ _           _    |  |" << endl;
	cout << "|  _  | |___ _ _   | | | |___ ___ _| |___|  |" << endl;
	cout << "|   __| | .'| | |  | | | | . |  _| . |_ -|__|" << endl;
	cout << "|__|  |_|__,|_  |  |_____|___|_| |___|___|__|" << endl;
	cout << "            |___|                            " << endl;

	//Itens do menu
	bool anotherGame = false;
	do {

		cout << "   ___________________________________________ " << endl;
		cout << "//|            **   Play Words   **           |\\\\" << endl;
		cout << "\\\\|               Choose a game               |//" << endl;
		cout << " \\\\___________________________________________// " << endl;
		cout << "   |//                 1                   \\\\|   " << endl;
		cout << "   ||         Is word in world list?        ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 2                   \\\\|   " << endl;
		cout << "   ||         Guess scrambled word          ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 3                   \\\\|   " << endl;
		cout << "   ||    Words from given set of letters    ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 4                   \\\\|   " << endl;
		cout << "   ||    Build word out of random letters   ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 5                   \\\\|   " << endl;
		cout << "   ||         Wildcard word search          ||   " << endl;
		cout << "   |\\\\_____________________________________//|   " << endl;

		cout << endl << "Choose game: " << endl;

		//Escolher jogo
		size_t choice;
		bool validChoice = false;
		do {

			pw::takeInput(choice);
			if (choice < 1 || choice > 5) {
				validChoice = false;
				cout << "No such game, try again." << endl;
			} else {
				validChoice = true;
			}
		} while (!validChoice);

		switch (choice) {
			case (1):
				checkWordinList(file);
				break;
			case (2):
				guessScrambledWord(file);
				break;
			case (3):
				searchLetterSet(file);
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

		validChoice = false;
		string playAnotherGameChoice;
		cout << "Do you want to play another game? (y/n)";
		do {
			pw::readString(playAnotherGameChoice);
			playAnotherGameChoice = pw::trim(playAnotherGameChoice);
			playAnotherGameChoice = pw::makeUpper(playAnotherGameChoice);

			if (!playAnotherGameChoice.compare("Y")) {
				file.clear();
				file.seekg(0);
				anotherGame = true;
				validChoice = true;
			} else if (!playAnotherGameChoice.compare("N")) {
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
