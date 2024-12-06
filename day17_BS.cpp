
#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> nums, int target) {
    int low = 0;
    int n = nums.size();
    int high = n - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == target) {
            if (mid > 0) {
                return mid - 1;
            } else return 0;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;

}

int main() {
    vector<int> v = {};
    int target = ;
    cout << binarySearch(v, target);


    return 0;
}