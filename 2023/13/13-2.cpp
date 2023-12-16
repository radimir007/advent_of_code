#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("13.txt");
    string input;

    vector <string> map;

    bool vertical = true;

    int result = 0;

    while (getline(file, input)) {
        if (input.empty()) {
            int cols = 0, rows = 0;
            if (vertical) {
                string lastCol = "", curCol = "";
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
                vertical = false;
                result += cols;
            } else {
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
                vertical = true;
                result += rows*100;

                cout << rows * 100 << endl;
            }

            map.clear();
        } else {
            map.push_back(input);
        }
    }

    int rows = 0;

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

    result += rows*100;

    cout << result << endl;

    return 0;
}