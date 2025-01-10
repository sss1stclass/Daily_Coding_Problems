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

Node* middleNodeWithTortoiseHareMethod(Node* head){
    Node* fast=head;
    Node* slow = head;
    while(fast!= nullptr && fast->next!= nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool hasCycle(Node *head) {
    if(head==NULL || head->next==NULL){
        return false;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
Node *detectCycleBF(Node *head) {
    if(head==NULL || head->next==NULL) return NULL;
    unordered_map<Node*, int> nodeMap;
    Node* temp = head;
    while(temp!=NULL){
        if(nodeMap.find(temp) != nodeMap.end()){
            return temp;
        }
        nodeMap[temp]=1;
        temp= temp->next;
    }
    return NULL;
}

Node* detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    if(head == NULL || head->next==NULL){
        return NULL;
    }
    while(fast!=NULL && fast->next!= nullptr){
        if(fast==slow){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }

    return NULL;
}
bool isPalindrome(Node* head) {
    Node* temp = head;
    vector<int>v;
    while(temp!= nullptr){
        v.push_back(temp->data);
        temp=temp->next;
    }
    int n = v.size();
    for(int i =0;i<=n/2;i++){
        if(v[i] != v[n-i-1]){
            return false;
        }
    }
    return true;
}

int main (){
    Node* head = new Node(1);
    Node* node2 = new Node(83,NULL, head);
    head->next=node2;
    Node* node3 = new Node(9,NULL, node2);
    node2->next = node3;
    Node* node4 = new Node(3,NULL, node3);
    node3->next=node4;
    Node* node5 = new Node(1,NULL, node4);
    node4->next = node5;
//    Node* newHead = detectCycle(head);
    cout<<isPalindrome(head);
//    print(newHead);
    return 0;

}