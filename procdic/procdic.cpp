#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include "wordUtils.h"

using namespace std;

vector<string> finalVector; //vetor com todas as palavras
vector<vector<string>> wordVectors = vector<vector<string>>(26); //vetor com vetores para cada letra inicial

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
			cout << "Invalid input, try again.\n";
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			fileInput.open(inFileName);
			if (fileInput.is_open()) {
				inputFail = false;
			} else {
				inputFail = true;
				cout << "File not found, try again.\n";
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
			cout << "Invalid input, try again.\n";
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			fileOutput.open(outFileName);
			if (fileOutput.is_open()) {
				inputFail = false;
			} else {
				inputFail = true;
				cout << "Something went wrong, try again.\n";
			}
		}
	} while (inputFail);

	//Word extraction fase
	cout << "\nExtracting simple words from file " << inFileName << ",\n";
	if (fileInput.is_open()) {
		
		while (getline(fileInput, line)) {

			if (isLineValid(line)) {

				for (string word : splitLine(line, ';')) {

					if (isSingleWord(word)) {

						wordVectors.at(word.at(0) - 65).push_back(word);
					}
				}
			}
		}

		fileInput.close();
	} else {
		cout << "file not found\n";
	}

	//Word counting fase
	cout << "beginning with letter ...";
	for (int i = 0; i < 26; i++) {
		cout << "\n" << (char) (65 + i) << "\n";
		int wordCount = 0;
		for (string word : wordVectors.at(i)) {
			++wordCount;
			finalVector.push_back(word);
			if (wordCount % 100 == 0) {
				cout << ".";
			}
		}
	}

	cout << "\nNumber of simple words = " << finalVector.size() << "\n";

	//Sorting fase
	cout << "Sorting words ...\n";
	sort(finalVector.begin(), finalVector.end());

	//Duplicate removing fase
	cout << "Removing duplicate words ...\n";
	finalVector.erase(unique(finalVector.begin(), finalVector.end()), finalVector.end());

	cout << "Number of non-duplicate simple words = " << finalVector.size() << "\n";

	//Saving fase
	cout << "Saving words into file " << outFileName << " ...\n";
	if (fileOutput.is_open()) {
		for (string word : finalVector) {
			fileOutput << word << "\n";
		}
	}

	cout << "End of processing.\n";

	return 0;
}