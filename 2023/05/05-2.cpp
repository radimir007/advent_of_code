#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Seed {
    unsigned long srcStart;
    unsigned long range;
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

    bool pair = false;

    unsigned long src, range;

    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] != ' ') {
            current += temp[i];
            if (i == temp.length()-1) {
                range = stoul(current);
                current = "";
                Seed *seed = new Seed;
                seed->srcStart = src;
                seed->range = range;
                seeds.push_back(*seed);
                pair = false;
            }
        } else {
            if (!pair) {
                src = stoul(current);
                current = "";
                pair = true;
            } else {
                range = stoul(current);
                current = "";
                Seed *seed = new Seed;
                seed->srcStart = src;
                seed->range = range;
                seeds.push_back(*seed);
                pair = false;
            }
        }
    }
    // Skip lines
    getline(file, input);
    getline(file, input);

    while (true) {
        while (getline(file, input)) {
            if (input.empty()) break;

            unsigned long dstStart, srcStart, range;

            string temp = {};
            int i = 0;

            while (input[i] != ' ') {
                temp += input[i];
                i++;
            }
            dstStart = stoul(temp);
            temp = "";
            i++;

            while (input[i] != ' ') {
                temp += input[i];
                i++;
            }
            srcStart = stoul(temp);
            temp = "";
            i++;

            while (i <= input.length()-1) {
                temp += input[i];
                i++;
            }
            range = stoul(temp);
            temp = "";

            for (int i = 0; i < seeds.size(); i++) {
                unsigned long srcEnd = seeds[i].srcStart + seeds[i].range;
                if (srcEnd > srcStart) {
                    unsigned long tempStart = srcStart;
                    unsigned long oldRange = srcEnd - tempStart;

                    unsigned long newRange, newSrcStart = srcStart;
                    if (oldRange >= range) {
                        newRange = range;
                    } else {
                        newRange = oldRange;
                    }

                    seeds[i].srcStart = newSrcStart;
                    seeds[i].range = newRange;
                    seeds[i].manipulated = true;
                }


                /*if (seeds[i].number >= srcStart && seeds[i].number <= srcStart + range) {
                    if (!seeds[i].manipulated) {
                        seeds[i].number = (seeds[i].number - srcStart) + dstStart;
                        seeds[i].manipulated = true;
                    }
                }*/
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

    unsigned long lowestLocation = ULONG_MAX;

    for (int i = 0; i < seeds.size(); i++) {
        for (int j = seeds[i].srcStart; j < seeds[i].srcStart + seeds[i].range; j++) {
            if (j < lowestLocation) {
                lowestLocation = j;
            }
        }
    }

    /*
    for (int i = 1; i < seeds.size(); i++) {
        if (seeds[i].number < lowestLocation) {
            lowestLocation = seeds[i].number;
        }
    } */

    cout << lowestLocation << endl;

    return 0;
}