#include<bits/stdc++.h>
using namespace std;

int main () {
   vector<int>v;
   v.push_back(10);
   v.push_back(10);
//   v.push_back(45);
//   v.push_back(90);
//   v.push_back(31);

   for(int i : v ) cout<< i<< " ";
   cout << endl;
   sort(v.begin(),v.end());
   cout<<v.size()<<endl;
   cout<<v.at(v.size()-2);
   return 0;

}

//int getSecondLargest(vector<int> &arr) {
//    // Code Here
//    set<int> uniqueElements(arr.begin(), arr.end());
//
//    // If there are less than two unique elements, return -1
//    if (uniqueElements.size() < 2) return -1;
//
//    // Convert set to vector and sort
//    vector<int> uniqueVec(uniqueElements.begin(), uniqueElements.end());
//    sort(uniqueVec.begin(), uniqueVec.end());
//
//    // Return the second last element (second largest)
//    return uniqueVec.at(uniqueVec.size() - 2);
