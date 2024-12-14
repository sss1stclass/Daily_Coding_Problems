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
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    cout << minEatingSpeed(piles, h);
    return 0;
}
