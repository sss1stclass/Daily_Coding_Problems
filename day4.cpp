#include<bits/stdc++.h>
using namespace std;

int checkUniqueElement(vector<int> &nums){
    int count = 0;
    for(int i =0; i<nums.size(); i++){
        if(nums[i]==nums[i+1]){
            count++;
        }
    }
    int elm = nums.size() - count;
    return  elm;
}

int main(){
   vector<int>v = {1, 1, 2,4,5,6,6,7,7};
//    set<int>s(v.begin(),v.end());
//    v.assign(s.begin(), s.end());
//    cout<< v.size();
   cout<< checkUniqueElement(v);

    return 0;
}
