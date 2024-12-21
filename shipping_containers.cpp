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

// brute force approach

int minWeight(vector<int> weights, int d) {
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++) {
        if (countNoOfDays(weights, i) <= d) {
            return i;
        }
    }
    return -1;
}

// best and optimal with bs

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

//int findKthPositive(vector<int> &arr, int k) {
//    vector<int> temp;
//    for (int i = 1; i <= 13; i++) {
//        bool found = false;
//        for (int j = 0; j < arr.size(); j++) {
//            if (arr[j] == i) {
//                found = true;
//            }
//        }
//        if (found == false) {
//            temp.push_back(i);
//        }
//    }
//    return temp[k - 1];
//
//}

//    int findKthPositive(vector<int>& arr, int k) {
//    for(int i =0;i<arr.size();i++){
//        if(arr[i]<=k){
//            k++;
//        }else break;
//    }
//    return k;
//    }

int findKthPositive(vector<int> &arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (high >= low) {
        int mid = (high + low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return k + low;
}

int aggresiveCows(vector<int> v, int k, int n) {

}

int main() {
    vector<int> v = {2, 3, 4, 7, 11};
    int days = 5;
//    cout << shipWithinDays(v, days);
    cout << findKthPositive(v, days);
//    cout << countTotal(v) << endl;
//    cout << maxEleme(v) << endl;
    return 0;
}
