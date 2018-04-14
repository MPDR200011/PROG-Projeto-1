#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

// Verificar se palavra pertence ao dicionario
void checkWordinList(ifstream &file) {			
	vector<string> wordList;
	string temp;
	while (getline(file, temp)) {
		wordList.push_back(temp);
	}

	string word;
	cout << "Insert the word you want to search: ";
	pw::readString(word);
	word = pw::trim(word);
	word = pw::makeUpper(word);
	cout << endl;

	if (pw::isWordMember(word, wordList)) { 
		cout << word << " is in the dictionary" << endl; 
	} else { 
		cout << word << " is not in the dictionary." << endl; 
	}

	pw::endGame();
}