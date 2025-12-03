#pragma once

#include "Day2.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

std::vector<std::pair<long long, long long>> Day2::readFile(std::ifstream& file)
{
	long long minimum;
	long long maximum;
	char sep1;
	char sep2;


	std::vector<std::pair<long long, long long>> results;
	while (file >> minimum >> sep1 >> maximum)
	{
		std::cout << "minimum : " << minimum << " maximum : " << maximum << std::endl;
		results.push_back({ minimum, maximum });
		file >> sep2;
	}

	return results;
}

bool Day2::findInvalidIds(long long id, int splitInto) {
	std::string idString = std::to_string(id);
	size_t length = idString.length();

	if (length % splitInto != 0)
		return false;

	size_t partLength = length / splitInto;

	std::string firstPart = idString.substr(0, partLength);

	int charIndex = partLength;
	while (charIndex < length) {
		if (firstPart != idString.substr(charIndex, partLength)) {
			return false;
		}

		charIndex += partLength;
	}

	return true;
}

long long Day2::executePart1() {
	std::vector<std::pair<long long, long long>> ranges;
	std::ifstream file("Day2Input.csv");

	ranges = readFile(file);

	long long result = 0;
	for (auto& range : ranges) {
		for (long long id = range.first; id <= range.second; id++) {
			
			if (findInvalidIds(id, 2)) {
				result += id;
			}
		}
	}

	std::cout << std::to_string(result) << std::endl;
	return result;
}

long long Day2::executePart2() {
	std::vector<std::pair<long long, long long>> ranges;
	std::ifstream file("Day2Input.csv");

	ranges = readFile(file);

	long long result = 0;
	for (auto& range : ranges) {
		for (long long id = range.first; id <= range.second; id++) {
			std::string idString = std::to_string(id);
			size_t length = idString.length();
			
			for (int i = 2; i <= length; i++) {
				if (findInvalidIds(id, i)) {
					result += id;
					break;
				}
			}
		}
	}
	std::cout << std::to_string(result) << std::endl;
	return result;
}
