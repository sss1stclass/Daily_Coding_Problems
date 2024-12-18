#include<bits/stdc++.h>

using namespace std;

int countTotal(vector<int> v) {
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return sum;
}

int maxEleme(vector<int> v) {
    int n = v.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (v[i] >= maxi) {
            maxi = v[i];
        }
    }
    return maxi;
}

int countNoOfDays(vector<int> weights, int cap) {
    int n = weights.size();
    int days = 1;
    int load = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] + load > cap) {
            days += 1;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int> &weights, int days) {
//    int low = maxEleme(weights);
//    int high = countTotal(weights);
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0); // we can use stl to collect such data;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (countNoOfDays(weights, mid) <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;

}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(v, days);
//    cout << countTotal(v) << endl;
//    cout << maxEleme(v) << endl;
    return 0;
}
