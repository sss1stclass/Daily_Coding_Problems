//1. Reverse String
//- https://lnkd.in/dSYxrHkt
//2. Valid Palindrome
//- https://lnkd.in/dNTpQFit
//3. Longest Substring Without Repeating Characters
//- https://lnkd.in/dMYzuAY4
//4. Group Anagrams
//- https://lnkd.in/dZAMtWYM
//5. Longest Palindromic Substring
//- https://lnkd.in/dnk7bi7m
#include<bits/stdc++.h>
using namespace std;

vector<string> reverse(vector<string>& ch){
    int n = ch.size();
    for(int i =0;i<n/2;i++){
        swap(ch[i],ch[n-1-i]);
    }
    return ch;
}

bool checkPalindrome(string &s ){
    string ans = "";
    for(int i =0; i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] - 'A' + 'a';
            }
          ans+=s[i];
        }
    }
    for(int i =0;i<ans.length()/2;i++){
        if(ans[i]!=ans[ans.length()-1-i]){
            return false;
        }
    }
    return true;
}

int check(string s) {
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        vector<string> newAns;
        newAns.push_back(strs[i]);

        for (int j = i + 1; j < n; j++) {
            if (check(strs[i]) == check(strs[j])) {
                newAns.push_back(strs[j]);
                strs[j] = "";
            }
        }
        ans.push_back(newAns);
    }
    return ans;
}

//int longestOnes(vector<int>& nums, int k) {
//    int n = nums.size();
//    int maxLen = 0;
//    for( int i  =0;i<n;i++){
//        int zeros = 0;
//        for(int j =i;j<n;j++) {
//            if(nums[j]==0){
//                zeros++;
//            }
//            if(zeros<=k){
//                int length = j-i+1;
//                maxLen = max(length, maxLen);
//            }
//            else{
//                break;
//            }
//        }
//    }
//    return maxLen;
//
//}

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    int l = 0; int r = 0;
    int zeros = 0;
    while(r<n-1){
        if(nums[r]==0){
           zeros++;
        }
        if(zeros>k){
            if(nums[l] == 0 ){
                zeros--;
            }


            l++;
        }
        if(zeros<=k){
            maxLen= max(maxLen, r-l+1);
        }

        r++;
    }
    return maxLen;
}

int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int>mp;
    int maxlen = 0;
    int r = 0; int l = 0;
    while(r<n){
        mp[fruits[r]]++;
        while (mp.size() > 2) {
            if (mp[fruits[l]] == 0) {
                mp.erase(fruits[l]);
            }
            l++;
        }
        if(mp.size()<=2){
            maxlen= max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}

int characterReplacement(string s, int k) {
    int n = s.length();
    unordered_map<char, int> mp;
    int maxlen = 0;
    int r = 0;
    int l = 0;

    while (r < n) {
        mp[s[r]]++;
        while (mp.size() > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

string removeDigit(string number, char digit) {
    int n = number.length();
    string ans = "";
    int count =0;
    for(int i =0;i<n;i++){
        if(number[i]==digit){
            count++;
        }
    }

    cout<<count;
    return "as";
}

//int numSubarraysWithSum(vector<int>& nums, int goal) {
//    int counter =0;
//int n = nums.size();
//for(int i =0;i<n;i++){
//    int sum=0;
//    for(int j =i;j<n;j++){
//        sum+=nums[j];
//        if(sum==goal){
//            counter++;
//        }
//    }
//}
//return counter;
//}

int calculate(vector<int>& nums, int goal) {
    int counter =0;
    int n = nums.size();
    int sum = 0;
    int l =0; int r =0;
    while(r<n){
        sum+=nums[r];
        while(sum>goal){
            sum=sum-nums[l];
            l++;
        }
        if(sum<=goal){
            counter = counter+(r-l+1);
        }
       r++;
    }
    return counter;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {

    int sum = calculate(nums, goal) - calculate(nums, goal-1);
    return sum;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int count=0;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum +=nums[j];
            int len = j-i;
            if((len==k) && (sum%2!=0)){
                count++;
            }
        }
    }
    return count;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    unordered_map<int, deque<int>> diagonals;
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            diagonals[i + j].push_front(mat[i][j]);
        }
    }

    vector<int> result;
    for (auto& diagonal : diagonals) {
        while (!diagonal.second.empty()) {
            result.push_back(diagonal.second.front());
            diagonal.second.pop_front();
        }
    }

    return result;
}

int numberOfSubstrings(string s) {
 int n = s.length();
 int counter =0;
 for(int i =0;i<n;i++){
     char hash[3] = {0};
     for(int j =i;j<n;j++){
         hash[s[j]-'a']=1;
         if(hash[0]+hash[1]+hash[2]==3){
            counter++;
         }
     }
 }
 return counter;
}

bool setcheck(vector<int>&v,int k){
    set<int>s;
    s.insert(v.begin(),v.end());
    if(s.size()==k){
        return true;
    }
    return false;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
  int n = nums.size();
  int counter = 0;
  for(int i =0;i<n;i++){
      for(int j = i;j<n;j++){
          vector<int>temp;
          for(int k =i;k<=j;k++){
             temp.push_back(nums[k]);
          }
          if(setcheck(temp, k)){
              counter++;
          }
      }
  }
  return counter;
}



int main (){
   vector<int>s = {1,2,1,3,4};
 cout<<subarraysWithKDistinct(s,3)<<endl;

    return 0;
}