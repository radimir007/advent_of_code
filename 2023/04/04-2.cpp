#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_winning_numbers_count(string input) {
    vector<int> winningNumbers;
    vector<int> currentNumbers;

    input = input.substr(10);
    string number = {};
    int dividerIndex;

    int result = 0;

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

    for (int i = 0; i < currentNumbers.size(); i++) {
        for (int j = 0; j < winningNumbers.size(); j++) {
            if (currentNumbers[i] == winningNumbers[j]) {
                result++;
            }
        }
    }

    return result;
}

int main() {
    ifstream file("04.txt");
    string input;

    vector<string> cards;

    while (getline(file, input)) {
        string cardNumber = {};
        string winningCount = to_string(get_winning_numbers_count(input));
        input = input.substr(5);
        int index = 0;
        while (input[index] != ':') {
            if (isdigit(input[index])) {
                cardNumber += input[index];
            }
            
            index++;
        }

        string card = cardNumber + ':' + winningCount;

        cards.push_back(card);
    }

    for (int i = 0; i < cards.size(); i++) {
        int index = cards[i].find(':');
        string cardNumber = {};
        for (int j = 0; j < cards[i].length(); j++) {
            if (cards[i][j] == ':') break;
            cardNumber += cards[i][j];

        }

        int winningCount = stoi(cards[i].substr(index+1));
        if (winningCount != 0) {

            for (int j = stoi(cardNumber); j <= stoi(cardNumber) + winningCount; j++) {
                for (int k = 0; k < cards.size(); k++) {
                    string currentNumber = {};
                    int indexIn = cards[k].find(':');
                    for (int l = 0; l < indexIn; l++) {
                        currentNumber += cards[k][l];
                    }
                    if (currentNumber == to_string(j) && currentNumber != cardNumber) {
                        cards.push_back(cards[k]);
                        sort(cards.begin(), cards.end());
                        break;
                    }
                }
            }

        } else {
            continue;
        }
    }

    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i] << endl;
    }

    cout << cards.size() << endl;

    return 0;
}