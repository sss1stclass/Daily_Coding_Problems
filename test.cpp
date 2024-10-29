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