#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int l =0; int r = 0;
    while(l<m){
        if(g[r]<=s[l]){
            r++;
        }
        l++;
    }
    return r;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int totalValWt = 0;
    int totalVal = 0;
    double ans=0;
    for(auto i : wt){
        totalValWt+=i;
    }
    for(auto i : val){
        totalVal+=i;
    }
    if(capacity>=totalValWt) return totalVal;
    double tempwt = 0;
    for(int i =0;i<wt.size();i++){
        tempwt+=wt[i];
        if(tempwt<=capacity){
            ans+=val[i];
        }
        if(tempwt>capacity){
            double extraWt = tempwt - capacity;
            if(tempwt-extraWt<=capacity){
                ans+=(val[i]/wt[i])*(wt[i]-extraWt);
            }
            break;
        }
    }
    return ans;

}

bool lemonadeChange(vector<int>& bills) {
       int five =0;
       int ten = 0;
       for(int i =0;i<bills.size();i++){
           if(bills[i]==5){
               five++;
           }else if(bills[i]==10){
               if(five){
                   five--;
                   ten++;
               } else{
                   return false;
               }
           }else{
               if(ten && five){
                   ten--;
                   five--;
               }else if(five>3){
                   five-=3;
               }
               else{
                   break;
               }
           }
       }
       return true;
}


bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxlen = 0;
    for(int i =0;i<n;i++){
        if(i>maxlen) return false;
        maxlen= max(maxlen, i+nums[i]);
        cout<<maxlen<<i<<nums[i]<<endl;
    }
    return true;
}

bool hasSameDigits(string s) {
    string temp = s;
    for(int i=0;i<s.length()-1;i++){
        string ans="";
        for(int j =0;j<temp.length()-1;j++){
            int num =(temp[j]-'0' + temp[j+1]-'0') % 10;
            ans+= to_string(num);
        }
        if(ans.length()==2){
           if(ans[0]!=ans[1]){
               return false;
           }else{
               return true;
           }
        }
        temp = ans;
    }
return true;
}

int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int>mp;
    int l=0;int r=0;
    int count=INT_MAX;
    while(r<cards.size()){
        mp[cards[r]]++;

        while (mp[cards[r]] == 2) {
            count = min(count, r - l + 1);
            mp[cards[l]]--;
            l++;
        }
        r++;
    }
    return count==INT_MAX?-1:count;
}

int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int counter = 0;
    int odd_count = 0, even_count = 1;
    int prefix_sum = 0;

    for (int num : arr) {
        prefix_sum += num;

        if (prefix_sum % 2 == 0) {
            counter = (counter + odd_count) % MOD;
            even_count++;
        } else {
            counter = (counter + even_count) % MOD;
            odd_count++;
        }
    }

    return counter;
}

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int l = 0, r = 0;
        int count = 0;
        int minCount = INT_MAX;

        while (r < n) {
            if (blocks[r] == 'W') {
                count++;
            }

            if (r - l + 1 == k) {
                minCount = min(minCount, count);

                if (blocks[l] == 'W') {
                    count--;
                }

                l++;
            }

            r++;
        }

        return minCount;
    }
};


int main(){
    vector<int>bills={1,3,5};
    string s = "3902";
    cout<<numOfSubarrays(bills);
    return 0;
}