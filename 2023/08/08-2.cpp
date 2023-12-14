#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    string subNode1;
    string subNode2;
};

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a * b) / gcd(a, b);
}

unsigned long long findLCM(vector <int> results, int n) {
    unsigned long long result = results[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, results[i]);
    }
    return result;
}



int main() {
    ifstream file("08.txt");
    string input;
    string instructions;

    int counter = 0;

    map<string, Node> nodes;

    vector<string> currentNodes;

    file >> instructions;

    // Skip empty rows
    getline(file, input);
    getline(file, input);

    while (getline(file, input)) {
        string tempName, tempNode1, tempNode2;
        tempName = input.substr(0, 3);
        tempNode1 = input.substr(7, 3);
        tempNode2 = input.substr(12, 3);

        if (tempName[2] == 'A') {
            currentNodes.push_back(tempName);
        }

        Node *node = new Node;
        node->subNode1 = tempNode1;
        node->subNode2 = tempNode2;

        nodes.insert({tempName, *node});
    }

    bool found = false;

    vector <int> results;

    for (int i = 0; i < currentNodes.size(); i++) {
        found = false;
        unsigned long tempCount = 0;
        while (!found) {
            for (int j = 0; j < instructions.length(); j++) {
                switch(instructions[j]) {
                    case 'L':
                        currentNodes[i] = nodes.find(currentNodes[i])->second.subNode1;
                        break;

                    case 'R':
                        currentNodes[i] = nodes.find(currentNodes[i])->second.subNode2;
                        break;
                }

                tempCount++;

                if (currentNodes[i][2] == 'Z') {
                    results.push_back(tempCount);

                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }

    cout << findLCM(results, results.size()) << endl;

    return 0;
}