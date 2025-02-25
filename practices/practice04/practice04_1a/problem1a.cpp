#include <iostream>
#include <iomanip>

double convertTemp(double temp, char scale = 'F') {
    if (scale == 'F') {
        return (temp * 9.0 / 5.0) + 32; //Celcius to Fahrenheit
    }
    else if (scale == 'C') {
        return (temp - 32) * 5.0 / 9.0;//Farhrenheit to Celsius
    }
    return temp;
}

int main() {
    int userInput;
    double temp;
    double result;

    while (true) {
        std::cout << std::endl;
        std::cout << "---Temperature Conversion---" << std::endl;
        std::cout << "1. Celsius to Fahrenheit" << std::endl;
        std::cout << "2. Fahrenheit to Celsius" << std::endl;
        std::cout << "0. Exit Program" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your choice: ";


        //handle user entering any invalid option for userInput (char or invalid int)
        while (true) {
            std::cin >> userInput;
            if (std::cin.fail() || (userInput < 0 || userInput > 2)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a number (0-2): ";
            }
            else {
                break;
            }
        }

        if (userInput == 0) {
            std::cout << "Exiting program! Goodbye!" << std::endl;
            std::cout << std::endl;
            return 0;
        }

        //handle user entering non - numeric value for temp
        while (true) {
            std::cout << std::endl;
            std::cout << "Enter temperture: ";
            std::cin >> temp;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a valid integer or decimal temperature." << std::endl;
            }
            else {
                break;
            }
        }

        std::cout << std::fixed << std::setprecision(1);

        if (userInput == 1) {
            result = convertTemp(temp, 'F');
            std::cout << temp << "°C = " << result << "°F." << std::endl;

        }
        else if (userInput == 2) {
            result = convertTemp(temp, 'C');
            std::cout << temp << "°F = " << result << "°C." << std::endl;
        }
    }
    return 0;
}

/*AI: Utilized to help with conversion formulas.Also, used to help when fixing bugs.
There was some organization issues I was facing with my if statements. Also, used it to
help me with the cin.clear()/fail() syntax. */