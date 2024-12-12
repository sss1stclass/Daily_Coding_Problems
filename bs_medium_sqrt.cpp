#include<bits/stdc++.h>

using namespace std;

int findSQRT(int n) {
    int ans = 1;
    for (int i = 0; i <= n; i++) {
        if (i * i <= n) {
            ans = i;
        }
    }
    return ans;
}

int main() {
    int num = 28;
    cout << findSQRT(num);
    return 0;
}
