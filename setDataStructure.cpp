#include<bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(49);
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
    if (s.find(49) != s.end()) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    vector<int> v = {1, 2, 3, 4, 5, 6};
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        int pos = it - v.begin();
        cout << "found" << " " << pos << endl;
    } else {
        cout << "not found" << endl;
    }


//    set<int> s1 = {1, 2, 3};
//    set<int> s2 = {2, 3, 4};
//    set<int> unionSet;

// Insert all elements from both sets
//    unionSet.insert(s1.begin(), s1.end());
//    unionSet.insert(s2.begin(), s2.end());

    set<int> s1 = {1, 2, 3};
    set<int> s2 = {2, 3, 4};
    set<int> intersectionSet;

    for (int x: s1) {
        if (s2.find(x) == s2.end()) {
            intersectionSet.insert(x);
        }
    }

    for (auto i: intersectionSet) {
        cout << i << " ";
    }
    return 0;
}