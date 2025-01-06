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

Node* convertArrayToDLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for( int i =1; i<arr.size();i++){
        Node* newNode = new Node(arr[i], NULL, temp);
        temp->next = newNode;
        temp=newNode;
    }
    return head;
}
int countTheList(Node* head, int k){
   Node* temp = head;
   int count = 0;
   while(temp!= nullptr){
       count++;
       if(temp->data == k){
           return 1;
       }
       temp= temp->next;
   }
//   return count;
     return 0;
}

Node* insertionAtHead(Node* head, int val){
   Node* newNode = new Node(val, head, nullptr);
   head = newNode;
   return head;
}
Node* insertAtEnd(Node* head, int val){
    Node* temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val,NULL, temp->next);
    temp->next=newNode;
    return  head;

}

Node *addNode(Node *head, int pos, int data) {
    // code here
//    if(pos==0){
//        Node* newNode = new Node(data, head, nullptr);
//        head = newNode;
//        return head;
//    }
    Node* temp = head;
    int count = -1;
    while(temp->next!= nullptr){
        count++;
        cout<<count<<" ";
        if(count==pos){
            Node* newNode = new Node(data,temp->next,temp);
            temp->next = newNode;
            temp->next->back = newNode;
            break;
        }
        temp= temp->next;
    }
    return head;

}


int main(){
    vector<int> arr = {2,3,5,1,8};
    Node* head = convertArrayToDLL(arr);
    head = addNode(head, 4,6);
    cout<<endl;
//    cout<<countTheList(head,15)<<endl;
    print(head);

    return 0;
}