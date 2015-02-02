//
//  main.cpp
//  levelOrderTraversal
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > v;
    if (!root) return v;
    queue<TreeNode*> Q;
    TreeNode* const SPACE = new TreeNode(-1);
    
    Q.push(SPACE);
    Q.push(root);
    while(!Q.empty()){
        TreeNode* curr = Q.front();
        Q.pop();
        if (curr == SPACE){
            // handle the last SPACE.
            if (Q.empty()) break;
            Q.push(SPACE);
            vector<int> tmp;
            v.push_back(tmp);
        } else {
            v.back().push_back(curr->val);
            if (curr->left) Q.push(curr->left);
            if (curr->right) Q.push(curr->right);
        }
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
