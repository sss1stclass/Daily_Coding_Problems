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
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}
int checkVal(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        temp=temp->next;
        count++;
    }
    return  count;
}

int main (){
vector<int>arr= {2,5,4,6};
Node* y = new Node(arr[0]);
Node* head = convertArrtoll(arr);
//cout<<head->data<<endl;
cout<<lengthLL(head)<<"length"<<endl;
cout<<y<<endl;
Node* temp = head;
cout<<checkVal(head, 15)<<endl;
while(temp){
    cout<<temp->data<<" ";
    temp= temp->next;
}
    return 0;
}
