#include <iostream>
#include "playWordsUtils.h"
#include "router.h"

using namespace std;

int main() {
	//Fase de abertura da word list
	ifstream file;
	cout << "Word list file ? ";
	bool validFile = false;
	do {
		string fileName;
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

	//Imprimir menu
	vector<string> menu = {
		"4 - Random N Letters (Try to create a word using a set of N random characters)"
	};

	cout << "Welcome to Playwords!!!" << endl << endl;
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
		case (1) :
			break;
		case (2):
			break;
		case (3):
			break;
		case (4) :
			randomNLetters(file);
			break;
		case (5) : 
			break;
		default :
			break;
	}

	return 0;
}