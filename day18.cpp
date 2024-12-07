#include<bits/stdc++.h>

using namespace std;

//int search(vector<int> &nums, int target) {
//    int n = nums.size();
//    int high = n - 1;
//    int low = 0;
//
//    while (low <= high) {
//        int mid = (high + low) / 2;
//        if (nums[mid] == target) {
//            return mid;
//        } else if (nums[mid] >= target) {
//            high = mid - 1;
//        } else {
//            low = mid + 1;
//        }
//    }
//    return -1;
//}
//
//vector<int> searchRange(vector<int> &nums, int target) {
//    int n = nums.size();
//    int high = n - 1;
//    int low = 0;
//    int ans = n;
//    int last = n;
//    vector<int> temp = {};
//    vector<int> nest = {-1, -1};
//    int val = search(nums, target);
//    if (val != -1) {
//        while (low <= high) {
//            int mid = (high + low) / 2;
//            if (nums[mid] >= target) {
//                ans = mid;
//                last = mid + 1;
//                high = mid - 1;
//            } else {
//                low = mid + 1;
//            }
//        }
//        temp.push_back(ans);
//        temp.push_back(last);
//        nums = temp;
//        return nums;
//    } else {
//        nums = nest;
//        return nums;
//    }
//
//}

//approach 2

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int lb = lowerBound(nums, n, target);
    if (lb == n || nums[lb] != target) {
        return {-1, -1};
    }
    return {lb, upperBound(nums, n, target) - 1};

}

int countFreq(vector<int> &arr, int target) {
    // code here
    int n = arr.size();
    int lb = lowerBound(arr, n, target);
    if (lb == n || arr[lb] != target) {
        return 0;
    }
    int ans = (upperBound(arr, n, target) - 1) - lb + 1;
    return ans;
}


int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 8, 8, 8, 10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    for (auto it: ans) {
        cout << it << " ";
    }
    cout << endl;
    cout << countFreq(nums, target);

    return 0;
}
