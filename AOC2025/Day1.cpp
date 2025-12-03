#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Day1.h"

int Day1::solve()
{
	std::ifstream combinations("Day1Input.txt");
	if (!combinations.is_open()) {
		std::cerr << "Error opening the input!";
		return 1;
	}
	std::string rotation;
	int currentCombination = initialCombination;
	int password = 0;

	while (std::getline(combinations, rotation)) {
		rotate(rotation, currentCombination, password);
	}

	return password;
}

void Day1::rotateRight(int& currentCombination, int& distance, int& password)
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

void Day1::rotateLeft(int& currentCombination, int& distance, int& password)
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

void Day1::rotate(std::string rotation, int& currentCombination, int& password)
{
	std::string direction = rotation.substr(0, 1);
	int distance = stoi(rotation.substr(1, rotation.length()));

	if (direction == "R") {
		rotateRight(currentCombination, distance, password);
	}
	else {
		rotateLeft(currentCombination, distance, password);
	}
}