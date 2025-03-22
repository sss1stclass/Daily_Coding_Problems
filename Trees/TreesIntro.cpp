#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data= data1;
        left=right=NULL;
    }
};

void printPreOrder(Node* node){
    if(node== nullptr){
        return ;
    }
    cout<<node->data<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(Node* node){
    if(node== nullptr){
        return ;
    }
    printInOrder(node->left);
    cout<<node->data<<" ";
    printInOrder(node->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right= new Node(7);
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);


    return 0;
}


  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    void preOrder(TreeNode* root, vector<int>&ans){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root, ans);
        return ans;

    }
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*>q;
    if(root == NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i =0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

