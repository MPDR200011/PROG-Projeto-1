#pragma once

#include <iostream>
#include <string>
#include <vector>

//playwords namespace
namespace pw {

	void readString(std::string &var);

	template <class T>
	void takeInput(T &var) {
		//Funcao generica para receber input valido para qualquer 
		//tipo de variavel, exceto strings
		bool validInput = false;
		do {
			validInput = false;
			cin >> var;
			if (cin.fail()) {
				validInput = false;
				cout << "Invalid input, try again." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			} else {
				validInput = true;
				cin.ignore(1000, '\n');
			}
		} while (!validInput);
	}

	bool isWordPartOfSet(std::string word, std::vector<char> set);

}