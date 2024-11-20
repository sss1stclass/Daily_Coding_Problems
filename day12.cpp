
#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> temp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                temp.push_back(i);
                temp.push_back(j);
                break;
            }
        }
    }
    nums = temp;
    return nums;
}

int main() {
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> v = twoSum(nums, target);
    for (auto it: v) {
        cout << it << " ";
    }

    return 0;
}
