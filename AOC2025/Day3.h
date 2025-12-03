#pragma once
#include <vector>
#include <string>
class Day3 {
private:
	void loadBatteryBanks(std::vector<std::string>& banks);
	int determineBankMaxJoltage(std::string bank);
	long long determineBankMaxJoltageV2(std::string bank, int joltageLength);
public:
	long long solvePart1();
	long long solvePart2();
};