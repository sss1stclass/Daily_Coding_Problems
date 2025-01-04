#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        data = data1;
        next=next1;
    }
public:
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

Node* convertArrtoll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}
int checkVal(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        temp=temp->next;
        count++;
    }
    return  count;
}

int sumOfLastN_Nodes(Node* head, int n) {
    // Code here
    Node* temp = head;
    int  count=0;
    int ans = 0;
    while(temp){
        if(count>n){
            ans = ans+temp->data;
        }
        temp=temp->next;
        count++;
        cout<<temp->data<<" ";
    }
//    return ans;
}

int main (){
vector<int>arr= {2,5,4,6,1};
Node* y = new Node(arr[0]);
Node* head = convertArrtoll(arr);
//cout<<sumOfLastN_Nodes(head,3)<<endl;

//cout<<head->data<<endl;
//cout<<lengthLL(head)<<"length"<<endl;
//cout<<y<<endl;
Node* temp = head;
int ans=0;
int count =0;
//cout<<checkVal(head, 15)<<endl;
while(temp){
    cout<<temp->data<<" ";
    if(count>=3){
        ans= ans+temp->data;
        cout<<ans<<endl;
    }
    temp= temp->next;
    count++;
}
    return 0;
}
