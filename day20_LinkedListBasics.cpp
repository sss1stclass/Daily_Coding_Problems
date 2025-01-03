#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next=next1;
    }
public:
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

Node* convertArrtoll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =0;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}

int main (){
vector<int>arr= {2,5,4,6};
Node* y = new Node(arr[0]);
Node* head = convertArrtoll(arr);
cout<<head->data<<endl;
cout<<y->data;
    return 0;
}
