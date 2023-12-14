#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Seed {
    unsigned long long number;
    bool manipulated = false;
};

int main() {
    ifstream file("05.txt");
    string input;

    vector <Seed> seeds;

    getline(file, input);

    // Load seeds
    string temp = input.substr(7);
    string current = {};

    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] != ' ') {
            current += temp[i];
            if (i == temp.length()-1) {
                Seed *seed = new Seed;
                seed->number = stoull(current);
                seeds.push_back(*seed);
                current = "";
            }
        } else {
            Seed *seed = new Seed;
            seed->number = stoull(current);
            seeds.push_back(*seed);
            current = "";
        }
    }

    // Skip lines
    getline(file, input);
    getline(file, input);

    while (true) {
        while (getline(file, input)) {
            if (input.empty()) break;

            unsigned long long dstStart, srcStart, range;

            string temp = {};
            int i = 0;

            while (input[i] != ' ') {
                temp += input[i];
                i++;
            }
            dstStart = stoull(temp);
            temp = "";
            i++;

            while (input[i] != ' ') {
                temp += input[i];
                i++;
            }
            srcStart = stoull(temp);
            temp = "";
            i++;

            while (i <= input.length()-1) {
                temp += input[i];
                i++;
            }
            range = stoull(temp);
            temp = "";

            for (int i = 0; i < seeds.size(); i++) {
                if (seeds[i].number >= srcStart && seeds[i].number <= srcStart + range) {
                    if (!seeds[i].manipulated) {
                        seeds[i].number = (seeds[i].number - srcStart) + dstStart;
                        seeds[i].manipulated = true;
                    }
                }
            }
        }

        for (int i = 0; i < seeds.size(); i++) {
            seeds[i].manipulated = false;
        }

        if (!file.eof()) {
            getline(file, input);
        } else {
            break;
        }
    }

    unsigned long long lowestLocation = seeds[0].number;

    for (int i = 1; i < seeds.size(); i++) {
        if (seeds[i].number < lowestLocation) {
            lowestLocation = seeds[i].number;
        }
    }

    cout << lowestLocation << endl;

    return 0;
}