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

int countPages(vector<int> arr, int pages) {
    int students = 1;
    long long studentPages = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + studentPages <= pages) {
            studentPages += arr[i];
        } else {
            students += 1;
            studentPages = arr[i];
        }
    }
    return students;

}

int findPages(vector<int> &arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (high >= low) {
        int mid = (high + low) / 2;
        int pages = countPages(arr, mid);
        if (pages > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums1 = {12, 34, 67, 90};
//    vector<int> nums2 = {3, 4};
    int n = nums1.size();
    int m = 2;
    int asn = findPages(nums1, n, m);
    cout << asn << endl;
    return 0;
}