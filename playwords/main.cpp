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
	bool anotherGame = false;
	do {

		cout << "                                          __ " << endl;
		cout << " _____ _            _ _ _           _    |  |" << endl;
		cout << "|  _  | |___ _ _   | | | |___ ___ _| |___|  |" << endl;
		cout << "|   __| | .'| | |  | | | | . |  _| . |_ -|__|" << endl;
		cout << "|__|  |_|__,|_  |  |_____|___|_| |___|___|__|" << endl;
		cout << "            |___|                            " << endl;
		cout << " ___________________________________________ " << endl;
		cout << "//|     **   Bem vindo a Play Words!   **     |\\\\" << endl;
		cout << "\\\\|             Escolha uma opcao             |//" << endl;
		cout << " \\\\___________________________________________// " << endl;
		cout << "   |//                 1                   \\\\|   " << endl;
		cout << "   ||    Palavra pertence ao dicionario?    ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 2                   \\\\|   " << endl;
		cout << "   ||           Adivinhar palavra           ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 3                   \\\\|   " << endl;
		cout << "   ||  Palavras existentes com letras dadas ||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 4                   \\\\|   " << endl;
		cout << "   ||Construir palavra com letras aleatorias||   " << endl;
		cout << "   |\\\\                                     //|   " << endl;
		cout << "   |//                 5                   \\\\|   " << endl;
		cout << "   ||   Palavras com characteres Wildcard   ||   " << endl;
		cout << "   |\\\\_____________________________________//|   " << endl;

		if (anotherGame) {
			file.open(fileName);
		}

		//Escolher jogo
		size_t choice;
		bool validChoice = false;
		do {

			pw::takeInput(choice);
			if (choice < 1 || choice > 5) {
				validChoice = false;
				cout << "Esse jogo nao existe, tente outra vez.";
			} else {
				validChoice = true;
			}
		} while (!validChoice);

		switch (choice) {
			case (1):
				func1(file);
				break;
			case (2):
				func2(file);
				break;
			case (3):
				func3(file);
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
