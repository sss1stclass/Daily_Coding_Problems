#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    int n = nums.size();
    int high = n - 1;
    int low = 0;

    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int high = n - 1;
    int low = 0;
    int ans = n;
    int last = n;
    vector<int> temp = {};
    vector<int> nest = {-1, -1};
    int val = search(nums, target);
    if (val != -1) {
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                last = mid + 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        temp.push_back(ans);
        temp.push_back(last);
        nums = temp;
        return nums;
    } else {
        nums = nest;
        return nums;
    }

}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    searchRange(nums, target);
    for (auto it: nums) {
        cout << it << " ";
    }

    return 0;
}
