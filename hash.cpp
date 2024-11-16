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

int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    long maxFreq = 0;
    long left = 0;
    long long sum = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];
        while (nums[right] * (right - left + 1) - sum > k) {
            sum -= nums[left];
            left++;
        }
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}

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