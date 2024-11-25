#include<bits/stdc++.h>

using namespace std;

//int maxSubArray(vector<int> &nums) {
//    int maxi = INT_MIN;
//    int n = nums.size();
//    for (int i = 0; i < n; i++) {
//        int sum = 0;
//        for (int j = i; j < n; j++) {
//            cout << nums[i] << "," << nums[j] << endl;
//            sum += nums[j];
//            cout << sum << endl;
//            maxi = max(sum, maxi);
//        }
//    }
//    return maxi;
//
//}

int maxSubArray(vector<int> &nums) {
    int maxi = INT_MIN;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum < 0) {
            sum = 0;
        }
        if (sum > maxi) {
            maxi = sum;
        }
    }
    return maxi;

}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}

//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int res = nums[0];
//        int total = 0;
//
//        for (int n : nums) {
//            if (total < 0) {
//                total = 0;
//            }
//
//            total += n;
//            res = max(res, total);
//        }
//
//        return res;
//    }
//};
