#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

void guessScrambledWord(ifstream &file) {			// Adivinhar uma palavra baralhada

	vector<string> wordList;
	string temp;
	while (getline(file, temp)) {
		wordList.push_back(temp);
	}

	srand(time(NULL));
	int wordIndex = rand() % wordList.size();
	string word = wordList[wordIndex];
	string scrWord = pw::scramble(word);
	string guessWord;

	cout << scrWord << endl << endl;

	cout << "Make a guess: ";

	for (int v = 3; v >= 0; v--) {

		if (v == 0) {
			cout << endl << "You lost, the answer was " << word << "!" << endl;
			break;
		}

		pw::readString(guessWord);
		guessWord = pw::trim(guessWord);
		guessWord = pw::makeUpper(guessWord);
		if (word == guessWord) {
			cout << endl << "You won! Congratulations!" << endl;
			break;
		} else {
			cout << "Wrong guess, try again: ";
		}
	}

	pw::endGame();

}