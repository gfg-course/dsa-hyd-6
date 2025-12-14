
// TC: O(A + B)

for (int i = 0; i < A.size(); i++) { 
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) { 
    cout << B[i] << endl;
}

// ---------------------------------------------------

// TC: O(A * B)
for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

// TC: O(n^2)
void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

// TC: O(n^2 * m)
void func(int n, string s) { // size of s = m
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl; // printing a string
        }
    }
}

// ---------------------------------------------------

// Input Space: O(m^2)
// Output Space: O(k)
// Aux Space: O(n)

// Space Complexity: O(m^2 + n + k)
vector<int> func(vector<vector<int>> arr) { // arr: m^2, output: k
    // ....
    vector<int> temp(n);
    // ....

    vector<int> result;
    // ....
    return result;
}

// ---------------------------------------------------

// I/P Space: O(m * length_of_the_largest_string_in_arr)
// Output Space: O(k)
// Aux Space: O(n * length_of_the_largest_string_in_temp)
string func(vector<string> arr) { // arr: m
    // ...
    vector<string> temp(n);

    // ...
    return result; // length = k
}