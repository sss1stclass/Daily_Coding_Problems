#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr, int number) {
    for (int i = 0; i < number - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int rotatedArray(vector<int> &arr, int number, int k){
    vector<int>temp(arr.size());
    for(int i =0 ;i<number;i++){
        temp[(i+k)%number] = arr[i];
    }
    for(auto i : temp){
        cout<<i<<" ";
    }cout<<endl;
}


int stock(vector<int>& arr){
    int n = arr.size();
    int maxSum =0;
    int mini = INT_MAX;
    for(int i =0;i<n;i++){
        mini = min(mini, arr[i]);
        maxSum = max(maxSum, arr[i]-mini);
    }
    return  maxSum;
}


int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int current_area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, current_area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
int main() {
    int arr[] = {1, 4, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    int number = v.size();

//    if (isSorted(v, number)) {
//        cout << "The array is sorted." << endl;
//    } else {
//        cout << "The array is not sorted." << endl;
//    }
    rotatedArray(v, number, 2);

    return 0;
}
