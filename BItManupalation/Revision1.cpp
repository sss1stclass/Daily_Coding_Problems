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






int main (){
   vector<string>s = {"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(s);
//cout<<check("eat");
    return 0;
}