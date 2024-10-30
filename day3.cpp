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

int main() {
    int arr[] = {1, 4, 6, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    int number = v.size();

    int sort = is_sorted(v.begin(), v.end());
    cout<<sort<<endl;

    if (isSorted(v, number)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
