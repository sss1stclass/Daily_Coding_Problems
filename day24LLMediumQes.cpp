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
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
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
int reverseNUmber(int num){
    int result =0;
    while(num>0){
       int add = num%10;
       result= result*10+add;
       num=num/10;

    }
    return result;
}


Node* addTwoNumbers(Node* l1, Node* l2) {
    int result1=0;
    while(l1!=NULL){
        result1 = result1*10+l1->data;
        l1=l1->next;
    }
    int result2=0;
    while(l2!=NULL){
        result2 = result2*10+l2->data;
        l2=l2->next;
    }
    int newResult = reverseNUmber(result2)+ reverseNUmber(result1);
    vector<int>v;
    while(newResult>0){
        v.push_back(newResult%10);
        newResult=newResult/10;
    }
    Node* newHead = new Node(v[0]);
    Node* temp = newHead;
    for(int i = 1;i<v.size();i++){
        Node* newNode = new Node(v[i]);
        temp->next = newNode;
        temp =newNode;
    }
    return newHead;

}

Node* addTwoNumbers2(Node* l1, Node* l2){
    Node* dummyNode= new Node(-1);
    Node* curr = dummyNode;
    int carry=0;
    while(l1!=NULL || l2!=NULL){
        int sum = carry;
        if(l1) sum +=l1->data;
        if(l2) sum +=l2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;

    }
    if(carry){
        Node* newNodeCarry = new Node(carry);
        curr->next = newNodeCarry;
    }
    return dummyNode->next;

}
Node* reverseLLOptimal(Node* head) {
    Node* temp= head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}


int main(){
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next= new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next= new Node(4);
//    head2->next->next->next = new Node(0);
//    head2->next->next->next->next = new Node(5);

    Node* newHead = reverseLLOptimal(head);
    print(newHead);


    return 0;
}