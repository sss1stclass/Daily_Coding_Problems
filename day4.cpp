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

int sum(int l){
    int ans =0;
    if(l<10) return l;
    while(l>0){
        int val = l%10;
        ans += val;
        l = l/10;
    }
    return ans;
}
int prod(int l){
    int ans =1;
    if(l<10) return l;
    while(l>0){
        int val = l%10;
        ans *= val;
        l = l/10;
    }
    return ans;
}
int beautifulNumbers(int l, int r) {
    int ans = 0;
    for(int i = l; i<=r;i++){
        int s = sum(i);
        int p = prod(i);
        if(p%s==0){
            ans++;
        }
    }
    return ans;
}

bool divideArray(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>mp;
    for(int i =0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto i : mp){
       if(i.second%2!=0){
           return false;
       }
    }
   return true;
}

int main(){
   vector<int>v = {3,2,3,2,2,2,1};
////    set<int>s(v.begin(),v.end());
////    v.assign(s.begin(), s.end());
////    cout<< v.size();
//   cout<< checkUniqueElement(v);
//cout<<prod(11124);
cout<<divideArray(v);

    return 0;
}
