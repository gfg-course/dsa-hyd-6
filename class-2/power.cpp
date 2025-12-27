#include<bits/stdc++.h>
using namespace std;

// TC: O(log(b))
// AS: O(log(b))
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int temp = power(a, b/2);

    if (b % 2 == 0) {
        return temp * temp;
    }
    return a * temp * temp;
}

int main() {
    cout << power(2, 3) << endl;
    cout << power(2, 0) << endl;
    cout << power(2, 1) << endl;
    cout << power(3, 10) << endl;
}
