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

int minDays(vector<int> &bloomDay, int m, int k) {
    int n = *max_element(bloomDay.begin(), bloomDay.end());
    int s = bloomDay.size();
    int ans = 0;
    for (int i = 0; i <= n; i++) {

        for (int j = 0; j < s; j++) {
            if (bloomDay[j] == i) {
                bloomDay[j] = -1;
            }
        }
        int count = 0;
        for (int k = 0; k < s; k++) {
            if (bloomDay[k] == bloomDay[k + 1]) {
                count++;
            }
        }
        if ((m / count) >= 1) {
            ans++;
        }
        if (ans == k) {
            return i;
        }

    }

    return ans;
}

int main() {
    vector<int> piles = {7, 7, 7, 7, 13, 11, 12, 7};
    int h = 5;
//    cout << minEatingSpeed(piles, h);
    cout << minDays(piles, 2, 3);
    return 0;
}
