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
        } else {
            if (nums[high] >= target && nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
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

int singleNonDuplicate(vector<int> &arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
            || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        } else {

            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    for (int i = 0; i <= n; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
//    cout << findMin(nums);
//    int target = findMin(nums);
//    cout << search(nums, target);
//    cout << singleNonDuplicate(nums);
    cout << findPeakElement(nums);
    return 0;
}
