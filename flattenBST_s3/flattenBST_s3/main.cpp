//
//  main.cpp
//  flattenBST_s3
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

void flatten(TreeNode *root) {
    if (!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        if (root->right){
            s.push(root->right);
        }
        if (root->left){
            s.push(root->left);
        }
        // here s.top() is the next node to traverse.
        // link the current node to the next node. (preorder traverse.)
        root->left = NULL;
        if (!s.empty()){
            root->right = s.top();
        }
    }        
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
