#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <string> rows;

void tiltToNorth() {
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                int lastPos = i;
                int temp = i;
                while (true) {
                    if (temp - 1 >= 0 && rows[temp-1][j] == '.') {
                        temp--;
                    } else {
                        break;
                    }
                }
                if (lastPos != temp) {
                    rows[lastPos - (lastPos - temp)][j] = 'O';
                    rows[lastPos][j] = '.';
                }
            }
        }
    }
}

void tiltToSouth() {
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                int lastPos = i;
                int temp = i;
                while (true) {
                    if (temp + 1 < rows.size() && rows[temp+1][j] == '.') {
                        temp++;
                    } else {
                        break;
                    }
                }
                if (lastPos != temp) {
                    rows[lastPos + (temp-lastPos)][j] = 'O';
                    rows[lastPos][j] = '.';
                }
            }
        }
    }
}

void tiltToEast() {
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                int lastPos = j;
                int temp = j;
                while (true) {
                    if (temp - 1 >= 0 && rows[i][temp-1] == '.') {
                        temp--;
                    } else {
                        break;
                    }
                }
                if (lastPos != temp) {
                    rows[i][lastPos - (lastPos-temp)] = 'O';
                    rows[i][lastPos] = '.';
                }
                
            }
        }
    }
}

void tiltToWest() {
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].length(); j++) {
            if (rows[i][j] == 'O') {
                int lastPos = j;
                int temp = j;
                while (true) {
                    if (temp + 1 < rows[i].length() && rows[i][temp+1] == '.') {
                        temp++;
                    } else {
                        break;
                    }
                }
                if (lastPos != temp) {
                    rows[i][lastPos + (temp-lastPos)] = 'O';
                    rows[i][lastPos] = '.';
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

    int result = 0;

    for (int i = 0; i < 1000000000; i++) {
        tiltToNorth();
        tiltToWest();
        tiltToSouth();
        tiltToEast();
    }

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