#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("13.txt");
    string input;

    vector <string> map;

    int result = 0;

    while (getline(file, input)) {
        if (input.empty()) {
            string lastCol = {}, curCol = {};
            int cols = 0, rows = 0;
            for (int i = 0; i < map.size(); i++) {
                lastCol += map[i][0];
                curCol += map[i][1];
            }
            if (lastCol == curCol) {
                cols = 0;
            } else {
                for (int i = 2; i < map[0].length(); i++) {
                    lastCol = curCol;
                    curCol = "";
                    for (int j = 0; j < map.size(); j++) {
                        curCol += map[j][i];
                    }
                    if (curCol == lastCol) {
                        cols = i;
                        break;
                    }
                }
            }

            result += cols;

            string lastRow = map[0];
            string curRow = map[1];

            if (lastRow == curRow) {
                rows = 0;
            } else {
                for (int i = 2; i < map.size(); i++) {
                    lastRow = curRow;
                    curRow = map[i];
                    if (curRow == lastRow) {
                        rows = i;
                        break;
                    }
                }
            }

            result += rows*100;

            map.clear();;
        } else {
            map.push_back(input);
        }
    }

    string lastCol = {}, curCol = {};
    int cols = 0, rows = 0;
    for (int i = 0; i < map.size(); i++) {
        lastCol += map[i][0];
        curCol += map[i][1];
    }
    if (lastCol == curCol) {
        cols = 0;
    } else {
        for (int i = 2; i < map[0].length(); i++) {
            lastCol = curCol;
            curCol = "";
            for (int j = 0; j < map.size(); j++) {
                curCol += map[j][i];
            }
            if (curCol == lastCol) {
                cols = i;
                break;
            }
        }
    }

    string lastRow = map[0];
    string curRow = map[1];

    if (lastRow == curRow) {
        rows = 0;
    } else {
        for (int i = 2; i < map.size(); i++) {
            lastRow = curRow;
            curRow = "";
            for (int j = 0; j < map[i].length(); j++) {
                curRow += map[i][j];
            }
            if (curRow == lastRow) {
                rows = i;
                break;
            }
        }
    }

    result += cols + rows*100;

    cout << result << endl;

    return 0;
}