#pragma once
#include <string_view>
#include <vector>
#include <istream>

class Day2 {
private:
	bool findInvalidIds(long long id, int splitInto);
	std::vector<std::pair<long long, long long>> readFile(std::ifstream& file);
public:
	long long executePart1();
	long long executePart2();
};

