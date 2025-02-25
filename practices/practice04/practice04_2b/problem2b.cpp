#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
T findMax(T a, T b, T c) {
	return std::max({ a, b, c });
}

int getValidInt(const std::string& prompt) {
	int value;

	while (true) {
		std::cout << prompt;
		if (std::cin >> value) {
			return value;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please only enter integers" << std::endl;
		}
	}

}

std::string getValidString(const std::string& prompt) {
	std::string value;

	while (true) {
		std::cout << prompt;
		std::cin >> value;

		if (std::all_of(value.begin(), value.end(), ::isalpha)) {
			return value;
		}
		else {
			std::cout << "Invalid input. Please only enter letters." << std::endl;
		}
	}

}

int main() {
	int userInput;

	while (true) {
		std::cout << std::endl;
		std::cout << "---Max Finder---" << std::endl;
		std::cout << "1. Compare Integers" << std::endl;
		std::cout << "2. Compare strings" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> userInput;

		if (std::cin.fail() || (userInput < 0 || userInput > 2)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number (0-2)" << std::endl;
			continue;
		}

		switch (userInput) {
		case 1: {
			std::cout << "Enter 3 integers:" << std::endl;
			int a = getValidInt("First: ");
			int b = getValidInt("Second: ");
			int c = getValidInt("Third: ");
			std::cout << "Enter 3 integers:" << std::endl;
			int max = findMax(a, b, c);
			std::cout << "Maximum value: " << max << std::endl;
			break;
		}
		case 2: {
			std::cout << "Enter 3 strings:" << std::endl;
			std::string a = getValidString("First: ");
			std::string b = getValidString("Second: ");
			std::string c = getValidString("Third: ");
			std::cout << "Enter 3 integers:" << std::endl;
			std::string max = findMax(a, b, c);
			std::cout << "Maximum value: " << max << std::endl;
			break;
		}
		case 0:
			std::cout << "Exiting the program...Goodbye!" << std::endl;
			return 0;
		default:
			std::cout << "Invalid choice. Please choose from options 0-2." << std::endl;
		}
	}
	return 0;
}
//AI: Used AI to help me with the user input check for strings. I've done it plenty with checking for ints but not the other way around.