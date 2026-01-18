#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {"",
                        "", "abc", "def",
                        "ghi", "jkl", "mno",
                        "pqrs", "tuv", "wxyz"};


void getPossibleWordsUtil(int i, vector<int> &arr, string &curr, vector<string> &result) {
    if (i == arr.size()) {
        result.push_back(curr);
        return;
    }

    if (arr[i] <= 1) {
        getPossibleWordsUtil(i + 1, arr, curr, result);
        return;
    }

    for (char ch: keypad[arr[i]]) {
        curr.push_back(ch);
        getPossibleWordsUtil(i + 1, arr, curr, result);
        curr.pop_back();
    }
}

// TC: O(4^n)
// AS: O(n)
vector<string> getPossibleWords(vector<int> arr) {

    string curr = "";
    vector<string> result;
    getPossibleWordsUtil(0, arr, curr, result);
    return result;
}

int main() {

    vector<string> res1 = getPossibleWords({2, 3});
    vector<string> res2 = getPossibleWords({1, 2});

    for (string i : res1) {
        cout << i << " ";
    }
    cout << endl;

    for (string i : res2) {
        cout << i << " ";
    }
    cout << endl;
}
