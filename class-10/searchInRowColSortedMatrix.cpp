#include<bits/stdc++.h>
using namespace std;

// TC: O(n + m)
// AS: O(1)
bool searchInRowColSortedMatrix(vector<vector<int>> arr, int target) {

    int n = arr.size();
    int m = arr[0].size();

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (arr[i][j] == target) {
            return true;
        }
        if (target < arr[i][j]) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> arr = {{3, 30, 38},
                               {36, 43, 60},
                               {40, 51, 69}};
    
    cout << searchInRowColSortedMatrix(arr, 36) << endl;
    cout << searchInRowColSortedMatrix(arr, 39) << endl;
}
