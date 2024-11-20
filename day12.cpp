
#include<bits/stdc++.h>

using namespace std;

//vector<int> twoSum(vector<int> &nums, int target) {
//    vector<int> temp;
//    int n = nums.size();
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (nums[i] + nums[j] == target) {
//                temp.push_back(i);
//                temp.push_back(j);
//                break;
//            }
//        }
//    }
//    nums = temp;
//    return nums;
//}

//using map

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int number = nums[i];
        int diff = target - number;
        if (map.find(diff) != map.end()) {
            return {map[diff], i};
        }
        map[number] = i;
    }
}

int main() {
    vector<int> nums = {1, 6, 1, 1, 4, 2, 3};
    int target = 6;
    vector<int> v = twoSum(nums, target);
    for (auto it: v) {
        cout << it << " ";
    }

    return 0;
}
