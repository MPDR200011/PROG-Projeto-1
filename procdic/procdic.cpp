#include <iostream>
#include <string>
#include <vector>
#include "wordUtils.h"

using namespace std;

vector<string> finalVector;
vector<vector<string>> wordVectors; //vetor com vetor para cada letra inicial

int main() {
	string line;

	getline(cin, line);

	cout << line << endl;

	vector<string> words = processLine(line);

	if (isLineValid(line)) {
		for (string s : processLine(line)) {
			cout << s << endl;
		}
	} else {
		cout << "invalid line" << endl;
	}

	return 0;
}