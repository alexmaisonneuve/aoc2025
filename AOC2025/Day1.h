#pragma once
#include <string>

class Day1 {
private :
	int initialCombination = 50;

	void rotateRight(int& currentCombination, int& distance, int& password);
	void rotateLeft(int& currentCombination, int& distance, int& password);
	void rotate(std::string rotation, int& currentCombination, int& password);
public:
	int solve();
};