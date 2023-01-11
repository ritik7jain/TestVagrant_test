#include<bits/stdc++.h>
using namespace std;

struct News {
    string name;
    double prices[7]; 
};

bool check_combination(vector<string>& combination, double budget, vector<News>& newspapers) {
    double total_cost = 0;
    for (string n : combination) {
        for (News newspaper : newspapers) {
            if (newspaper.name == n) {
                for (int i = 0; i < 7; i++) {
                    total_cost += newspaper.prices[i];
                }
            }
        }
    }
    return total_cost <= budget;
}

int main() {
    // create a vector of newspapers
    vector<News> newspapers = {
        {"TOI", {3, 3, 3, 3, 3, 5, 6}},
        {"Hindu", {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4}},
        {"ET", {4, 4, 4, 4, 4, 4, 10}},
        {"BM", {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5}},
        {"HT", {2, 2, 2, 2, 2, 4, 4}}
    };

    double budget;
    cout << "Enter weekly budget ";
    cin >> budget;

    vector<vector<string>> combinations;

    for (int i = 0; i < newspapers.size(); i++) {
        for (int j = i + 1; j < newspapers.size(); j++) {
            vector<string> combination = {newspapers[i].name, newspapers[j].name};
            if (check_combination(combination, budget, newspapers)) {
                combinations.push_back(combination);
            }
        }
    }

    cout << "All possible combinations of newspaper subscriptions within budget: " << endl;
    for (vector<string> combination : combinations) {
        cout << "{ ";
        for (string n : combination) {
            cout << n << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
