#include<bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] && nums[i + 1] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
    return 0;

}
