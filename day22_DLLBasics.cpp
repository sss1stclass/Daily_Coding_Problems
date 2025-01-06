#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

public:
   Node(int data1, Node* next1, Node* back1){
        data= data1;
        next= next1;
        back= back1;
    }
    Node(int data1){
       data=data1;
       next= nullptr;
       back= nullptr;
   }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
}

int main(){
    Node* newNode = new Node(2);
    Node* node2= new Node(3, nullptr, newNode);
    newNode->next= node2;
    Node* node3 = new Node(4, nullptr,node2);
    node2->next= node3;
    print(newNode);

    return 0;
}