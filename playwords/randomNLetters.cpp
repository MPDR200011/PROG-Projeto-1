#include <iostream>
#include <fstream>
#include <time.h>
#include "router.h"
#include "playWordsUtils.h"

using namespace std;

struct CharSet {

	unsigned int letterAmountsInFile[26] = {0};
	vector<char> finalCharVector;

	CharSet(ifstream &input) {
		
		for (unsigned int i : letterAmountsInFile) {
			//Colocar todos os valores da array a 0
			i = 0;
		}

		string temp;
		while (getline(input, temp)) {
			//Conta o numero de ocorrencias de cada letra no ficheiro
			for (char c : temp) {
				letterAmountsInFile[c - 65] ++;
			}
		}

		size_t lowestAmount = letterAmountsInFile[0]; //Indice para a quantidade mais baixa de uma letra especifica
		size_t totalChars = 0; //Total de letras

		for (size_t i = 0; i < 26; i++) {
			//Procura o indice correspondente a letra que aparece menos vezes no ficheiro
			totalChars += letterAmountsInFile[i];
			if (letterAmountsInFile[i] < lowestAmount) {
				lowestAmount = letterAmountsInFile[i];
			}
		}

		//Frequencia com que a letra com menos frequencia aparece
		float lowestRatio = (float) lowestAmount / (float) totalChars;

		for (int i = 0; i < 26; i++) {
			/*
				Fase de criacao do vetor com as letras atraves do qual
				se criara o set de chars aleatorios

				calcula-se o razao de cada letra e apliaca-se uma
				regra dos tres simples de modo a que a letra que ocorre 
				menos vezes ocorra 2 vezes:

				lowestRatio -> 2 ocorrencias
				ratio -> amount
			*/
			float ratio = (float) letterAmountsInFile[i] / (float) totalChars;
			int amount = (int) ((2 * ratio) / lowestRatio);

			for (int j = 0; j < amount; j++) {
				//Preencher o vetor com o numero de ocorrencias calculado
				finalCharVector.push_back((char) (i + 65));
			}
		}



	}

};

void randomNLetters(ifstream &wordListFile) {

	//Cria struct com um vetor de chars com frequencia proporcional 
	//a frequencia com que aparecem na word list
	CharSet cset(wordListFile);
	
	//Pedido do tamanho do set de caracteres aleatorios
	bool validInput = false;
	unsigned int NSetSize;
	cout << "Set size ? ";
	pw::takeInput(NSetSize);

	//Criacao do set de caracteres aleatorios
	vector<char> randomCharSet;
	srand((unsigned int) time(NULL));
	for (size_t i = 0; i < NSetSize; i++) {
		//escolhe caracter aleatorio do vetor
		size_t index = rand() % cset.finalCharVector.size(); 
		char c = cset.finalCharVector.at(index);
		//passa esse caracter para o set
		randomCharSet.push_back(c);
	}

	//Fase de imprimir o set
	cout << "Build a word using letters from the following set: ";
	for (char c : randomCharSet) {
		cout << c << " ";
	}
	cout << endl;
	cout << "Input ? ";

	//Pede a sugestao do jogador
	bool validWord = false;
	string answer;
	do {
		pw::readString(answer);
		answer = pw::trim(answer);
		answer = pw::makeUpper(answer);

		validWord = pw::isWordPartOfSet(answer, randomCharSet);
		
		if (!validWord) {
			//Verifica se se estao a usar letras do set 
			//e se nao se estao a usar letras a mais
			cout << "Word letters do not correspond to given set, try again." << endl;
		}
	} while (!validWord);

	//////////////////////////////////
	//Fase de verificacao e veredito//
	//////////////////////////////////

	//Retorna ao inicio do ficheiro
	wordListFile.clear();
	wordListFile.seekg(0);

	string temp;
	bool founWord = false;
	cout << endl << "Checking..." << endl;
	while (getline(wordListFile, temp)) {
		if (!temp.compare(answer)) {
			//Encontrou
			founWord = true;
			break;
		}
	}

	//Nao encontrou
	if (founWord) {
		cout << "Word is in word list!" << endl;
	} else {
		cout << "Word is not in world list!" << endl;
	}

	pw::endGame();

}