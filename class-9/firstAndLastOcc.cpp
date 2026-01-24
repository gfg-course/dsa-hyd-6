#include<bits/stdc++.h>
using namespace std;

int getFirstOcc(vector<int> &arr, int target, bool isFirstOcc) {

    int result = -1;
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int getLastOcc(vector<int> &arr, int target) {

    int result = -1;
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

// TC: O(log(n))
// AS: O(1)
vector<int> getFirstAndLastOcc(vector<int> arr, int target) {

    int firstOcc = getFirstOcc(arr, target);
    if (firstOcc == -1) {
        return {-1, -1};
    }
    int lastOcc = getLastOcc(arr, target);

    return {firstOcc, lastOcc};
}

int main() {

    vector<int> res1 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    vector<int> res2 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 67);
    vector<int> res3 = getFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 128);

    cout << res1[0] << " " << res1[1] << endl;
    cout << res2[0] << " " << res2[1] << endl;
    cout << res3[0] << " " << res3[1] << endl;
}
