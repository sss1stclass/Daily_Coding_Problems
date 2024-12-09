#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;

}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target);

    return 0;
}
