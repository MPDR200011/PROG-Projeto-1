#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

// visualizar palavras com um set de letras
void searchLetterSet(ifstream &file) {			

	vector<string> wordList;
	string temp;
	while (getline(file, temp)) {
		wordList.push_back(temp);
	}

	string letras_in;
	string letras_mid;
	string letras = string();
	cout << "Insira agora as letras que fazem parte do conjunto: ";
	getline(cin, letras_in);
	size_t compin = letras_in.length();
	size_t comp = letras.length();

	// remove espacos e qlqr simbolo e poe tudo em maiusculas
	for (char c : letras_in) {                        
		if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
			letras.push_back(toupper(c));
		}
	}

	// mostra o set de letras
	cout << letras << endl;                                  

	cout << endl << endl << "As palavras as quais pertencem todas as letras do conjunto sao: " << endl;

	bool pertence = false;
	for (string wordInList: wordList) {
		pertence = true;
		for (char c: letras) {
			if (wordInList.length() > letras.length()) {
				pertence = false;
				break;
			}
			if (!pw::isCharMember(c, wordInList)) {
				pertence = false;
				break;
			}
		}
		if (pertence == true) {
			cout << wordInList << endl;
		}
	}

	pw::endGame();

}