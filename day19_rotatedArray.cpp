#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (high >= low) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        // for the duplicate elements
//        if(nums[low]==nums[mid] && nums[high]==nums[mid]){
//            low=low+1;
//            high = high-1;
//            continue;
//        }
        if (nums[mid] >= nums[low]) {
            if (nums[low] <= target && nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            cout << nums[mid] << "less" << endl;
        } else {
            if (nums[high] >= target && nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            cout << nums[mid] << "high" << endl;
        }
    }
    return -1;

}

int findMin(vector<int> &nums) {
    int n = nums.size();
    int mini = INT_MAX;
    int high = n - 1;
    int low = 0;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (nums[low] <= nums[mid]) {
            mini = min(nums[low], mini);
            low = mid + 1;
        } else {
            mini = min(nums[mid], mini);
            high = mid - 1;
        }
    }
    return mini;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2, 0};
    cout << findMin(nums);
//    int target = 0;
//    cout << search(nums, target);

    return 0;
}
