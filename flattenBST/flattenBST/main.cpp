//
//  main.cpp
//  flattenBST
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


void dfs(TreeNode* root){
    if (!root) return;
    dfs(root->left);
    dfs(root->right);
    
    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    TreeNode* curr = root;
    while(curr->right){
        curr= curr->right;
    }
    curr->right = tmp;
}


void flatten(TreeNode *root) {
    dfs(root);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
