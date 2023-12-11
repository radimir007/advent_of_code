#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

vector<string> engine;

int getGearRatio(const int indexI, const int indexJ, const bool endOfLine) {
    int up = indexI;
    if (indexI - 1 >= 0) up--;
    int bottom = indexI;
    if (bottom + 1 < engine.size()) bottom++;
    int left = indexJ - 1;
    int right = indexJ + 1;

    if (endOfLine) {left++;}

    string temp = "";

    vector<int> numbers;

    unsigned long long result = 0;

    map<int, int> used_positions;

    for (int i = up; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            bool isUsed = false;
            
            if (isdigit(engine[i][j])) {
                int index = j;
                while (isdigit(engine[i][index-1])) {
                    index--;
                }
                while(isdigit(engine[i][index])) {
                    if (used_positions.size() > 0) {
                        for (auto k : used_positions) {
                            if (k.first == i && k.second == index) {
                                isUsed = true;
                            }
                        }
                    }
                    
                    temp += engine[i][index];
                    used_positions.insert({i, index});
                    index++;
                }

                if (!isUsed) {
                    numbers.push_back(stoi(temp));
                }
                
                temp = "";
            }
        }
    }

    if (numbers.size() > 1) {
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = 0; j < numbers.size(); j++) {
                for (int k = 0; k < numbers.size(); k++) {
                    if (j == k) continue;

                    if (numbers[j] == numbers[k]) {
                        numbers.erase(numbers.begin() + j);
                    }    
                }
                
            }
        }

        result = numbers[0] * numbers[1];

        return result;
    }

    return 0;
}

int main() {
    ifstream file("03.txt");
    string input;

    unsigned long long result = 0;

    while (getline(file, input)) {
        engine.push_back(input);
    }


    for (int i = 0; i < engine.size(); i++) {
        bool endOfLine = false;
        for (int j = 0; j < engine[i].length(); j++) {
            if (engine[i][j] == '*') {
                if (j == engine[i].length() - 1) {
                    endOfLine = true;
                }
                result += getGearRatio(i, j, endOfLine);
            }
        }
    }

    cout << result << endl;

    return 0;
}