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
    int sum = INT_MAX;
    for (int i = 0; i < n; i++) {
        sum = min(sum, prices[i]);
        maxlen = max(maxlen, prices[i] - sum);
    }
    return maxlen;
}

vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            pos.push_back(nums[i]);
        } else {
            neg.push_back(nums[i]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        temp.push_back(pos[i]);
        temp.push_back(neg[i]);
    }
    nums = temp;

    return nums;
}

void nextPermutation(vector<int> &nums) {

    next_permutation(nums.begin(), nums.end());

}

int main() {
    vector<int> nums = {1, 2, 5, 4, 3, 0, 0};
//    cout << maxSubArray(nums);
//    cout << maxProfit(nums);
//    rearrangeArray(nums);
    nextPermutation(nums);
    for (auto i: nums) {
        cout << i << " ";
    }

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
