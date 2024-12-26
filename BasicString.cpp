#include<bits/stdc++.h>

using namespace std;

string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int checkLen(char ch[]) {
    int len = 0;
    for (int i = 0; ch[i] != '\0'; i++) {
        len++;
    }
    return len;
}

bool isPalindrome(char s[]) {
    // code here
    int n = strlen(s);
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    string st = "52";
    char star[20] = "abbaaa";
    cout << largestOddNumber(st);
    cout << isPalindrome(star);
//    cout << checkLen(star);
    return 0;
}

