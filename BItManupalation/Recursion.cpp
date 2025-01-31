#include<bits/stdc++.h>
using namespace std;

int factorial(int num){
    vector<int>ans;
    if(num==0){
        return 1;
    };
    int fact = num * factorial(num-1);
    if(fact<=num){
        ans.push_back(num);
    }
    for(auto i : ans){
        cout<<i<<" ";
    }
    return fact;
}


int sumOfSeries(int n) {
    // code here
    if(n==0) return 0;
    int sum = n+sumOfSeries(n-1);
    return sum;
}

void reverseArray2(vector<int> &arr,int i){
    if(i>=arr.size()){
        return;
    }
    reverseArray2(arr,i+1);
    cout<<arr[i]<<" ";

}

void reverseArray(vector<int> &arr) {
    // code here
    int i =0;
    reverseArray2(arr,i);

}

int main(){
//    cout<<sumOfSeries(5)<<endl;
    vector<int>arr={1,22,3,41,5,6,7};
    reverseArray(arr);
    return 0;
}