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

int main(){
    vector<int> arr = {2,3,5,1,8,6};
    Node* head = convertArrayToDLL(arr);
    cout<<countTheList(head,15)<<endl;
    print(head);

    return 0;
}