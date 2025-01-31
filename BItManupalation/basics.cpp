
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
int findOddNumber(vector<int>&arr){
    unordered_map<int , int>hasmap;
    for(int i =0;i<arr.size();i++){
        hasmap[arr[i]]+=1;
    }
    for(auto i : hasmap){
        if(i.second == 1){
            return i.first;
        }
    }
    cout<<endl;
    return -1;
}

int countSetBits(int n)
{
    int mostCount = 0;

    // Iterate over all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        int count = 0;

        // Count set bits in the current number
        while (i > 0) {
            count += i & 1;   // Add 1 if the least significant bit is set
            i >>= 1;           // Right shift to check the next bit
        }

        // Add the number of set bits for the current number to the total
        mostCount += count;
    }

    return mostCount;
}





int main(){
    int num = 81;
    decimalToBinary(num);
    int num2 = 23;
    swap2NumberWithout3rdVar(num,num2);
    vector<int>arr={2,2,4,3,3,4,5};
    cout<<countSetBits(7);



    return 0;
}