#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ifstream fileIn("01.txt");

    unordered_map <string, string> numbers = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };

    int sum = 0;

    string currentNumber = {};

    string input;

    map<int, string> digits = {};

    while (getline(fileIn, input)) {

        for (int i = 0; i < input.length(); i++) {

            if (isdigit(input[i])) {
                digits[i] = input[i];
            }

            for (auto j = numbers.begin(); j != numbers.end(); j++) {

                if (i + j -> first.length() <= input.length()) {

                    if (input.substr(i, j -> first.length()) == j->first) {
                        digits[i] = j -> second;
                    }
                }
            }
        }

        string lastValue = {};

        for (auto i : digits) {
            
            lastValue = i.second;
        }

        currentNumber += digits.begin() -> second;
        currentNumber += lastValue;

        lastValue = {};

        sum += stoi(currentNumber);

        currentNumber = {};
        digits.clear();
    }

    cout << sum << endl;

    return 0;
}