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


	bool anotherGame = false;
	do {

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
				func1();
				break;
			case (2):
				func2();
				break;
			case (3):
				func3();
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
// funcoes side
bool isMember_word(string word, vector<string> list) {

	for (unsigned i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
	}

	for (unsigned i = 0; i < list.size(); i++) {
		if (word == list[i])
			return true;
	}
	return false;
}

string scramble(string word) {
	string scramb = word;
	for (unsigned i = 0; i < scramb.length(); i++) {
		unsigned j = rand() % scramb.length();
		swap(scramb[i], scramb[j]);
	}
	return scramb;
}

bool char_pertence(char ch, string word) {
	for (unsigned i = 0; i < word.length(); i++) {
		if (ch == word[i]) {
			return true;
		}
	}
	return false;
}


//funcoes main

void func1(vector<string> wordList) {			// Verificar se palavra pertence ao dicionario
	string word;
	cout << "Insira a palavra que quer pesquisar: "; cin >> word;
	cout << '\n';

	if (isMember_word(word, wordList)) { cout << "A palavra " << word << " pertence ao dicionario.\n"; }
	else { cout << "A palavra " << word << " nao pertence ao dicionario.\n"; }
}

void func2(vector<string> wordList) {			// Adivinhar uma palavra baralhada
	int wordIndex = rand() % wordList.size();
	string word = wordList[wordIndex];
	string scrWord = scramble(word);
	string guessWord;
	cout << scrWord << "\n\n";
	for (int v = 3; v >= 0; v--) {
		if (v == 0) {
			cout << '\n' << "Perdeu! A resposta era " << word << "!\n";
			break;
		}
		cin >> guessWord;
		if (word == guessWord) {
			cout << '\n' << "Acertou! Parabens!\n";
			break;
		}
	}
}

void func3(vector<string> wordList) {			// visualizar palavras com um set de letras
	string letras_in;
	string letras_mid;
	string letras;
	cout << "Insira agora as letras que fazem parte do conjunto:\n";
	cin.ignore();
	getline(cin, letras_in);
	size_t compin = letras_in.length();
	size_t comp = letras.length();

	for (unsigned i = 0; i < compin; i++) {                        // remove espacos e qlqr simbolo e poe tudo em maiusculas
		if ((letras_in[i] > 64 && letras_in[i] < 91) || (letras_in[i] > 96 && letras_in[i] < 123)) {
			letras = letras + char(toupper(letras_in[i]));
		}
	}

	cout << letras << '\t';                                  // mostra o set de letras

	cout << "\n\n" << "As palavras as quais pertencem todas as letras do conjunto sao:\n";
	bool pertence = false;
	for (unsigned i = 0; i < wordList.size(); i++) {
		pertence = true;
		for (unsigned j = 0; j < letras.length(); j++) {
			if (sizeof(wordList[i]) > letras.length()) {
				pertence = false;
				break;
			}
			if (!char_pertence(letras[j], wordList[i])) {
				pertence = false;
				break;
			}
		}
		if (pertence == true) {
			cout << wordList[i] << '\n';
		}
	}
}