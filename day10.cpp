#include<bits/stdc++.h>

using namespace std;

// bruete force approach
//int getLongestSubarray(vector<int> &a, long long k) {
//    int n = a.size();
//
//    int len = 0;
//    for (int i = 0; i < n; i++) {
//        long long s = 0;
//        for (int j = i; j < n; j++) {
//            s += a[j];
//            if (s == k)
//                len = max(len, j - i + 1);
//        }
//    }
//    return len;
//}

//optimal solution

int getLongestSubarray(vector<int> &a, long long k) {
    int right = 0;
    int left = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while (right < n) {
        if (right < n) {
            sum += a[right];
        }
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
//            maxLen = max(maxLen, (right - left + 1)); // for longest array
            maxLen++;  // for the total number of max array of subarray
        }
        right++;

    }
    return maxLen;
}


int main() {
    vector<int> arr = {1};
    int k = 0;
    cout << getLongestSubarray(arr, k);

    return 0;
}
