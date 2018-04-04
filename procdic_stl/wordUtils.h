#pragma once

#include <vector>

bool isLineValid(std::string line);

std::string trim(std::string s);

std::vector<std::string> splitLine(std::string line, const char splitter);

bool isSingleWord(std::string word);