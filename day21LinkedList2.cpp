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

Node* deleteTail(Node* head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp= temp->next;
    }
    delete temp->next;
    temp->next= NULL;
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

Node* insertAtSpecificPosition(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
    }
    if(k==1){
        return  new Node(val, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        if(count == k-1){
            Node* newNode = new Node(val, temp->next);
            temp->next= newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

Node* insertAtVal(Node* head, int val, int num){
    if(head==NULL){
        return NULL;
    }
    if(head->data == num){
        return  new Node(val, head);
    }
    Node* temp = head;
    while(temp->next!= NULL){
        if(temp->next->data == num){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp= temp->next;
    }
    return head;
}

Node* deleteAtPos(Node* head, int val){
    Node* temp = head;
    int counter = 0;
    Node* prev = NULL;
    while(temp!= NULL){
        counter++;
        if(counter == val){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev= temp;
        temp=temp->next;
    }
    return head;
}
Node* deleteAtVal(Node* head, int val){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!= NULL){
        if(temp->data == val){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev= temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = { 1,4,7,2,9};
    Node* head = merge(arr);
////    head = deleteHead(head);
////      head = insertAtEnd(NULL, 340);
//       head = insertAtVal(head, 100, 1);
head = deleteAtVal(head,7);
    print(head);

    return 0;
}
