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

int findSQRT(int n, int m) {
    int low = 1;
    int high = n;
    int ans = 1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (pow(mid, n) > m) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int mult(int ini, int n) {
    int ans = ini;
    for (int i = 1; i < n; i++) {
        ans = ans * ini;
    }
    return ans;
}

int nthRoot(int n, int m) {  //brute force
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        if (mult(i, n) == m) {
            ans = i;
            break;
        } else {
            ans = -1;
        }
    }
    return ans;
}

int nthRoot(int n, int m) { //optimal
    int low = 1;
    int high = m;
    int ans = 1;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (pow(mid, n) == m) return mid;
        if (pow(mid, n) > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}


int main() {
    int n = 3;
    int m = 27;
//    cout << pow(2, 4) << endl;
//    cout << nthRoot(n, m);
    cout << findSQRT(n, m);
    return 0;
}
