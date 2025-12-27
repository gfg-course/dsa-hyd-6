#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {
    // bool isLowercase = (ch >= 'a' && ch <= 'z');
    // bool isUppercase = (ch >= 'A' && ch <= 'Z');
    // bool isDigit = (ch >= '0' && ch <= '9');

    // return isLowercase || isUppercase || isDigit;

    return 
        (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9');
}

bool isSame(char ch1, char ch2) {

    return 
        (ch1 == ch2) ||
        (ch1 - 'A' + 'a' == ch2) ||
        (ch1 == ch2 - 'A' + 'a');
}

// TC: O(n)
// AS: O(1)
bool isSpecialPalindrome(string s) {

    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (!isAlphaNumeric(s[i])) {
            i++;
        } else if (!isAlphaNumeric(s[j])) {
            j--;
        } else {
            if (!isSame(s[i], s[j])) {
                return false;
            }
            i++;
            j--;
        }
    }

    return true;
}

int main() {

    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: Nama") << endl;
    cout << isSpecialPalindrome("level") << endl;
    cout << isSpecialPalindrome("levels") << endl;
    cout << isSpecialPalindrome("lev 0 1 0 vEL") << endl;
}
