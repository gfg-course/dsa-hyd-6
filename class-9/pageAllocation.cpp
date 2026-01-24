#include<bits/stdc++.h>
using namespace std;

// TODO: Painter's partition problem.

bool isPossible(vector<int> &pages, int M, int mid) {

    int numStudents = 1, numPages = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (numPages + pages[i] <= mid) {
            numPages += pages[i];
        } else {
            numStudents++;
            numPages = pages[i];
        }
    }

    return numStudents <= M;
}

// TC: O(n * log(sum))
// AS: O(1)
int allocateBooks(vector<int> pages, int M) {
    int n = pages.size();
    if (n < M) {
        return -1;
    }

    int low = pages[0];
    int high = pages[0];

    for (int i = 1; i < n; i++) {
        low = max(low, pages[i]);
        high += pages[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(pages, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {

    cout << allocateBooks({12, 34, 67, 90}, 2) << endl;
    cout << allocateBooks({10, 20, 10, 30}, 2) << endl;
}
