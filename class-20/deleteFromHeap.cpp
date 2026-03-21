#include<bits/stdc++.h>
using namespace std;

void topDownHeapify(int index, vector<int> &heap) {

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    int maxValueIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
    }

    if (maxValueIndex != index) {
        swap(heap[index], heap[maxValueIndex]);
        topDownHeapify(maxValueIndex, heap);
    }
}

// TC: O(log(n))
// AS: O(1) (tail recursive).
void deleteFromHeap(vector<int> &heap) {
    if (heap.size() == 0) {
        return;
    }

    // Step-1: replace root with the last element and delete the last element.
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    // Step-2: top-down heapify on root.
    topDownHeapify(0, heap);
}

int main() {

    vector<int> heap = {100, 40, 50, 10, 15, 32, 30};
    deleteFromHeap(heap);
    for (int i : heap) {
        cout << i << " ";
    }
}
