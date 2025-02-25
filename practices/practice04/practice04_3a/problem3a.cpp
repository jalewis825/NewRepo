#include <iostream>
#include <string>
#include <list>


int main() {
	std::list<std::string> tasks;
	int userInput;

	while (true) {
		std::cout << std::endl;
		std::cout << "---Task Manager---" << std::endl;
		std::cout << "1. Add a task" << std::endl;
		std::cout << "2. Remove a task" << std::endl;
		std::cout << "3. Show tasks" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> userInput;

		if (std::cin.fail() || (userInput < 0 || userInput > 3)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number (0-3)" << std::endl;
			continue;
		}

		switch (userInput) {
			case 1: {
				std::string task;
				std::cin.ignore();
				std::cout << "Enter the task: ";
				std::getline(std::cin, task);
				tasks.push_back(task);
				std::cout << "----------------" << std::endl;
				std::cout << "Task added succesfully!" << std::endl;
				break;
			}
			case 2: {
				if (tasks.empty()) {
					std::cout << "----------------" << std::endl;
					std::cout << "No tasks to remove." << std::endl;
					break;
				}

				std::string taskToRemove;
				std::cin.ignore();
				std::cout << "Enter the task to remove: ";
				std::getline(std::cin, taskToRemove);

				//searches through the list to see if the task to be removed is even in the list
				auto eraseTask = std::find(tasks.begin(), tasks.end(), taskToRemove);
				if (eraseTask != tasks.end()) {
					tasks.erase(eraseTask);
					std::cout << "--------------------" << std::endl;
					std::cout << "Task: '" << taskToRemove << "' removed successfully." << std::endl;
				}
				else {
					std::cout << "--------------------" << std::endl;
					std::cout << "Task: '" << taskToRemove << "' not found." << std::endl;
				}
			}
			case 3: {
				if (tasks.empty()) {
					std::cout << "--------------------" << std::endl;
					std::cout << "No tasks to remove." << std::endl;
					break;
				}

				int index = 1; //initilizes list at 1 instead of 0 for numbered list
				std::cout << "-----Your tasks-----" << std::endl;
				for (const auto& task : tasks) {
					std::cout << index++ << ". " << task << std::endl;
				}
				std::cout << "--------------------" << std::endl;
				break;
			}
			case 0:
				std::cout << "Exiting the program...Goodbye!" << std::endl;
				return 0;
			default:
				std::cout << "Invalid input. Please choose from options 0-3." << std::endl;
		}
	}
}

/*AI: AI used to help with list syntax. Basically, the same as the other containers...I just didn't realize that. Also, it helped with the std::find*/