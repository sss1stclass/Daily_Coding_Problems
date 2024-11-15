#include<bits/stdc++.h>

using namespace std;

// number hashing;
//int main() {
//    int n;
//    cin >> n;
//    int arr[n];
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    int hash[13] = {0};
//    for (int i = 0; i < n; i++) {
//        hash[arr[i]]++;
//    }
//    int q;
//    cin >> q;
//    while (q--) {
//        int c;
//        cin >> c;
//        cout << hash[c] << endl;
//    }
//
//    return 0;
//}

// string hashing

int main() {
    string s;
    cin >> s;
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }
    for (auto i: hash) {
        cout << i << " ";
    }
    int t;
    cin >> t;
    while (t--) {
        char ch;
        cin >> ch;
        cout << hash[ch - 'a'];
    }
    return 0;
}