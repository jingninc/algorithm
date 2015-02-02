//
//  main.cpp
//  flattenBST_s2
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
    stack<TreeNode*> s;
    while(!s.empty() || root){
        if (root){
            s.push(root);
            root= root->left;
        } else{
            root = s.top();
            s.pop();
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            while(root->right){
                root = root->right;
            }
            root->right = tmp;
            root = root->right;
        }
    }	        
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
