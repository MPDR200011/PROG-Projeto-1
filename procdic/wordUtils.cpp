#include "wordUtils.h"
#include <vector>
#include <string>

using namespace std;

vector<string> processLine(string line) {
	//serve esta funcao para transformar uma linha de diferentes palavras separadas 
	//por caracteres especiais num vetor de cada palavra
	vector<string> tempVector; // vetor a ser retornado com as palavrasda linha
	string tempString = string(); // string temporaria para guardar

								  //iterar pela string dada como parametro
	for (char car : line) {
		if (car != ' ' & car != ';' & car != '-' & car != '\'' & car >= 65 & car <= 90) {
			//se encontrar uma maiuscula, adiciona-a a string temporaria
			tempString += car;
		} else if (car == ' ' || car == ';' || car == '-' || car == '\'') {
			//se encontrar um dos caracteres especiais
			if (tempString.length() != 0) {
				//se a tempString nao estiver vazia passa-a para o vetor
				tempVector.push_back(tempString);
			}
			tempString = string(); //faz reset a string
		}
	}

	if (tempString.length() != 0) {
		tempVector.push_back(tempString);
	}

	return tempVector;
}

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