#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
bool binarySearch(vector<int> arr, int target) {

    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return true;
        }
        if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {

    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 20) << endl;
    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 1) << endl;
    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 27) << endl;
    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 18) << endl;
    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 0) << endl;
    cout << binarySearch({1, 3, 10, 16, 20, 25, 27}, 30) << endl;
}
