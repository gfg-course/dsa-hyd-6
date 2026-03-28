#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main() {

    cout << kthLargestElement({3, 5, 4, 2, 9}, 3) << endl;
}
