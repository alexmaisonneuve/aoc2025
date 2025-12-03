#include "Day3.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

void Day3::loadBatteryBanks(std::vector<std::string>& banks)
{
	std::ifstream banksFile("Day3Input.txt");
	if (!banksFile.is_open()) {
		std::cerr << "Error opening the input!";
	}

	std::string bank;
	while (std::getline(banksFile, bank)) {
		banks.push_back(bank);
	}
}

int Day3::determineBankMaxJoltage(std::string bank)
{
	int maxJoltage = 0;

	int firstDigit = 9;
	int secondDigit = 9;
	bool firstDigitFound = false;
	bool secondDigitFound = false;
	int firstDigitIndex = 0;

	while (!firstDigitFound || !secondDigitFound) {

		if (!firstDigitFound) {
			for (int i = 0; i < bank.length() - 1; i++) {

				int currentDigit = bank[i] - '0';
				if (currentDigit != firstDigit) {
					continue;
				}
				firstDigitFound = true;
				firstDigitIndex = i;
				break;
			}
		}

		if (firstDigitFound) {
			for (int j = firstDigitIndex + 1; j < bank.length(); j++) {
				int currentSecondDigit = bank[j] - '0';
				if (currentSecondDigit == secondDigit) {
					secondDigitFound = true;
					break;
				}
			}

			if (!secondDigitFound) {
				secondDigit--;
			}
		}
		else
		{
			if (firstDigit > 0) {
				firstDigit--;
			}
			else {
				return 0;
			}
		}
	}

	maxJoltage = firstDigit * 10 + secondDigit;

	return maxJoltage;
}

long long Day3::determineBankMaxJoltageV2(std::string bank, int joltageLength)
{
	long long maxJoltage = 0;
	int lastIndex = 0;
	int currentJoltageDigit = joltageLength;
	std::vector<int> joltage;

	while (currentJoltageDigit > 0) {
		int highestJoltage = 0;
		for (int i = lastIndex; i < bank.length() - currentJoltageDigit + 1; i++) {
			int currentDigit = bank[i] - '0';
			if (currentDigit > highestJoltage) {
				highestJoltage = currentDigit;
				lastIndex = i;
			}
		}
		joltage.push_back(highestJoltage);
		currentJoltageDigit--;
		lastIndex++;
	}

	std::stringstream ss;
	for (int digit : joltage) {
		ss << digit;
	}

	maxJoltage = stoll(ss.str());

	return maxJoltage;
}

long long Day3::solvePart1()
{
	std::vector<std::string> banks;
	loadBatteryBanks(banks);

	long long totalJoltage = 0;
	for (std::string bank : banks) {
		totalJoltage += determineBankMaxJoltage(bank);
	}

	return totalJoltage;
}

long long Day3::solvePart2()
{
	std::vector<std::string> banks;
	loadBatteryBanks(banks);

	long long totalJoltage = 0;
	std::vector<long long> joltages;
	for (std::string bank : banks) {
		long long joltage = determineBankMaxJoltageV2(bank, 12);
		totalJoltage += joltage;
		joltages.push_back(joltage);
	}

	return totalJoltage;
}