//
//  main.cpp
//  levelOrderTraversal_s2
//
//  Created by JINGNING CAO on 1/4/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > v;
    if (!root) return v;
    queue<TreeNode*> Q, sub;
    
    Q.push(root);
    while(!Q.empty()){
        vector<int> temp;
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            temp.push_back(curr->val);
            
            if (curr->left) sub.push(curr->left);
            if (curr->right) sub.push(curr->right);
        }
        v.push_back(temp);
        swap(Q, sub);
    }
    return v;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(-9);
    root -> left =new TreeNode(9);
    root -> left ->left =new TreeNode(-9);
    root -> left ->right =new TreeNode(-1);
    
    root -> right =new TreeNode(3);
    root -> right -> left = new TreeNode(2);
    root -> right -> left->right = new TreeNode(-10);
    root -> right -> right = new TreeNode(-8);
    
    vector<vector<int> > v = levelOrder(root);
    for (auto e: v){
        cout << "[";
        for(auto elem : e){
            cout << elem << ",";
        }
        cout << "]" << endl;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
