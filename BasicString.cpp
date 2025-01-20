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

void reverseString(vector<char> &s) {
    vector<char> sn;
    int n = s.size() - 1;
    for (int i = 0; i <= n / 2; i++) {
        swap(s[i], s[n - i]);
    }
    for (auto i: s) {
        cout << i << " ";
    }
}

string rev(string st) {
    int n = st.length() - 1;
    for (int i = 0; i < n / 2; i++) {
        swap(st[i], st[n - i]);
    }
    return st;
}

string reverseTotal(string st) {
    string ans = "";
    for (int i = 0; i < st.length(); i++) {
        if (st[i] != ' ') {
            ans.push_back(st[i]);
        }


    }
    string inc = rev(ans);
    cout << inc;
//    cout << ans;
}

string removeOuterParentheses(string s) {
    int balance = 0;
    string result = "";

    for (char c : s) {
        if (c == '(') {
            if (balance > 0) {
                result += c; // Add to result only if we are not at outermost level
            }
            balance++;
        } else {
            balance--;
            if (balance > 0) {
                result += c; // Add to result only if we are not at outermost level
            }
        }
    }

    return result;
}


int main() {
    string st = "this";
    vector<char> ch = {'a', 'h', 'e', 'l'};
//    reverseString(ch);
    st += 'a';
    cout << st;
//    reverseTotal(st);
//    cout << largestOddNumber(st);
//    cout << isPalindrome(star);
//    cout << checkLen(star);
//    cout << isssPalindrome(st);
  vector<int>arr= {1,2,3,3,4};
  cout<<arr.size();
    return 0;
}

