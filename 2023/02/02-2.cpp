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

        int red = 0, green = 0, blue = 0;

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
                    if (red == 0) {
                        red = stoi(count);
                    }
                    if (stoi(count) > red) {
                        red = stoi(count);
                    }
                } else if (color == "green") {
                    if (green == 0) {
                        green = stoi(count);
                    }
                    if (stoi(count) > green) {
                        green = stoi(count);
                    }
                } else if (color == "blue") {
                    if (blue == 0) {
                        blue = stoi(count);
                    }
                    if (stoi(count) > blue) {
                        blue = stoi(count);
                    }
                }
            }
            colors.clear();
        }
        
        result += (red * green * blue);
        red = 0;
        green = 0;
        blue = 0;
    }

    cout << result << endl;

    return 0;
}