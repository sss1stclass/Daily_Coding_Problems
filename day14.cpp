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

int maxProfit(vector<int> &prices) {

    int n = prices.size();
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum = prices[j] - prices[i];
            maxlen = max(sum, maxlen);
        }
    }
    return maxlen;
}

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};
//    cout << maxSubArray(nums);
    cout << maxProfit(nums);
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
