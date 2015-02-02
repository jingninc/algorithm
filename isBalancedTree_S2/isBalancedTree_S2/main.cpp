//
//  main.cpp
//  isBalancedTree_S2
//
//  Created by JINGNING CAO on 1/4/15.
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

int height(TreeNode* root){
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right) );
}

bool isBalanced(TreeNode *root) {
    if (!root) return true;
    bool lc = isBalanced(root->left);
    bool rc = isBalanced(root->right);
    return lc && rc && (height(root->left) - height(root->right) <= 1 &&
                        height(root->left) - height(root->right) >= -1 );
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    root -> left =new TreeNode(5);
    root ->left -> left = new TreeNode(7);
    cout << isBalanced(root) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}