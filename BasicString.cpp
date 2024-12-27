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

bool checkPalindrome(string s) {
    // code here
    int n = s.length();
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

bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }
    return 0;
}

char toLowerCase(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isssPalindrome(string s) {
    string temp = "";
    for (int i = 0; i <= s.length(); i++) {
        if (valid(s[i])) {
            temp.push_back(s[i]);
        }
    }

    for (int i = 0; i < s.length(); i++) {
        temp[i] = toLowerCase(temp[i]);
    }
    cout << temp << endl;
    return checkPalindrome(temp);
}

int main() {
    string st = "A man, a plan, a canal -- Panama";
    char star[20] = "ab_a";
//    cout << largestOddNumber(st);
//    cout << isPalindrome(star);
//    cout << checkLen(star);
    cout << isssPalindrome(st);
    return 0;
}

