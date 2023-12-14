#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

unordered_map <char, int> cardValues = {
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13},
    {'A', 14}
};

struct Hand {
    int cards[5] = {};
    int rank = 1;
    int winnings = 0;
    string combo = "";
};

string checkCombo(const string input) {
    unordered_map <char, int> cards;

    for (int i = 0; i < input.size(); i++) {
        if (cards.count(input[i])) {
            cards.find(input[i])->second++;
        } else {
            cards.insert({input[i], 1});
        }
    }

    if (cards.size() == 1) {
        return "five_of_kind";
    } else if (cards.size() == 2) {
        vector<int> counts;
        for (auto i : cards) {
            counts.push_back(i.second);
        }
        if (counts[0] == 4 || counts[1] == 4) {
            return "four_of_kind";
        } else if (counts[0] == 3 || counts[1] == 3) {
            if (counts[0] == 2 || counts[1] == 2) {
                return "full_house";
            } else {
                return "three_of_kind";
            }
        }
    } else if (cards.size() > 2) {
        int pairCount = 0;
        for (auto i : cards) {
            if (i.second == 3) {
                return "three_of_kind";
            } else if (i.second == 2) {
                pairCount++;
            }
        }
        switch (pairCount) {
            case 2:
                return "two_pairs";
            case 1:
                return "one_pair";
            default:
                return "high_card";
        }
    }

    return "0";
}

int main() {
    ifstream file("07.txt");
    string input;

    map <Hand,int> cards;

    while (getline(file, input)) {
        string currentCards = {};
        int index = 0;
        while (input[index] != ' ') {
            currentCards += input[index];
            index++;
        }
        index++;
        int winnings = stoi(input.substr(index));

        Hand *hand = new Hand;
        for (int i = 0; i < currentCards.length(); i++) {
            hand->cards[i] = cardValues.find(currentCards[i])->second;
        }

        hand->winnings = winnings;

        hand->combo = checkCombo(currentCards);

        cards.insert({*hand, 1});
    }

    int currentRank = 1;
    int comboCount = 0;

    for (auto i : cards) {
        if (i.first.combo == "five_of_kind") {
            
        }
    }

    return 0;
}