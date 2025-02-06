#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& arr) {

}

vector<int> asteroidCollision(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            st.push(arr[i]);
        } else {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0) {
                if (st.top() < -arr[i]) {
                    st.pop();
                } else if (st.top() == -arr[i]) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(arr[i]);
            }
        }
    }

    while (!st.empty()) {
        ans.insert(ans.begin(),st.top());
        st.pop();
    }

//    reverse(ans.begin(), ans.end());

    return ans;
}

string removeKdigits(string num, int k) {
    int n = num.length()+1;
    string ans = "";
    stack<char>st;
    for(int i =0;i<n;i++){
        while (!st.empty() && k>0 && (st.top()-'0' > num[i]-'0')){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(k==n){
        return "0";
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
   while(ans.length() !=0 && ans.back()=='0'){
       ans.pop_back();
   }
   reverse(ans.begin(),ans.end());

   return ans.empty() ? "0" : ans;
}
int main(){
    string num = "1432219"; int  k = 3;
    cout<<removeKdigits(num, k)<<endl;
    vector<int>v = {5,10,-5};
    vector<int>ans  = asteroidCollision(v);
    for(auto  i : ans){
        cout<<i<<" ";
    }

    return 0;
}