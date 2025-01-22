
#include<bits/stdc++.h>
using namespace std;
string reverse(string st){
    string nst="";
    for(int i=0;i<st.length()/2;i++){
        swap(st[i],st[st.length()-i-1]);
    }
//    for(int i=st.length()-1;i>=0;i--){
//        nst.push_back(st[i]);
//    }
    return st;
}

void onesCompliment(string st){
    string newst = "";
    for(int i =0;i<st.length();i++){
        if(st[i]=='0'){
            newst.push_back('1');
        }else{
            newst.push_back('0');
        }
    }
    cout<<newst;
}

void decimalToBinary(int num){
    string st = "";
    while(num>=1){
       if(num%2==1){
           st.push_back('1');
       }else{
           st.push_back('0');
       }
        num=num/2;
    }
    cout<<reverse(st)<<endl;

}

vector<int> toCheckOddEven(vector<int>&arr){
    vector<int>ans;
    for(int i =0;i<arr.size();i++){
        if((arr[i] & 1) != 1){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
void swap2NumberWithout3rdVar(int a, int b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b<<endl;
}



int main(){
    int num = 81;
    decimalToBinary(num);
    int num2 = 23;
    swap2NumberWithout3rdVar(num,num2);
    vector<int>arr={2,3,4,5,6,7,8};
//    toCheckOddEven(arr);
    for(auto i : toCheckOddEven(arr)){
        cout<<i<<" ";
    }


    return 0;
}