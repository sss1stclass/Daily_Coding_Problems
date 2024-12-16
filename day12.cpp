
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

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;
//    vector<int> v = twoSum(nums, target);
    vector<vector<int>> v = threeSum(nums);
    for (auto it: v) {
        for (auto x: it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
