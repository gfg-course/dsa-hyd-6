#include<bits/stdc++.h>
using namespace std;

// return true -> if a should occur before b.
// return false -> if b should occur before a.
bool cmp(pair<int, char> &a, pair<int, char> &b) {

    if (a.first == b.first) {
        // if (a.second == 'a') {
        //     return true;
        // }
        // return false;
        return a.second == 'a';
    }

    // if (a.first < b.first) {
    //     return true;
    // }
    // return false;
    return a.first < b.first;
}

// TC: O(n * log(n))
// AS: O(n)
int getMinPlatforms(vector<int> arr, vector<int> dep) {
    int n = arr.size();

    vector<pair<int, char>> timeline;
    for (int i = 0; i < n; i++) {
        timeline.push_back({arr[i], 'a'});
        timeline.push_back({dep[i], 'd'});
    }

    sort(timeline.begin(), timeline.end(), cmp);

    int currentPlatforms = 0, maxPlatforms = 0;
    for (int i = 0; i < timeline.size(); i++) {
        if (timeline[i].second == 'a') {
            currentPlatforms++;
        } else {
            currentPlatforms--;
        }
        maxPlatforms = max(maxPlatforms, currentPlatforms);
    }

    return maxPlatforms;
}

int main() {
    cout << getMinPlatforms({900,940,950,1100,1500,1800}, {910,1200,1120,1130,1900,2000}) << endl;
    cout << getMinPlatforms({900,910},{910,920}) << endl;
}
