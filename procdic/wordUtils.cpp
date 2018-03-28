#include "wordUtils.h"
#include <vector>
#include <string>

using namespace std;

bool isLineValid(string line) {
	// verifica se a linha tem apenas maiusculas e os caracteres especiais
	for (char car : line) {
		if ((car < 65 || car > 90) & (car != ' ' & car != ';' & car != '-' & car != '\'')) {
			// se encontrar algum caracter que nao seja dos necessarios retorna false
			return false;
		}
	}

	return true;
}

string trim(string s) {
	//remove o espaco branco no inicio e no fim da string
	const auto sBegin = s.find_first_not_of(" \t\n\v\f\r");

	if (sBegin == string::npos)
		return "";//caso esteja vazia

	const auto sEnd = s.find_last_not_of(" \t\n\v\f\r");
	const auto range = sEnd - sBegin;

	return s.substr(sBegin, range + 1);
}

vector<string> splitLine(string line, const char splitter) {
	//esta funcao cria um vetor de diferentes strings separadas pelo caracter dado
	//se der uma lista de palavras separadas por virgula e der um a virgula como splitter, ele cria um vetor das repetivas palavras
	vector<string> stringVector;

	string temp = string();
	for (char c : line) { //iterar pelos caracteres da string 
		if (c != splitter) {
			temp += c;
		} else {
			temp = trim(temp);
			if (temp != "") {
				stringVector.push_back(temp);
				temp = string();
			}
		}
	}

	temp = trim(temp);
	if (temp != "") {
		stringVector.push_back(temp);
	}

	return stringVector;
}

bool isSingleWord(string word) {
	for (char c : word) {
		if (c > 90 || c < 65) {
			return false;
		}
	}

	return true;
}