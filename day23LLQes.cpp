#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
public:
    Node(int data1, Node* next1, Node* prev1){
        data= data1;
        next=next1;
        prev= prev1;
    }
    Node(int data1){
        data = data1;
        next= nullptr;
        prev= nullptr;
    }
};

void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
}

Node* reverseDLL(Node* head){
    Node* temp = head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp= head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
  return head;
}

Node* middleNode(Node* head) {
    Node* temp = head;
    int length =0;
    while(temp!=NULL){
        length++;
        temp= temp->next;
    }
    Node* newNode;
    temp= head;
    int count = 0;
    while(temp!=NULL){
        count++;
      if(length/2 == count){
         newNode = temp->next;
         temp->next = newNode->next;
         newNode->next = nullptr;
         delete(newNode);
      }
      temp= temp->next;
    }
    return head;
}

int main (){
    Node* head = new Node(1);
    Node* node2 = new Node(3,NULL, head);
    head->next=node2;
    Node* node3 = new Node(9,NULL, node2);
    node2->next = node3;
    Node* node4 = new Node(5,NULL, node3);
    node3->next=node4;
    Node* node5 = new Node(2,NULL, node4);
    node4->next = node5;
    Node* newHead = middleNode(head);
    print(newHead);
    return 0;

}