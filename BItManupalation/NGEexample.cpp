#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector < int > nextGreaterElements(vector < int > & nums) {
        int n = nums.size();
        vector < int > nge(n, -1);
        stack < int > st;
        for (int i =  n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nge;
    }
};
void rotate(vector<int>&arr){
    vector<int>ans(arr.size(),-1);
    for(int i =0;i<arr.size();i++){
        ans[i]=arr[(i+1)%arr.size()];
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
}
void smallest(vector<int>&arr){
    int sNum=INT_MIN;
    int secondsm=INT_MIN;

    bool test = false;
    for(int i =0;i<arr.size();i++){
        if(arr[i]==arr[0]){
            test= true;

        }else{
            test=false;
            break;
        }
    }
    if(test){
        cout<< arr[0];
    }else{
        for(int i =0;i<arr.size();i++){
            if(arr[i]>sNum){
                sNum=arr[i];
            }
        }
        for(int i =0;i<arr.size();i++){
            if(arr[i]>secondsm && arr[i]!=sNum){
                secondsm=arr[i];
            }
        }
    }

    cout<<secondsm<<endl;
}

int trap(vector<int>& height) {
    int n = height.size();
    int prefixMax[n];
    int waterTrapped = 0;
    int sufixMax[n];
    prefixMax[0]=height[0];
    for(int i =1;i<n;i++){
        prefixMax[i] = max(height[i],prefixMax[i-1]);
    }
    sufixMax[n-1] = height[n-1];
    for(int i = n-2;i>=0;i--){
        sufixMax[i] = max(sufixMax[i+1],height[i]);
    }
    for(auto i : sufixMax){
        cout<<i<<" ";
    }cout<<endl;
    for(auto i : prefixMax){
        cout<<i<<" ";
    }
    for (int i = 0; i < n; i++) {
        waterTrapped += min(prefixMax[i], sufixMax[i]) - height[i];
    }
    return waterTrapped;
}
int findMin(vector<int>arr){
    if(arr.size()==1) return arr[0];
    int min = INT_MAX;
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int sumSubarrayMins(vector<int>& arr) {
    int findAns=0;
    int n = arr.size();
    for(int i =0;i<n;i++){
        vector<int>ans;
        for(int j=i;j<n;j++){
            cout<<arr[j]<<" ";
            ans.push_back(arr[j]);
        }
        cout<<endl;
        findAns+= findMin(ans);
    }
    return findAns;
}

vector<int>nextsmallerelement(vector<int>arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    for(int i =0;i<n;i++){
        for( int j = i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                ans[i]=arr[j];
               break;
            }
        }
    }
    return ans;
}
vector<int>nextsmaller(vector<int>& arr){
    int n = arr.size();
    vector<int>ans(n, -1);
    stack<int>st;
    for( int i =0; i<n;i++){
        while(!st.empty() && arr[i]<=st.top()){
            st.pop();
        }
        if(!st.empty()){
            ans[i]= st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

bool canJump(vector<int>& nums) {
    int jump = nums[1];
    int n = nums.size();
    int last = nums[n-1];
    if(nums[jump+1] == nums[last]){
        return true;
    }
    return false;
}
int main() {
    Solution obj;
    vector < int > v {2,3,1,1,4};
    vector < int > res = nextsmaller(v);
    for(auto i : res){
        cout<<i<<" ";
    }
//    cout<<sumSubarrayMins(v);
}


