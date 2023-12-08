#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> engine;

bool isAdjacent(const string digit, const int indexI, const int indexJ) {
    int up = indexI;
    if (indexI - 1 >= 0) up--;
    int bottom = indexI;
    if (bottom + 1 < engine.size()) bottom++;
    int left = indexJ - digit.length();
    if (left - 1 > 0) left--;
    int right = indexJ - 1;
    if (right >= engine[0].length()) right--;

    for (int i = up; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (!isdigit(engine[i][j])) {
                if (engine[i][j] != '.')
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ifstream file("03.txt");
    string input;

    long result = 0;

    engine.clear();

    while (getline(file, input)) {
        engine.push_back(input);
    }

    string currentDigit = "";

    for (int i = 0; i < engine.size(); i++) {
        for (int j = 0; j < engine[i].length(); j++) {
            if (isdigit(engine[i][j])) {
                currentDigit += engine[i][j];
            } else if (!isdigit(engine[i][j]) && currentDigit != "") {
                if (isAdjacent(currentDigit, i, j)) {
                    result += stoi(currentDigit);
                }
                currentDigit = "";
            }
        }
    }

    cout << result << endl;

    return 0;
}