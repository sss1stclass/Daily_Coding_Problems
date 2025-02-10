#include<bits/stdc++.h>
using namespace std;

int maximumSubArrayLength(vector<int>& arr, int k){
    int n = arr.size();
    int l=0; int r =0; int maxSum =0;int sum =0;
    while(n>r){
        sum += arr[r];
        while(k<sum){
          sum -=arr[l];
          l++;
        }
        maxSum= max(r-l+1,maxSum);
        r++;
    }
    return maxSum;
}

int lengthOfLongestSubstring(string s) {
int n = s.length();
int maxsum =0;
    for (int i = 0; i < n; ++i) {
        int hash[256] ={0};
       for(int j = i;j<n;j++){
           if(hash[s[j]]==1) break;
           maxsum=max(maxsum, j-i+1);
           hash[s[j]]=1;
       }
    }
    return maxsum;
}

int main(){
//
//    vector<int>arr={1,2,5,1,7,8,10};
//    int size = 10;
//    cout<<maximumSubArrayLength(arr,size);
string  s = "abcabcbb";
cout<<lengthOfLongestSubstring(s);

    return 0;
}