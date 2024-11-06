#include<bits/stdc++.h>
using namespace  std;


    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        a.insert(a.end(),b.begin(),b.end());
        set<int>final(a.begin(),a.end());
        vector<int>val(final.begin(),final.end());
        return val;
    }


int main(){
   vector<int>v={1,22,3,4,5,5,5,6};
   vector<int>b = {1,2,44,55,9};
   int k = 5;
//    bool check = binary_search(v.begin(),v.end(),k);
//    auto it = lower_bound(v.begin(),v.end(),k);
//    cout<<it - v.begin()<<" The element is present at this index"<<endl;
    vector<int> ki = findUnion(v,b);
    for(auto i : ki){
        cout<<i<<" ";
    }


    return 0;
}
