#include<bits/stdc++.h>
using namespace std;

int main (){
int  n, arr[20];
cout << "Enter the no. of Elelments"<<endl;
cin>>n;
cout<<"Enter the numbers of Elements"<<endl;
for(int i = 0; i<n ; i++){
    cin>>arr[i];
}
cout<<"The numbers of elements are "<<endl;
    cout<<"[";
for(int i=0; i<n;i++){
    cout<<arr[i]<<" ";
}
    cout<<"]";
return 0;
}
