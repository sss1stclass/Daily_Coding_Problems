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
