#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream file("02.txt");
    string input;

    int result = 0;

    vector<string> rounds = {};
    vector<string> colors = {};

    while (getline(file, input)) {
        rounds.clear();
        colors.clear();
        string gameId = {};
        int index = 5;
        while (input[index] != ':') {
            gameId += input[index];
            index++;
        }

        index++;

        string currentRound = {};

        bool isPossible = true;

        for (int i = index+1; i < input.length(); i++) {
            if (input[i] != ';' && i < input.length()-1) {
                currentRound += input[i];
            } else {
                if (i == input.length()-1) {
                    currentRound += input[i];
                }
                rounds.push_back(currentRound);
                currentRound = {};
                i++;
            }
        }

        string temp = {};

        for (int i = 0; i < rounds.size(); i++) {
            for (int j = 0; j < rounds[i].length(); j++) {
                if (rounds[i][j] != ',') {
                    temp += rounds[i][j];
                    if (j == rounds[i].length() - 1) {
                        colors.push_back(temp);
                        temp = {};
                    }
                } else {
                    colors.push_back(temp);
                    temp = {};
                    j++;
                }
            }

            for (int j = 0; j < colors.size(); j++) {
                int index = colors[j].find(' ');
                string count = colors[j].substr(0, 0 + index);
                string color = colors[j].substr(index+1);

                if (color == "red") {
                    if (stoi(count) > 12) {
                        isPossible = false;
                    }
                } else if (color == "green") {
                    if (stoi(count) > 13) {
                        isPossible = false;
                    }
                } else if (color == "blue") {
                    if (stoi(count) > 14) {
                        isPossible = false;
                    }
                }
            }
            colors.clear();
        }

        if (isPossible) {
            result += stoi(gameId);
        }
        
    }

    cout << result << endl;

    return 0;
}
