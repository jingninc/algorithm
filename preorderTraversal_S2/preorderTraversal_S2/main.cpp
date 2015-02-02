//
//  main.cpp
//  preorderTraversal_S2
//
//  Created by JINGNING CAO on 1/7/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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


vector<int> preorderTraversal(TreeNode *root) {
    vector<int> v;
    if (!root) return v;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        v.push_back(root->val);
        if (root->right){
            s.push(root->right);
        }
        if (root->left){
            s.push(root->left);
        }
    }	
    return v;
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> right = new TreeNode(15);
    
    root -> left -> left = new TreeNode(4);
    root -> left -> left -> right = new TreeNode(7);
    root -> left -> left -> right -> left = new TreeNode(10);
    root -> left -> left -> right -> right = new TreeNode(11);
    
    root -> right = new TreeNode(3);
    root -> right  -> right= new TreeNode(6);
    
    vector<int> res = preorderTraversal(root);
    for (int elem : res){
        cout << elem << endl;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
