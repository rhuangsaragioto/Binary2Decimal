#include "message.h"

#include <iostream>
#include <cmath>
#include <string>

int main(int argc, const char* argv[]) {
    std::string binary;
    if (argc == 1) {
        std::cout << "You need to pass in a binary number! See -u for usage." << std::endl;
        return -1;
    } else {
        binary = argv[1];
    }

    size_t decimal = 0;
    int exp = binary.size() - 1;
    for (size_t i = 0; i < binary.size(); i++) {
        decimal += std::pow(2, exp) * static_cast<int>(binary[i] - '0');
    }

    std::cout << decimal << std::endl;
    return 0;
}