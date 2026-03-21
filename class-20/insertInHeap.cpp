#include<bits/stdc++.h>
using namespace std;

void bottomUpHeapify(int index, vector<int> &heap) {

    int parentIndex = (index - 1) / 2;
    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(parentIndex, heap);
    }
}

// TC: O(log(n))
// AS: O(1)
void insertInHeap(vector<int> &heap, int value) {
    
    // Step-1: Insert value at the end to get rid of the structural requirements.
    heap.push_back(value);

    // Step-2: Bottom-up heapiy on the last node.
    bottomUpHeapify(heap.size() - 1, heap);
}

int main() {
    vector<int> heap = {10, 5, 3, 2, 4};
    insertInHeap(heap, 15);
    for (int i : heap) {
        cout << i << " ";
    }
}
