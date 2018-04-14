#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

// Adivinhar uma palavra baralhada
void guessScrambledWord(ifstream &file) {			

	vector<string> wordList;
	string temp;
	while (getline(file, temp)) {
		wordList.push_back(temp);
	}

	srand(time(NULL));
	int wordIndex = rand() % wordList.size();
	string wordToGuess = wordList[wordIndex];
	string scrambledWord = pw::scramble(wordToGuess);

	cout << scrambledWord << endl << endl;

	string guessWord; 
	int tries = 3;
	bool lost = false;

	cout << "Make a guess: ";
	while (!lost) {
		pw::readString(guessWord);
		guessWord = pw::trim(guessWord);
		guessWord = pw::makeUpper(guessWord);
		if (!guessWord.compare(wordToGuess)) {
			break;
		} else {
			if (!--tries) {
				lost = true;
			} else {
				cout << "Wrong guess, try again: ";
			}
		}
	}

	if (!lost) {
		cout << endl << "You won! Congratulations!" << endl;
	} else {
		cout << endl << "You lost, better luck next time." << endl;
		cout << "The answer was " << wordToGuess << endl;
	}

	pw::endGame();

}