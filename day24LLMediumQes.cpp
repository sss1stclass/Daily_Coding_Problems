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

Node* mergeTwoLists(Node* list1, Node* list2) {
    if(list1==NULL && list2 == NULL){
        return NULL;
    }


    Node* temp = list1;
    vector<int>v;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    temp=list2;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    Node* newHead = new Node(v[0]);
    Node* newTemp = newHead;
    for(int i =1;i<v.size();i++){
        Node* newNode = new Node(v[i]);
        newTemp ->next = newNode;
        newTemp=newNode;
    }
    return newHead;

}

int main(){
    Node* head = new Node(2);
    head->next = new Node(9);
    head->next->next= new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);

    Node* head2 = new Node(2);
    head2->next = new Node(8);
    head2->next->next= new Node(1);
    head2->next->next->next = new Node(0);
    head2->next->next->next->next = new Node(5);

    Node* newHead = mergeTwoLists(head,head2);
    print(newHead);

    return 0;
}