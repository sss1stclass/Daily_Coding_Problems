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

bool fun(int i , int j){
    return i<j;
}

vector<int>twoSum(vector<int>&arr){
    int n = arr.size();
    unordered_map<int,int>mp;
    for(int i =0;i<n;i++){
        int start = arr[i];
        int diff = 13-start;
        if(mp.find(diff)!=mp.end()){
            return {mp[diff],i};
        }
        mp[start]=i;
    }
    return {-1,-1};
}

//vector<int>start={1, 3, 0, 9, 8, 5};
//vector<int>end={2, 4, 6, 7, 9, 9};
//vector<int>ans = twoSum(start);
//for(auto i : ans){
//cout<<i<<" ";
//}cout<<endl;
//vector<pair<int, int>>meetings;
//for(int i =0;i<start.size();i++){
//meetings.push_back({start[i],end[i]});
//}
//sort(meetings.begin(), meetings.end(), [](pair<int, int>& a, pair<int, int>& b) {
//return a.second < b.second;
//});
//int count=0;
//int last_time = -1;
//for(int i =0;i<start.size();i++){
//if(meetings[i].first>last_time){
//count++;
//last_time=meetings[i].second;
//}
//}
//cout<<count;
//for(auto i : meetings){
//cout<<(i.first)<<" "<<i.second<<"---";
//}

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next= nullptr;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;

}
Node* reverse(Node* head){
    Node* temp = head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!= NULL){
      temp->data = st.top();
      st.pop();
      temp= temp->next;
    }
    return temp;
}


int main(){

    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    node1->next = node2;
    Node* node3 = new Node(9);
    node2->next = node3;
    Node* node4  = new Node(4);
    node3->next = node4;
    Node* node5 = new  Node(5);
    node4->next = node5;
    print(node1);
    reverse(node1);
    print(node1);





    return 0;
}