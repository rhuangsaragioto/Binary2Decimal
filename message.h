#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string_view>

const std::string_view NO_INPUT = "You need to pass in a binary number!\n";
const std::string_view WRONG_INPUT = "Entered input MUST be a binary number!\n";
const std::string_view USAGE = "Usage: ./Bin2Dec binary_number"
                               " | binary_number - a string containing only 1s and 0s. i.e., '1010001'";

#endif