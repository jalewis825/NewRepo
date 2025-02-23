#include <iostream>
#include <vector>

//function to add numbers to the vector
void addNumber(std::vector<int>& numbers) {
    int num;
    std::cout << "Enter number you'd like to add to the vector: ";
    std::cin >> num;
    numbers.push_back(num);
    std::cout << num << " has been added to the vector." << std::endl;
}

//function to print the vector
void printVector(std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        std::cout << "Vector contents: ";
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

//function to double all numbers in the vector
void doubleVector(std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        for (int& num : numbers) {
            num *= 2;
        }
        std::cout << "Doubled Vector: ";
        printVector(numbers);
    }
}

//function to find the sum of all numbers in the vector
void sumVector(std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        std::cout << "The sum of all numbers in the vector is: " << sum << std::endl;
    }
}

//funtion to sort throught the vector and print multiples of a user identified number
void printMultiples(std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "The vector is empty." << std::endl;
    }
    else {
        int multiple;
        std::cout << "Enter a number you'd like to find multiples of: ";
        std::cin >> multiple;

        bool found = false; //check to see if at least one multiple is found

        std::cout << "Multiples of " << multiple << " within the vector: ";
        for (int num : numbers) {
            if (num % multiple == 0) {
                std::cout << num << " ";
                found = true;
            }
        }

        if (!found) {
            std::cout << "0" << std::endl; //print out 0 if no mutltiples of user given number found
        }
    }
}

int main() {
    std::vector<int> numbers;
    int userInput;

    while (true) {
        std::cout << "---Vector Management---" << std::endl;
        std::cout << "1. Add number to vector" << std::endl;
        std::cout << "2. Print the vector" << std::endl;
        std::cout << "3. Double the vector" << std::endl;
        std::cout << "4. Sum of vector" << std::endl;
        std::cout << "5. Print multiples of specified value" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> userInput;

        switch (userInput) {
        case 1:
            addNumber(numbers);
            break;
        case 2:
            printVector(numbers);
            break;
        case 3:
            doubleVector(numbers);
            break;
        case 4:
            sumVector(numbers);
            break;
        case 5:
            printMultiples(numbers);
            break;
        case 0:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            std::cout << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please choose from options 0-5." << std::endl;
        }
        std::cout << std::endl; //extra lines so program is easier to read for the user
        std::cout << "Returning to menu..." << std::endl;
        std::cout << std::endl;
    }
}

/*AI: AI was utilized to help me with the bool I wanted to add. I wanted to add the condition that if
no multiples were found it would state that but I was having trouble structuring the code to make it work
the way I was wanting. */