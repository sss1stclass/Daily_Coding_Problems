#include<bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (piles[j] + (i + 1) - 1) / (i + 1);
        }
        if (sum <= h) {
            mini = min(mini, (i + 1));
        }
    }
    return mini;
}

int main() {
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    cout << minEatingSpeed(piles, h);
    return 0;
}
