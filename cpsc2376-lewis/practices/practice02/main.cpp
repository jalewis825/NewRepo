#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //included for setprecision when using doubles
#include <limits> //For clearing input buffer in case of invalid input

//defines filename to keep from hardcoding each time
const std::string filename = "account_balance.txt";

//function to check for a file. If no file found or it is corrupt: create one and initilize balance to $100
double readBalance() {
    std::ifstream inFile(filename);
    double balance = 0.0;
    if (inFile.is_open()) {
        inFile >> balance;
        inFile.close();
    }
    else {
        std::cerr << "No file to open for reading." << std::endl;
        std::cout << "Initializing balance to $100.00." << std::endl;
        std::cout << std::endl;
        balance = 100.00;
        std::ofstream outFile(filename);
        outFile << std::fixed << std::setprecision(2) << balance;
        outFile.close();
    }
    return balance;
}
//function to take the new balance and add it to the file, replacing the old balance with the new based on withdraw or deposit.
void writeBalance(double balance) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << std::fixed << std::setprecision(2) << balance;
        outFile.close();
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

double getValidAmount() {
    double amount;
    while (true) {
        std::cout << "Amount: ";
        std::cin >> amount;

        if (std::cin.fail() || amount <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid amount. Please enter a positive numeric value." << std::endl;
        }
        else {
            return amount;
        }
    }
}


int main() {
    std::cout << "Welcome to your Bank Account!" << std::endl;
    std::cout << std::endl;

    double balance = readBalance();

    while (true) {
        int userInput;
        std::cout << "---Bank Account Menu---" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Make A Deposit" << std::endl;
        std::cout << "3. Make A Withdrawal" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> userInput;
        std::cout << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number 0-3." << std::endl;
            std::cout << std::endl;
            continue;
        }


        switch (userInput) {
        case 1: {
            balance = readBalance();
            std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
            break;
        }
        case 2: {
            std::cout << "How much would you like to deposit?" << std::endl;
            double deposit = getValidAmount();
            balance += deposit;
            writeBalance(balance);
            std::cout << "Deposit successful! New balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
            break;
        }
        case 3: {
            std::cout << "How much would you like to withdraw? " << std::endl;
            double withdrawal = getValidAmount();
            if (withdrawal <= balance) {
                balance -= withdrawal;
                writeBalance(balance);
                std::cout << "Withdrawal successful! New balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
            }
            else {
                std::cout << "Invalid amount. Please enter a positive value that does not exceed your balance total." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Thank you for trusting us with your banking needs! Goodbye!" << std::endl;
            std::cout << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please choose from options 0-3." << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;

}
/*AI:I was having trouble converting my notes from tutorial 01 to fit this practice. Therefore,
AI was utilized to help me figure out how to make the initial balance a double instead of the method in tutorial.
AI also reminded me to use setprecision when using doubles. I also wanted to check to make sure the user doesn't
enter characters vs. ints. I used AI to remind me of the cin.fail method.*/