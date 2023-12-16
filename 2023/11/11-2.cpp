#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>

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

    unordered_map <int, int> rows;
    unordered_map <int, int> cols;

    unsigned long long result = 0;

    int rowCount = 0;

    while(getline(file, input)) {
        base_map.push_back(input);
        int galaxyCount = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != '.') {
                galaxyCount++;
            }
        }

        rows.insert({rowCount, galaxyCount});

        rowCount++;
    }

    for (int i = 0; i < base_map[0].length(); i++) {
        int galaxyCount = 0;
        for (int j = 0; j < base_map.size(); j++) {
            if (base_map[j][i] != '.') {
                galaxyCount++;
            }
        }
        cols.insert({i, galaxyCount});
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
        for (int j = i+1; j < galaxies.size(); j++) {
            int emptyRowsPassed = 0;
            for (int k = galaxies[i].posY; k < galaxies[j].posY; k++) {
                int curCount = rows.find(k)->second;
                if (curCount == 0) {
                    emptyRowsPassed++;
                }
            }

            int emptyColsPassed = 0;
            if (galaxies[j].posX > galaxies[i].posX) {
                for (int k = galaxies[i].posX; k <= galaxies[j].posX; k++) {
                    int curCount = cols.find(k)->second;
                    if (curCount == 0) {
                        emptyColsPassed++;
                    }
                }
            } else {
                for (int k = galaxies[j].posX; k <= galaxies[i].posX; k++) {
                    int curCount = cols.find(k)->second;
                    if (curCount == 0) {
                        emptyColsPassed++;
                    }
                }
            }

            result += abs(galaxies[i].posX - galaxies[j].posX) + abs(galaxies[i].posY - galaxies[j].posY) + (emptyRowsPassed + emptyColsPassed) * 999999;
        }
    }

    cout << result << endl;
    

    return 0;
}