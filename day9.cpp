#include<bits/stdc++.h>

using namespace std;


int singleNumber(vector<int> &nums) {

    if (nums.size() == 1) return nums[0];
    for (int i = 0; i < nums.size(); i++) {
        int number = nums[i];
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == number) {
                count++;
            }
        }
        if (count < 2) {
            return number;
        }
    }


}

int main() {
    vector<int> nums = {4, 4, 1, 5, 1, 3, 3};
    cout << singleNumber(nums);

    return 0;
}
