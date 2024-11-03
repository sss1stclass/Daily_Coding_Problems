#include<bits/stdc++.h>
using namespace std;

int moveZeros(vector<int> &v){
    vector<int>nonZeros;
    vector<int>zeros;
    for(int i =0 ; i<v.size();i++){
        if(v[i]!=0){
            nonZeros.push_back(v[i]);
        }else{
            zeros.push_back(v[i]);
        }
    }
    sort(nonZeros.begin(),nonZeros.end());
    nonZeros.insert(nonZeros.end(),zeros.begin(),zeros.end());
    v=nonZeros;
}

int main (){
    vector<int>v = {0,1,0,3,12};
    moveZeros(v);
    for(auto i : v){
        cout<<i<<" ";
    }
    return 0;
}