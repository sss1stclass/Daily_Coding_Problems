#include<bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &nums) {
    int n = nums.size();
    int hashh[100] = {0};
    for (int i = 0; i < n; i++) {
        hashh[nums[i]] += 1;
    }
    for (int i = 0; i < 100; i++) {
        if (hashh[i] > n / 2) {
            return i;
        }
    }
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
    return 0;
}
