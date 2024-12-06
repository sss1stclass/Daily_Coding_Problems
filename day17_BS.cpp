
#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> nums, int target) {
    int low = 0;
    int n = nums.size();
    int high = n - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;

}

// lowerBound = smallest index of  arr[index]>=x
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 5, 9, 15, 19};
    int n = 5, x = 9;
//    int ind = upperBound(arr, n, x);
    int ind = lowerBound(arr, n, x);
    auto it = lower_bound(arr.begin(), arr.end(), 9);
    cout << it - arr.begin() << endl;

    cout << "The lower bound is the index: " << ind << "\n";
    //    cout << binarySearch(v, target);
    return 0;
}