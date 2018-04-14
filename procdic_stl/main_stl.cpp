#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "wordUtils.h"

using namespace std;
set<string> finalSet; //vetor com todas as palavras
set<string> wordSets[26]; //lista com vetores para cada letra inicial

int main() {
	string line;
	string inFileName, outFileName;
	bool inputFail = false;

	ifstream fileInput;
	ofstream fileOutput;



	//Input file request
	cout << "Dictionary file ? ";
	do {
		getline(cin, inFileName);
		if (cin.fail()) {
			inputFail = true;
			cout << "Invalid input, try again." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			fileInput.open(inFileName);
			if (fileInput.is_open()) {
				inputFail = false;
			} else {
				inputFail = true;
				cout << "File not found, try again." << endl;
			}
		}

	} while (inputFail);

	//Output file request
	cout << "Word list file  ? ";
	do {
		inputFail = false;
		getline(cin, outFileName);
		if (cin.fail()) {
			inputFail = true;
			cout << "Invalid input, try again." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			fileOutput.open(outFileName);
			if (fileOutput.is_open()) {
				inputFail = false;
			} else {
				inputFail = true;
				cout << "Something went wrong, try again." << endl;
			}
		}
	} while (inputFail);

	//Word extraction fase
	cout << endl << "Extracting simple words from file " << inFileName << "," << endl;
	if (fileInput.is_open()) {
		
		while (getline(fileInput, line)) {

			if (isLineValid(line)) {

				for (string word : splitLine(line, ';')) {

					if (isSingleWord(word)) {

						wordSets[word.at(0) - 65].insert(word);
					}
				}
			}
		}

		fileInput.close();
	} else {
		cout << "file not found" << endl;
	}

	//Word counting fase
	cout << "beginning with letter ...";
	for (int i = 0; i < 26; i++) {
		cout << endl << (char) (65 + i) << endl;
		int wordCount = 0;
		for (string word : wordSets[i]) {
			++wordCount;
			finalSet.insert(word);
			if (wordCount % 100 == 0) {
				cout << ".";
			}
		}
	}

	cout << endl << "Number of non-duplicate simple words = " << finalSet.size() << endl;

	//Saving fase
	cout << "Saving words into file " << outFileName << " ..." << endl;
	if (fileOutput.is_open()) {
		for (string word : finalSet) {
			fileOutput << word << endl;
		}

		fileOutput.close();
	}

	cout << "End of processing." << endl;

	return 0;
}