#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SafeSolver {
	int initialCombination = 50;

public :
	int solve() 
	{
		ifstream combinations("Day1Input.txt");
		if (!combinations.is_open()) {
			cerr << "Error opening the input!";
			return 1;
		}
		string rotation;
		int currentCombination = initialCombination;
		int password = 0;

		while (getline(combinations, rotation)) {
			rotate(rotation, currentCombination, password);
		}

		return password;
	}

	void rotateRight(int& currentCombination, int& distance, int& password)
	{
		for (int i = 0; i < distance; i++) {
			if (currentCombination == 99) {
				currentCombination = 0;
				password++;
			}
			else {
				currentCombination++;
			}
		}
	}

	void rotateLeft(int& currentCombination, int& distance, int& password)
	{
		for (int i = 0; i < distance; i++) {
			if (currentCombination == 0) {
				currentCombination = 99;
			}
			else {
				currentCombination--;
				if (currentCombination == 0) {
					password++;
				}
			}
		}
	}

	void rotate(string rotation, int& currentCombination, int& password)
	{
		string direction = rotation.substr(0, 1);
		int distance = stoi(rotation.substr(1, rotation.length()));

		if (direction == "R") {
			rotateRight(currentCombination, distance, password);
		}
		else {
			rotateLeft(currentCombination, distance, password);
		}
	}
};