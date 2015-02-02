//
//  main.cpp
//  bstIterator
//
//  Created by JINGNING CAO on 1/5/15.
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

class BSTIterator {
public:
stack<TreeNode*> S;
//TreeNode* curr;
BSTIterator(TreeNode *root) {
    TreeNode* curr = root;
    while(curr){
        S.push(curr);
        curr= curr->left;
    }
}

/** @return whether we have a next smallest number */
bool hasNext() {
    return (!S.empty());
}

/** @return the next smallest number */
int next() {
    TreeNode* curr = S.top();
    S.pop();
    int currVal = curr->val;
    curr = curr->right;
    while(curr){
        S.push(curr);
        curr = curr->left;
    }
    return currVal;
}
    
};

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(-9);
    root -> left =new TreeNode(5);
    root -> left ->left =new TreeNode(-9);
    root -> left ->right =new TreeNode(-1);
    
    root -> right =new TreeNode(3);
    root -> right -> left = new TreeNode(2);
    root -> right -> left->right = new TreeNode(-10);
    root -> right -> right = new TreeNode(-8);
    
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << " ,";
    
    std::cout << "Hello, World!\n";
    return 0;
}
