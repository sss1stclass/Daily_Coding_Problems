#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data= data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next= nullptr;
    }
};

void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* sortList(Node* head) {
Node* temp = head;
vector<int>v;
while(temp!= nullptr){
    v.push_back(temp->data);
    temp=temp->next;
}
sort(v.begin(),v.end());
int i =0;
temp = head;
while(temp!= nullptr){
    temp->data = v[i];
    i++;
    temp= temp->next;
}
return head;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(9);
    head->next->next= new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);
    Node* newHead = sortList(head);
    print(newHead);

    return 0;
}