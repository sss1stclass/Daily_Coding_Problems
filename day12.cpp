
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

//vector<vector<int>> threeSum(vector<int> &nums) {
//    int n = nums.size();
//    set<vector<int>> st;
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            for (int k = j + 1; k < n; k++) {
//                if (nums[i] + nums[j] + nums[k] == 0) {
//                    vector<int> temp = {nums[i], nums[j], nums[k]};
//                    sort(temp.begin(), temp.end());
//                    st.insert(temp);
//                }
//            }
//        }
//    }
//    vector<vector<int>> ans(st.begin(), st.end());
//    return ans;
//}

//vector<vector<int>> threeSum(vector<int> &nums) {
//    int n = nums.size();
//    set<vector<int>> st;
//    for (int i = 0; i < n; i++) {
//        set<int> hashMap;
//        for (int j = i + 1; j < n; j++) {
//            int k = -(nums[i] + nums[j]);
//            if (hashMap.find(k) != hashMap.end()) {
//                vector<int> temp = {nums[i], nums[j], k};
//                sort(temp.begin(), temp.end());
//                st.insert(temp);
//            }
//            hashMap.insert(nums[j]);
//        }
//    }
//    vector<vector<int>> ans(st.begin(), st.end());
//    return ans;
//}

//optimal soln

vector<vector<int>> threeSum(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

// four sum brute force sol.....

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    vector<int> nums = {2, 2, 2, 2, 2};
    int target = 8;
//    vector<int> v = twoSum(nums, target);
//    vector<vector<int>> v = threeSum(nums);
    vector<vector<int>> v = fourSum(nums, target);
    for (auto it: v) {
        for (auto x: it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
