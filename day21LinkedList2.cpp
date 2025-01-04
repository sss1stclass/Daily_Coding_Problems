#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data=data1;
        next= next1;
    }
    Node (int data1){
        data=data1;
        next= nullptr;
    }
};

Node* merge(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}
void print (Node* head){
    Node* temp = head;
    while (temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
Node* deleteHead(Node* head){
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}

Node *insertAtEnd(Node *head, int x) {
    // Code here
    Node* newNode = new Node(x);
    if(head== NULL){
        return  newNode;
    };
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

Node* insertAtFront(Node* head, int x){
    return new Node(x, head);
}

int main(){
    vector<int> arr = { 1,4,7,2,9};
    Node* head = merge(arr);
//    head = deleteHead(head);
//      head = insertAtEnd(NULL, 340);
       head = insertAtFront(head, 100);
    print(head);

    return 0;
}
