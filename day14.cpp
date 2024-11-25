#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int maxi = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            cout << nums[i] << "," << nums[j] << endl;
            sum += nums[j];
            cout << sum << endl;
            maxi = max(sum, maxi);
        }
    }
    return maxi;

}

int main() {
    vector<int> nums = {4, -1, 2, 1, -2, 1, -3, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}
