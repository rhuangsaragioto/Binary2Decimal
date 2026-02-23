# Binary2Decimal

A small command line tool that allows you to convert variable size binary numbers to decimals.

## Table of Contents

- [Description](#description)
- [Getting Started](#getting-started)
  - [Dependencies](#dependencies)
  - [Executing Program](#executing-program)
- [Help](#help)
- [Authors](#authors)
- [Version History](#version-history)
- [License](#license)
- [Acknowledgements](#acknowledgments)

## Description

The program utilizes a summation algorithm as such:

![Summation algorithm](https://p.kagi.com/proxy/binary2.PNG?c=NEWVyEx4NuEJxKkAg7KeAU6NxdCIjRRfJBKa7ghmgDxZRY2keOf3_jtXOFZbdxvW7HqdBdVXybbScNGhz1HpHUq-zkh9TLO4wxvCSPH7erv-7uhrBpCjK2P_azA-c9kt)

In code, the binary number is iterated through (meaning that each 'digit' in the string representation of the binary number is accessed once), and for every digit, the value modeled by `std::pow(2, exp) * static_cast<double>(binary[i] - '0')`. This is a lot to unpack, so let's walk through it step-by-step.

`std::pow(2, exp)` is equivalent to saying `2` to the power of `exp`, where `exp` is the current power of two. E.g., `pow(2, 3)` means `2` to the power of `3`.

Then, the result of that operation is multiplied by the value at `binary[i]`. This works because the string's current character is always going to be either 0 or 1, therefore, if the current character is equivalent to 1, the value remains the same, otherwise, it gets multiplied by 0, being nullifed.

However, you may notice that the value at that index is being subtracted by `'0'`. The reason is that the characted representation of a number is not the same value as the actual number. For example, `'0'` in ASCII is equivalent to 48, and `'1'` is equivalent to 49. Therefore, subtracting by `'0'` yields the distance between those values `'1' - '0'` is equivalent to 49 - 48, which yields 1.

The exponent ranges from `binary.size() - 1` to 0. This is set up the way it is because the string representation of the binary number is traversed in MSB to LSB order. Therefore, exponents need to be in decreasing order.

The reason why the upper-range is `binary.size() - 1` rather than just `binary.size()` is that exponents are "0-indexed" in this conversion method (since we need to represent odd numbers and any nonzero number to the power of 0 is 1.)

The summation step is repeated until end of string is reached. The sum is then returned as the decimal value.

## Getting Started

### Dependencies

- gcc: Since this is a c++ project you need gcc to compile the code. You can follow the tutorial for [downloading, installing and configuring gcc here](https://gcc.gnu.org/install/).
**Note:** You may use a different compiler, but you would have to modify the Makefile or manually compile in order to run the program.
- make: I used Makefiles to automate the compiling process. If you wish to utilize them as well, you can [download, install, and configure make here](https://www.gnu.org/software/make/#download).

### Executing program

- You may choose to either clone the repo, or download the project as a zip. In whichever case you can run the program the same way:
  - Cloning the repo: You can clone the repo by doing the following command on the target directory:

```shell
  git clone https://github.com/rhuangsaragioto/Binary2Decimal.git
```

**Note** that this will also create a copy of the repository in your machine. If you only  wish to have a copy of the directory, you can [download the project's zip here](https://github.com/rhuangsaragioto/Binary2Decimal/archive/refs/heads/main.zip).

When you have the directory on your local machine, along with gcc and make configured, you can run the project with the following command:

```zsh
make
```

and

```zsh
./Bin2Dec binary_number
```

where `binary_number` is the binary number you wish to convert into a decimal. You may enter any number of digits, as long the number is in binary form. E.g.:

```zsh
./Bin2Dec 101010101010
```

You can also remove the compiled files and executable of the program by running `make clean` in the terminal.

## Help

If you want more info on the usage of the program, you can either try:

- Running the program with no arguments:

```c++
./Bin2Dec
```

which will yield the message:

```zsh
You need to pass in a binary number!
Usage: ./Bin2Dec binary_number | binary_number - a string containing only 1s and 0s. i.e., '1010001'
```

or

- Running the program with invalid arguments (e.g., non-binary number, words, more than one argument, etc.)

```zsh
./Bin2Dec HelloWorld
```

which will yield the message:

```zsh
Entered input MUST be a binary number!
Usage: ./Bin2Dec binary_number | binary_number - a string containing only 1s and 0s. i.e., '1010001'
```

## Authors

I am the sole author of this project, you can find some of my information below.

- LeetCode - [@rhuangsaragioto](https://leetcode.com/u/rhuangsaragioto/)
- GitHub - [@rhuangsaragioto](https://github.com/rhuangsaragioto)
- LinkedIn - [@rhuansaragioto](https://www.linkedin.com/in/rhuan-saragioto-4043662aa/)

## Version History

- 0.2
  - Fixed conversion (actually works now)
  - See [commit history](https://github.com/rhuangsaragioto/Binary2Decimal/commits/main/).
- 0.1
  - Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

- [README-Template.md](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc) - The README file's template you're currently reading came from this legend's  gist. Go show them some support.
- [GeeksForGeeks](https://www.geeksforgeeks.org/utilities/binary-to-decimal/) - Provided the image demonstrating the conversion algorithm in this README.
