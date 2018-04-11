#include <iostream>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

void searchWildcard(ifstream &wordListFile) {
	
	cout << "Wildcard explanation:" << endl;
	cout << "	* - Match any string." << endl;
	cout << "	? - Match any character." << endl;

	string input;
	cout << endl << "Enter string with wildcards to search ? ";
	pw::readString(input);
	input = pw::trim(input); //Remove espaços a frente e atras
	input = pw::makeUpper(input); 

	cout << endl;
	string temp;
	while (getline(wordListFile, temp)) {
		//Procura todas as palavras que facam match com as wildcards e imprime-as
		if (pw::wildcardMatch(temp.c_str(), input.c_str())) {
			cout << temp << endl;
		}
	}
	
}