#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("04.txt");
    string input;

    int result = 0;

    vector<int> winningNumbers;
    vector<int> currentNumbers;

    while (getline(file, input)) {
        input = input.substr(10);
        string number = {};
        int dividerIndex;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '|') {
                dividerIndex = i;
                break;
            } else {
                if (input[i] != ' ') {
                    number += input[i];
                } else {
                    if (number.length() > 0) {
                        winningNumbers.push_back(stoi(number));
                        number = {};
                    }
                }
            }
            
        }

        input = input.substr(dividerIndex + 1);

        for (int i = 0; i < input.length(); i++) {
            if (i == input.length() - 1) {
                number += input[i];
                currentNumbers.push_back(stoi(number));
                number = {};
                break;
            }
            if (input[i] != ' ') {
                number += input[i];
            } else {
                if (number.length() > 0) {
                    currentNumbers.push_back(stoi(number));
                    number = {};
                }
            }
        }

        int points = 0;

        for (int i = 0; i < currentNumbers.size(); i++) {
            for (int j = 0; j < winningNumbers.size(); j++) {
                if (currentNumbers[i] == winningNumbers[j]) {
                    if (points == 0) {
                        points++;
                    } else {
                        points *= 2;
                    }
                }
            }
        }

        result += points;
        points = 0;

        winningNumbers.clear();
        currentNumbers.clear();
        
    }

    cout << result << endl;

    return 0;
}