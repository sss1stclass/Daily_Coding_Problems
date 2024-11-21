#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums) {
//    vector<int> zero;
//    vector<int> one;
//    vector<int> two;
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[i] == 0) {
//            zero.push_back(nums[i]);
//        } else if (nums[i] == 1) {
//            one.push_back(nums[i]);
//        } else {
//            two.push_back(nums[i]);
//        }
//    }
//    zero.insert(zero.end(), one.begin(), one.end());
//    zero.insert(zero.end(), two.begin(), two.end());
//    nums = zero;

    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid < high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        } else {
            mid++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto i: nums) {
        cout << i << " ";
    }
    return 0;
}
