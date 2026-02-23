#include "message.h"

#include <iostream>
#include <cmath>
#include <string>

double binToDec(std::string binary) {
    double decimal = 0;
    size_t exp = binary.size() - 1;
    for (size_t i = 0; i < binary.size(); i++) {
        decimal += std::pow(2, exp) * static_cast<double>(binary[i] - '0');
        if (exp > 0)
            exp--;
        else
            exp = 0;
    }
    return decimal;
}

bool checkIfBinary(std::string input) {
    for (size_t i = 0; i < input.size(); i++) {
        if ((input[i] != '0') || (input[i] == '1'))
            return false;
    }
    return true;
}

int main(int argc, const char* argv[]) {
    std::string binary;
    if (argc == 1) {
        std::cout << NO_INPUT << USAGE << std::endl;
        return -1;
    } else {
        if (checkIfBinary(argv[1]) == 1)
            binary = argv[1];
        else {
            std::cout << WRONG_INPUT << USAGE << std::endl;
            return 1;
        }
    }

    double decimal = binToDec(binary);
    std::cout << "Binary: " << binary << std::endl;
    std::cout << "Decimal: " << decimal << std::endl;
    return 0;
}