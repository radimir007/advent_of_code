#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <string> rows;

void tiltToNorth() {
    int moveCount = 0;

    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                int temp = i;
                while (true) {
                    if (temp - 1 >= 0 && rows[temp-1][j] == '.') {
                        rows[temp-1][j] = 'O';
                        rows[temp][j] = '.';
                        temp--;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    ifstream file("14.txt");
    string input;

    while (getline(file, input)) {
        rows.push_back(input);
    }

    tiltToNorth();

    int result = 0;

    for (int i = 0; i < rows.size(); i++) {
        int tempResult = 0;
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                tempResult++;
            }
        }
        result += tempResult * (rows.size() - i);
    }

    cout << result << endl;

    return 0;
}