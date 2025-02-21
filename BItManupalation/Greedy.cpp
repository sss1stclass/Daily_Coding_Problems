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
int main(){
    vector<int>bills={3,2,1,0,4};
    cout<<canJump(bills);
    return 0;
}