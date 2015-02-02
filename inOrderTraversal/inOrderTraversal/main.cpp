//
//  main.cpp
//  inOrderTraversal
//
//  Created by JINGNING CAO on 1/13/15.
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


vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode*> s;
    vector<int> v;
    while(!s.empty() || root){
        if (root){
            // it means only if the nodes passing by is not NULL, it will
            // be stored in the stack once.
            s.push(root);
            // determine the proceeding direction
            root= root->left;
        }else {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            // determine the proceeding direction
            root = root->right;
        }
    }
    return v;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
