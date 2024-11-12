#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] + 1 != nums[i + 1]) {
            return nums[i] + 1;
        }
    }

    if (nums[0] != 0) return 0;
    return nums.size();
}

int main() {
    vector<int> nums = {1, 2, 3, 6, 7, 9, 5, 8, 4};
    cout << missingNumber(nums);

    return 0;
}
