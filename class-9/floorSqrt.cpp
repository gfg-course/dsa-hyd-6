#include<bits/stdc++.h>
using namespace std;

// TODO: Try to extend this to return the answer till the second decimal place.

// TC: O(log(n))
// AS: O(1)
int getFloorSqrt(int n) {
    int result = 0;
    int low = 0, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        }

        if (mid * mid < n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    cout << getFloorSqrt(0) << endl;
    cout << getFloorSqrt(1) << endl;
    cout << getFloorSqrt(25) << endl;
    cout << getFloorSqrt(40) << endl;
}
