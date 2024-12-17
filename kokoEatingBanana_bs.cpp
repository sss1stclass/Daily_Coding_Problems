#include<bits/stdc++.h>

using namespace std;

//int minEatingSpeed(vector<int> &piles, int h) {
//    int n = piles.size();
//    int mini = INT_MAX;
//
//    for (int i = 0; i < n; i++) {
//        int sum = 0;
//        for (int j = 0; j < n; j++) {
//            sum += (piles[j] + (i + 1) - 1) / (i + 1);
//        }
//        if (sum <= h) {
//            mini = min(mini, (i + 1));
//        }
//    }
//    return mini;
//}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double) (v[i]) / (double) (hourly));
    }
    return totalH;
}

int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int ans = 0;
    int high = *max_element(piles.begin(), piles.end());
    while (high >= low) {
        int mid = (high + low) / 2;
        if (calculateTotalHours(piles, mid) <= h) {
            ans = mid;
            high = mid - 1;
            cout << "high" << high << endl;
        } else {
            low = mid + 1;
            cout << "low" << low << endl;
        }
    }
    return ans;
}

//int minDays(vector<int> &bloomDay, int m, int k) {
//    int n = *max_element(bloomDay.begin(), bloomDay.end());
//    int s = bloomDay.size();
//    int ans = 0;
//    for (int i = 0; i <= n; i++) {
//
//        for (int j = 0; j < s; j++) {
//            if (bloomDay[j] == i) {
//                bloomDay[j] = -1;
//            }
//        }
//        int count = 0;
//        for (int k = 0; k < s; k++) {
//            if (bloomDay[k] == bloomDay[k + 1]) {
//                count++;
//            }
//        }
//        if ((m / count) >= 1) {
//            ans++;
//        }
//        if (ans == k) {
//            return i;
//        }
//
//    }
//
//    return ans;
//}

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        } else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int minDays(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    int low = *min_element(arr.begin(), arr.end()), high = *max_element(arr.begin(), arr.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, k, m)) {
            high = mid - 1;
        } else low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> piles = {1, 10, 3, 10, 2};
    int h = 5;
//    cout << minEatingSpeed(piles, h);
    cout << minDays(piles, 3, 1);
    return 0;
}
