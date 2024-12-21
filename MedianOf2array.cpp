#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    int n = nums1.size();
    if (n % 2 != 0) {
        return nums1[n / 2];
    } else {
        double sum = 0;
        int low = 0;
        int high = n - 1;
        int mid = (low + high) / 2;
        sum = nums1[mid] + nums1[mid + 1];
        return sum / 2;
    }
    return -1;
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double asn = findMedianSortedArrays(nums1, nums2);
    cout << asn << endl;
    return 0;
}