#include <iostream>
#include <ctype.h>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fileIn("01.txt");

    int sum = 0;

    string currentNumber = {};

    string input;
    vector<int> digits = {};

    while (!fileIn.eof()) {
        fileIn >> input;
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i])) {
                digits.push_back(int(input[i]));
            }
        }
        currentNumber += digits.front();
        currentNumber += digits.back();
        sum += stoi(currentNumber);
        currentNumber = {};
        digits.clear();
    }

    fileIn.close();

    cout << sum << endl;

    return 0;
}