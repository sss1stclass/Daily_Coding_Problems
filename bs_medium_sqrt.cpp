#include<bits/stdc++.h>

using namespace std;

//int findSQRT(int n) {
//    int ans = 1;
//    for (int i = 0; i <= n; i++) {
//        if (i * i <= n) {
//            ans = i;
//        }
//    }
//    return ans;
//}

int findSQRT(int n) {
    int low = 1;
    int high = n;
    int ans = 1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (mid * mid > n) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int num = 5;
    cout << findSQRT(num);
    return 0;
}
