#include "playWordsUtils.h"

using namespace std;

void pw::readString(string &var) {
	//Funcao expecificamente para ler strings
	bool validInput = false;
	do {
		validInput = false;
		getline(cin, var);
		if (cin.fail()) {
			validInput = false;
			cout << "Invalid input, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		} else {
			validInput = true;
		}
	} while (!validInput);
}

bool pw::isWordPartOfSet(string word, vector<char> set) {
	//Verifica se uma palavra e construida so com letras de um conjunto das mesmas
	//ATENCAO: retorna falso se a palavra letras iguais a mais, ex:
	//	conjunto : C O E R R
	//	palavra : CORRER (palavra usa um R a mais)
	for (char c : word) {
		auto iter = find(set.begin(), set.end(), c);
		if (iter != set.end()) {
			set.erase(iter);
		} else {
			return false;
		}
	}

	return true;
}