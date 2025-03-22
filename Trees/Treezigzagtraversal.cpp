#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val1){
        val = val1;
        left=right= nullptr;
    }
    TreeNode(){
        val = 0;
        left=right= nullptr;
    }
};

void printInorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    printInorder(root->left);
    printInorder(root->right);
}

vector<vector<int>>printLevelOrder(TreeNode* root){
    vector<vector<int>>ans;
    queue<TreeNode*>q;
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL){
        return result;
    }
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;
    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);
        for(int i = 0; i < size; i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            int index = leftToRight ? i : (size - 1 - i);

            row[index] = node->val;
            if(node->left){
                nodesQueue.push(node->left);
            }
            if(node->right){
                nodesQueue.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    printInorder(root);
    cout<<endl;
    vector<vector<int>>ans = zigzagLevelOrder(root);
    for(auto i : ans){
        for(auto v : i){
            cout<<v<<" ";
        }cout<<endl;
    }
}