#include<bits/stdc++.h>
using namespace std;

class Node {
public:

    int data;
    Node* next;

    Node(int data1, Node* next1){
        data= data1;
        next=next1;
    }
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

class implementStack{
public:
    Node* top;

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top=temp;
    }
    void pop(){
        Node* temp = top;
        top=top->next;
        delete(temp);
    }
    int outer(){
       return top->data;
    }
};

int main(){
    implementStack st;
    st.push(7);
    st.push(8);
    st.push(9);
    st.pop();
    cout<<st.outer()<<endl;
    st.push(12);
    st.push(89);
    st.pop();
    cout<<st.outer();


    return 0;
}
