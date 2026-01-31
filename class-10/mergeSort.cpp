#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {

    int i = low, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

// T(n) = 2*T(n/2) + n
// TC: O(n * log(n))
// AS: O(n)
void mergeSortUtil(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortUtil(arr, low, mid); // arr[low ... mid]
    mergeSortUtil(arr, mid + 1, high); // arr[mid+1 ... high]
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr) {
    mergeSortUtil(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr = {1, 10, 12, 3, 5, 3, 2, 60};
    mergeSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }
}
