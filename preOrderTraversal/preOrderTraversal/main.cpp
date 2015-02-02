//
//  main.cpp
//  preOrderTraversal
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
    
}


vector<int> preorderTraversal(TreeNode *root) {
    vector<int> v;
    stack<TreeNode*> s;
    while(!s.empty() || root){
        if (root){
            v.push_back(root->val);
            s.push(root);
            root = root->left;
        }else {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }    
    return v;
    
}
int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(3);
    root ->left =new TreeNode(9);
    root ->right =new TreeNode(20);
    root ->right ->left=new TreeNode(15);
    root ->right ->right =new TreeNode(7);
    vector<int> res = preorderTraversal(root);

        for(int elem : res){
            cout << elem << ",";
        }


    std::cout << "Hello, World!\n";
    return 0;
}
