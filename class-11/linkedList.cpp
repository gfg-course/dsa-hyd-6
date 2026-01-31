#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;

    LinkedList() {
        head = NULL;
    }
    
    // TC: O(1)
    // AS: O(1)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    // AS: O(1)
    void insertAtEnd(int value) {
        if (head == NULL) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // TC: O(min(pos, n))
    // AS: O(1)
    void insertAtPos(int value, int pos) {
        if (pos <= 0 || head == NULL) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        int hops = 0;
        while (hops < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* newNode = new Node(value);
        Node* temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }

    // TC: O(1)
    // AS: O(1)
    void deleteAtBeginning() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete(temp);
    }

    // TC: O(n)
    // AS: O(1)
    void deleteAtEnd() {
        if (head == NULL || head->next == NULL) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* temp2 = temp->next;
        temp->next = NULL;
        delete(temp2);
    }

    // TC: O(min(pos, n))
    // AS: O(1)
    void deleteAtPos(int pos) {
        if (pos == 0 || head == NULL) {
            deleteAtBeginning();
            return;
        }

        int hops = 0;
        Node* temp = head;
        while (hops < pos - 1 && temp != NULL) {
            temp = temp->next;
            hops++;
        }

        // Do not delete anything if pos > n-1.
        if (temp == NULL) {
            return;
        }

        Node* temp2 = temp->next;
        temp->next = temp->next->next;
        delete(temp2);
    }

    // TC: O(n)
    // AS: O(1)
    void reverse() {
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    // TC: O(n)
    // AS: O(1)
    int getMiddle() {
        if (head == NULL) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    // TC: O(n)
    // AS: O(1)
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* ll = new LinkedList();
    ll->insertAtBeginning(5);
    ll->insertAtBeginning(4);
    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);
    ll->print(); // 1 2 3 4 5

    ll->insertAtEnd(6);
    ll->print(); // 1 2 3 4 5 6

    ll->insertAtPos(7, 4); // 1 2 3 4 7 5 6
    ll->insertAtPos(8, 100); // 1 2 3 4 7 5 6 8
    ll->insertAtPos(0, 0); // 0 1 2 3 4 7 5 6 8
    ll->print(); // 0 1 2 3 4 7 5 6 8

    ll->deleteAtBeginning();
    ll->deleteAtBeginning();
    ll->print(); // 2 3 4 7 5 6 8

    ll->deleteAtEnd();
    ll->print(); // 2 3 4 7 5 6

    ll->deleteAtPos(2); // 2 3 7 5 6
    ll->deleteAtPos(20); // 2 3 7 5 6
    ll->deleteAtPos(0); // 3 7 5 6
    ll->print();

    ll->reverse();
    ll->print(); // 6 5 7 3

    cout << ll->getMiddle() << endl; // 5
    
    ll->insertAtEnd(2); // 6 5 7 3 2
    ll->print();
    cout << ll->getMiddle() << endl; // 7
}
