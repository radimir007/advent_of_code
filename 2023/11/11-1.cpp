#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Galaxy {
    int posX;
    int posY;
};

int main() {
    ifstream file("11.txt");
    string input;

    vector<string> base_map;

    vector<Galaxy> galaxies;

    int result = 0;

    while(getline(file, input)) {
        base_map.push_back(input);
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != '.') {
                break;
            }

            if (i == input.length() - 1) {
                base_map.push_back(input);
            }
        }
    }

    bool insertion = false;

    for (int i = 0; i < base_map[0].length(); i++) {
        if (insertion) {
            insertion = false;
            continue;
        }
        string temp = "";
        bool isEmpty = true;
        for (int j = 0; j < base_map.size(); j++) {
            temp += base_map[j][i];
            if (base_map[j][i] != '.') {
                isEmpty = false;
            }

            if (j == base_map.size()-1 && isEmpty) {
                for (int k = 0; k < base_map.size(); k++) {
                    base_map[k].insert(i, ".");
                    insertion = true;
                }
            }
        }
    }

    for (int i = 0; i < base_map.size(); i++) {
        for (int j = 0; j < base_map[i].length(); j++) {
            if (base_map[i][j] == '#') {
                Galaxy *galaxy = new Galaxy;
                galaxy->posX = j;
                galaxy->posY = i;
                galaxies.push_back(*galaxy);
            }
        }
    }

    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i; j < galaxies.size(); j++) {
            if (i == j) continue;
            result += abs(galaxies[j].posX - galaxies[i].posX) + abs(galaxies[j].posY - galaxies[i].posY);
        }
    }

    cout << result << endl;
    

    return 0;
}