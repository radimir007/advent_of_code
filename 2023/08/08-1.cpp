#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    string subNode1;
    string subNode2;
};

int main() {
    ifstream file("08.txt");
    string input;
    string instructions;

    int counter = 0;

    map<string, Node> nodes;

    file >> instructions;

    // Skip empty rows
    getline(file, input);
    getline(file, input);

    while (getline(file, input)) {
        string tempName, tempNode1, tempNode2;
        tempName = input.substr(0, 3);
        tempNode1 = input.substr(7, 3);
        tempNode2 = input.substr(12, 3);

        Node *node = new Node;
        node->subNode1 = tempNode1;
        node->subNode2 = tempNode2;

        nodes.insert({tempName, *node});
    }

    string currentNode = "AAA";

    bool found = false;

    while (!found) {
        for (int i = 0; i < instructions.length(); i++) {
            switch (instructions[i]) {
                case 'L':
                    currentNode = nodes.find(currentNode)->second.subNode1;
                    counter++;
                    break;

                case 'R':
                    currentNode = nodes.find(currentNode)->second.subNode2;
                    counter++;
                    break;
            }

            if (currentNode == "ZZZ") {
                found = true;
                break;
            }
        }

        if (found) {
            break;
        } 
    }

    cout << counter << endl;

    return 0;
}