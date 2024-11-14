#include<bits/stdc++.h>

using namespace std;

int getLongestSubarray(vector<int> &a, long long k) {
    int n = a.size();

    int len = 0;
    for (int i = 0; i < n; i++) {
        long long s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            if (s == k)
                len = max(len, j - i + 1);
//                len++;
        }
    }
    return len;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9, 15};
    int k = 15;
    cout << getLongestSubarray(arr, k);

    return 0;
}
